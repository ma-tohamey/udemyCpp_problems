#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int str_to_int(string user_input) {
  if (stoi(user_input))
    return stoi(user_input);
  cout << "Enter valid number. please!" << endl;
  return -1;
}

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct user {
  string user_name, password, name, email;
  bool AQ_status;

  user() {}

  void print_user(int user_id) {
    cout << "ID: " << user_id << "\t\t\tName: " << name << endl;
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct question {
  int has_parent_id, to_id, from_id;
  bool AQ_status;
  queue<string> full_question;

  question() {}

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_to_me(int question_id) {
    cout << "Question Id(" << question_id << ") ";
    // if it isn't anonymous quesiton print from_id
    if (!AQ_status)
      cout << "from user id(" << from_id << ")";

    cout << "\t\tQuestion: ";
    while (!full_question.empty()) {
      cout << full_question.front() << ' ';
      full_question.pop();
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_from_me(int question_id) {
    cout << "Question Id(" << question_id << ") ";
    // if it isn't anonymous quesiton print !AQ
    if (!AQ_status)
      cout << "!AQ ";

    cout << "to user id(" << to_id << ")";

    cout << "\t\tQuestion: ";
    while (!full_question.empty()) {
      cout << full_question.front() << ' ';
      full_question.pop();
    }
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct answer {
  queue<string> full_answer;
  answer() {}

  void print() {
    cout << "\t\tAnswer: ";
    while (!full_answer.empty()) {
      cout << full_answer.front() << ' ';
      full_answer.pop();
    }
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct answers_manager {
  // set<int> answer_ids;
  vector<map<int, answer>> answers;

  answers_manager() {}

  void load_answer() {
    answers.clear();
    // answer_ids.clear();

    ifstream fin("answers.txt");
    string line, answer_text;
    int answer_id;
    getline(fin, line);

    while (getline(fin, line)) {
      istringstream iss(line);
      iss >> answer_id;
      while (iss >> answer_text)
        answers[answer_id].full_answer.push(answer_text);
      // answer_ids.insert(answer_id);
    }
    fin.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  bool is_answered(int question_id) {
    if (answers.count(question_id))
      return true;
    return false;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void answer_question(int question_id, string answer_text) {
    // adding new answer to file
    ofstream fout("answers.txt", ios::app);
    ostringstream oss;
    oss << question_id << ' ' << answer_text;
    fout << oss.str();
    fout.close();

    // adding new answer to the memeory
    string sub_answer;
    istringstream iss(answer_text);
    while (iss >> sub_answer)
      answers[question_id].full_answer.push(sub_answer);
    answer_ids.insert(question_id);
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void update_answer(int question_id, string new_answer) {
    ifstream answer_file("answers.txt");
    ofstream tmp_file("tmp.txt");

    // update the answer in answers file
    string line;
    int answer_id;
    while (getline(answer_file, line)) {
      istringstream iss(line);
      iss >> answer_id;
      if (answer_id == question_id) {
        ostringstream oss;
        oss << question_id << ' ' << new_answer;
        tmp_file << oss.str() << endl;
        continue;
      }
      tmp_file << line << endl;
    }
    answer_file.close();
    tmp_file.close();
    remove("answers.txt");
    rename("tmp.txt", "answers.txt");
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void delete_answer(int answer_id) {
    ifstream answers_file("answers.txt");
    ofstream tmp_file("tmp.txt");

    string line;
    int cnt_answer_id;

    while (getline(answers_file, line)) {
      istringstream iss(line);
      iss >> cnt_answer_id;

      if (cnt_answer_id == answer_id)
        continue;

      tmp_file << line << endl;
    }
    answers_file.close();
    tmp_file.close();
    remove("answers.txt");
    rename("tmp.txt", "answers.txt");
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct questions_manager {
  set<int> parent_que_ids;
  map<int, set<int>> thread_ids;

  set<int> from_me_ids;
  map<int, question> questions_mp;

  int questions_number;
  questions_manager() { questions_number = 0; }

  void load_questions(int user_id) {
    parent_que_ids.clear();
    thread_ids.clear();
    from_me_ids.clear();
    questions_mp.clear();

    questions_number = 0;
    int question_id;

    ifstream fin("questions.txt");
    string line, question_text;
    getline(fin, line);

    while (getline(fin, line)) {
      istringstream iss(line);
      iss >> question_id >> questions_mp[question_id].has_parent_id >>
          questions_mp[question_id].to_id >>
          questions_mp[question_id].from_id >>
          questions_mp[question_id].AQ_status;

      // to extract quesiton text then just pop last char
      // in question_text which is space
      while (iss >> question_text)
        questions_mp[question_id].full_question.push(question_text);

      if (questions_mp[question_id].to_id == user_id) {
        map<int, set<int>> parent_mp;

        // if it doesn't have parent id so it is a parent question
        if (!questions_mp[question_id].has_parent_id) {
          parent_que_ids.insert(question_id);
        }
        // if it has parent id insert it in its parent map
        else
          thread_ids[questions_mp[question_id].has_parent_id].insert(
              question_id);
      }

      if (questions_mp[question_id].from_id == user_id)
        from_me_ids.insert(question_id);

      ++questions_number;
    }
    fin.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void ask_question(question new_question) {
    // appending the new question to questions file
    ofstream fout("questions.txt", ios::app);
    ostringstream oss;
    int new_questions_id = ++questions_number;
    oss << new_questions_id << ' ' << new_question.has_parent_id << ' '
        << new_question.to_id << ' ' << new_question.from_id << ' '
        << new_question.AQ_status << ' ';

    while (!new_question.full_question.empty()) {
      oss << new_question.full_question.front() << ' ';
      new_question.full_question.pop();
    }
    fout << oss.str();
    fout.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void delete_question(int question_id) {
    ifstream question_file("questions.txt");
    ofstream tmp_file("tmp.txt");

    int cnt_question_id, cnt_parent_id;
    string line;

    while (getline(question_file, line)) {
      istringstream iss(line);
      iss >> cnt_question_id >> cnt_parent_id;

      if (cnt_question_id == question_id || cnt_parent_id == question_id)
        continue;

      tmp_file << line << endl;
    }
    question_file.close();
    tmp_file.close();
    remove("questions.txt");
    rename("tmp.txt", "questions.txt");
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct users_manager {
  user cnt_user;
  vector<int> user_ids;
  map<int, user> users;
  int users_number;

  users_manager() { users_number = 0; }

  void load_users() {
    user_ids.clear();
    users.clear();
    users_number = 0;
    int user_id;

    ifstream fin("users.txt");
    string line;
    getline(fin, line);
    while (getline(fin, line)) {
      istringstream iss(line);

      iss >> user_id >> users[user_id].user_name >> users[user_id].password >>
          users[user_id].name >> users[user_id].email >>
          users[user_id].AQ_status;

      user_ids.push_back(user_id);
      ++users_number;
    }
    fin.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void list_system_users() {
    for (int user_id : user_ids)
      users[user_id].print_user(user_id);
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  int is_registered(string user_name, string password) {
    for (int user_id : user_ids) {
      user cnt_user = users[user_id];
      if (cnt_user.user_name == user_name && cnt_user.password == password) {
        return user_id;
      }
    }
    return 0;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  bool is_valid_email(string user_email) {
    for (int user_id : user_ids) {
      if (users[user_id].email == user_email) {
        cout << "\nThis email is already registered. Try another one!" << endl;
        return false;
      }
    }
    return true;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  bool is_valid_user_name(string user_name) {
    for (int user_id : user_ids) {
      if (users[user_id].user_name == user_name) {
        cout << "\nThis user name is already taken!" << endl;
        return false;
      }
    }
    return true;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void add_new_user(user new_user) {
    ofstream fout("users.txt", ios::app);
    int new_user_id = users_number + 1;
    ostringstream oss;
    oss << new_user_id << ' ' << new_user.user_name << ' ' << new_user.password
        << ' ' << new_user.name << ' ' << new_user.email << ' '
        << new_user.AQ_status << endl;
    fout << oss.str();
    user_ids.push_back(new_user_id);
    fout.close();
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

struct ask_app {
  users_manager u_manager;
  questions_manager ques_man;
  answers_manager ans_man;

  user signed_user;
  int signed_user_id;
  bool is_signed_user = false;

  ask_app() {}

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void login() {
    string user_name, password;
    cout << "Enter user name & password: ";
    cin >> user_name >> password;

    u_manager.load_users();
    int user_id = u_manager.is_registered(user_name, password);

    if (user_id) {
      is_signed_user = true;
      signed_user_id = user_id;
      signed_user = u_manager.users[user_id];

      // load users, questions, answers
      u_manager.load_users();
      ques_man.load_questions(signed_user_id);
      ans_man.load_answer();
    } else {
      cout << "Incorrect user name or password." << endl;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void sing_up() {
    user new_user;

    // do while but without do while;
    cout << "Enter email: ";
    cin >> new_user.email;
    while (!u_manager.is_valid_email(new_user.email)) {
      cout << "Enter email: ";
      cin >> new_user.email;
    }

    cout << "Enter password: ";
    cin >> new_user.password;

    cout << "Enter your user name. (No spaces): ";
    cin >> new_user.user_name;
    while (!u_manager.is_valid_user_name(new_user.user_name)) {
      cout << "Enter your user name. (No spaces): ";
      cin >> new_user.user_name;
    }

    cout << "Enter your name: ";
    cin >> new_user.name;

    cout << "Allow anonymous questions? (0 or 1): ";
    cin >> new_user.AQ_status;

    u_manager.add_new_user(new_user);

    signed_user = new_user;
    signed_user_id = u_manager.user_ids.back();
    signed_user_id = is_signed_user = true;

    // load users, questions, answers
    u_manager.load_users();
    ques_man.load_questions(signed_user_id);
    ans_man.load_answer();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_questions_to_me() {
    ques_man.load_questions(signed_user_id);
    ans_man.load_answer();

    for (int parent_que_id : ques_man.parent_que_ids) {
      // to print question
      cout << endl;
      ques_man.questions_mp[parent_que_id].print_to_me(parent_que_id);
      cout << endl;

      // if it's answered print the answer and threads if it exists
      if (ans_man.is_answered(parent_que_id)) {
        ans_man.answers[parent_que_id].print();
        cout << endl;

        // print threads
        for (int thread_id : ques_man.thread_ids[parent_que_id]) {
          cout << endl;
          cout << "\t\tThread: ";
          ques_man.questions_mp[thread_id].print_to_me(thread_id);
          cout << endl;

          if (ans_man.is_answered(thread_id)) {
            cout << "\t\tThread: ";
            ans_man.answers[thread_id].print();
            cout << endl;
          }
        }
      }
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_questions_from_me() {
    ques_man.load_questions(signed_user_id);
    ans_man.load_answer();

    for (int ques_id : ques_man.from_me_ids) {
      ques_man.questions_mp[ques_id].print_from_me(ques_id);
      if (ans_man.is_answered(ques_id))
        ans_man.answers[ques_id].print();
      else
        cout << "\t\tNot Answered YET" << endl;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void answer_question() {
    ques_man.load_questions(signed_user_id);
    ans_man.load_answer();

    int question_id;
    cout << "Enter Question id or -1 to cancel: ";
    cin >> question_id;

    if (question_id == -1)
      return;

    bool is_qusetion = ques_man.questions_mp.count(question_id);
    bool to_me_question =
        ques_man.questions_mp[question_id].to_id == signed_user_id;

    if (is_qusetion && to_me_question) {
      ques_man.questions_mp[question_id].print_to_me(question_id);

      if (ans_man.is_answered(question_id)) {
        ans_man.answers[question_id].print();
        cout << "\n\nWarning: Already answered. Answer will be updated" << endl;
      }

      string answer;
      cout << "\nEnter answer: ";
      cin.ignore();
      getline(cin, answer);

      if (ans_man.is_answered(question_id))
        ans_man.update_answer(question_id, answer);
      else
        ans_man.answer_question(question_id, answer);

    } else {
      cout << "\nThis isn't a valid question id. Try another one!\n";
      return;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void delete_question() {
    int question_id;
    cout << "Enter Question id or -1 to cancel: ";
    cin >> question_id;

    if (question_id == -1)
      return;

    bool is_question_from_me = ques_man.from_me_ids.count(question_id);
    bool is_parent_question = ques_man.parent_que_ids.count(question_id);
    bool is_thread_question = false;
    for (int parent_que_id : ques_man.parent_que_ids)
      if (ques_man.thread_ids[parent_que_id].count(question_id)) {
        is_thread_question = true;
        break;
      }

    if (is_question_from_me || is_parent_question || is_thread_question) {
      ques_man.delete_question(question_id);
      ans_man.delete_answer(question_id);
    } else
      cout << "\nThis isn't a valid question id. Try another one" << endl;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void ask_question() {
    int reciver_id, question_id;
    question new_question;
    string question_text, sub_question;

    cout << "Enter User id or -1 to cancel: ";
    cin >> reciver_id;

    if (reciver_id == -1)
      return;

    if (u_manager.users.count(reciver_id)) {
      // check if that user allow for anonymous questions or not
      if (u_manager.users[reciver_id].AQ_status) {
        int question_AQ;
        cout << "Note: Anonymous questions are allowed for this user." << endl;
        cout << "Ask as anonymous (0 or 1): ";
        cin >> question_AQ;

        if (question_AQ != 0 && question_AQ != 1) {
          cout << "You Entered Invalid input." << endl;
          return;
        }
        new_question.AQ_status = question_AQ;

      } else {
        cout << "Note: Anonymous questions are not allowed for this user."
             << endl;
        new_question.AQ_status = 0;
      }

      cout << "For thread question: Enter Question id or 0 for new question: ";
      cin >> question_id;
      if (question_id != 0 && !ques_man.questions_mp.count(question_id)) {
        cout << "Unrecorded question id please make sure of the question id."
             << endl;
        return;
      }
      new_question.has_parent_id = question_id;

      cout << "Enter question test: ";
      cin.ignore();
      getline(cin, question_text);

      istringstream iss(question_text);
      while (iss >> sub_question)
        new_question.full_question.push(sub_question);

      new_question.from_id = signed_user_id;
      new_question.to_id = reciver_id;
      ques_man.ask_question(new_question);

    } else {
      cout << "This isn't a registered user id" << endl;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void list_system_users() { u_manager.list_system_users(); }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void feed() {
    ques_man.load_questions(signed_user_id);
    ans_man.load_answer();

    for (int answered_ques_id : ans_man.answer_ids) {
      cout << endl;
      if (ques_man.questions_mp[answered_ques_id].has_parent_id)
        cout << "Thread Parent ";

      ques_man.questions_mp[answered_ques_id].print_to_me(answered_ques_id);
      cout << endl;

      ans_man.answers[answered_ques_id].print();
      cout << endl;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void logout() { is_signed_user = false; }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  string menu() {
    string user_choice;
    cout << "\nMenu:" << endl;
    if (is_signed_user) {
      cout << "\t1: Print Questions To Me" << endl;
      cout << "\t2: Print Questions From Me" << endl;
      cout << "\t3: Answer Question" << endl;
      cout << "\t4: Delete Question" << endl;
      cout << "\t5: Ask Question" << endl;
      cout << "\t6: List System Users" << endl;
      cout << "\t7: Feed" << endl;
      cout << "\t8: Logout" << endl << endl;
      cout << "Enter number in range 1 - 8: ";
      cin >> user_choice;
      return user_choice;
    } else {
      cout << "\t1: Login" << endl;
      cout << "\t2: Sign Up" << endl;
      cout << "Enter number in range 1 - 2: ";
      cin >> user_choice;
      return user_choice;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void run() {
    while (true) {
      string user_choice = menu();
      string error_mes = "\nERROR: Invalid number...Try again\n";

      if (is_signed_user) {
        if (user_choice == "1")
          print_questions_to_me();
        else if (user_choice == "2")
          print_questions_from_me();
        else if (user_choice == "3")
          answer_question();
        else if (user_choice == "4")
          delete_question();
        else if (user_choice == "5")
          ask_question();
        else if (user_choice == "6")
          list_system_users();
        else if (user_choice == "7")
          feed();
        else if (user_choice == "8")
          logout();
        else
          cout << error_mes;

      } else {
        if (user_choice == "1")
          login();
        else if (user_choice == "2")
          sing_up();
        else
          cout << error_mes;
      }
    }
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

int main(int argc, char *argv[]) {
  ask_app ask;
  ask.run();
  return 0;
}
