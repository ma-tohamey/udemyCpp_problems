#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct ask_app {
  string signed_user_id, signed_user_name;
  bool signed_user = false;
  int users_number;
  int nquestions, nthreads;
  ask_app() {
    ifstream fin_questions("questions.txt");
    string line;
    getline(fin_questions, line);

    while (getline(fin_questions, line)) {
      istringstream iss(line);
      iss >> nquestions >> nthreads;
    }
    fin_questions.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void login() {
    string user_name, user_password, line;
    cout << "Enter user name & password: ";
    cin >> user_name >> user_password;
    ifstream fin("users.txt");
    bool valid_user = false;
    // to skip first line which is titles
    getline(fin, line);
    while (getline(fin, line)) {
      string cnt_user_id, cnt_user_name, cnt_password;
      istringstream iss(line);
      iss >> cnt_user_id >> cnt_user_name >> cnt_password;
      valid_user =
          (cnt_user_name == user_name && cnt_password == user_password);

      if (valid_user) {
        signed_user_name = cnt_user_name;
        signed_user_id = cnt_user_id;
        signed_user = true;

        fin.close();

        break;
      }
    }
    if (!valid_user) {
      cout << "Incorrect username or password." << endl;
      fin.close();
      return;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  string get_check_email_username(string label) {
    string user_input;
    bool is_uniqe = true, first_time = true;
    ifstream fin("users.txt");

    string line, cnt_user_id, cnt_user_name, cnt_user_password, cnt_name,
        cnt_email;

    while (!is_uniqe || first_time) {
      is_uniqe = true, first_time = false;
      cout << "\nEnter "
           << (label == "email" ? "email: " : "user name. (No spaces): ");
      cin >> user_input;

      // to skip first line which contain titles
      getline(fin, line);

      while (getline(fin, line)) {
        istringstream iss(line);
        iss >> cnt_user_id >> cnt_user_name >> cnt_user_password >> cnt_name >>
            cnt_email;

        if (label == "email" && user_input == cnt_email) {
          cout << "This email is already registered. Try another one!" << endl;
          is_uniqe = false;
          break;
        }

        if (label == "user_name" && user_input == cnt_user_name) {
          cout << "This user_name is already taken." << endl;
          is_uniqe = false;
          break;
        }
      }
    }
    users_number = stoi(cnt_user_id);
    fin.close();
    return user_input;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void sing_up() {
    string user_name, password, name, email, AQ_status;

    email = get_check_email_username("email");

    cout << "Enter password: ";
    cin >> password;
    cout << "Enter your name: ";
    cin >> name;

    user_name = get_check_email_username("user_name");

    cout << "Allow anonymous questions? (0 or 1): ";
    cin >> AQ_status;

    ofstream fout("users.txt", ios::app);

    fout << users_number + 1 << ' ' << user_name << ' ' << password << ' '
         << name << ' ' << email << ' ' << AQ_status;

    signed_user_name = user_name;
    signed_user_id = users_number + 1;
    signed_user = true;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_question_answer(string question_id, string thread_id) {
    ifstream fin_answers("answers.txt");
    string line, answer_id, answer_thread_id, answer;
    getline(fin_answers, line);

    while (getline(fin_answers, line)) {
      istringstream iss(line);
      iss >> answer_id >> answer_thread_id;
      if (answer_id == question_id && answer_thread_id == thread_id) {
        // cout << (thread_id == "-1" ? "" : "\tThread: ");
        cout << "\tAnswer: ";
        while (iss >> answer)
          cout << answer << ' ';
        cout << endl;
      }
    }

    fin_answers.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_question(int q_sahpe, string question_id = "0") {
    ifstream fin_questions("questions.txt");

    // to skil first line in both questions.txt and threads.txt which is
    // titles
    string line;
    getline(fin_questions, line);

    while (getline(fin_questions, line)) {
      istringstream iss(line);
      string p_question_id, thread_id, to_id, from_id, question;
      bool is_answered, AQ_status;
      iss >> p_question_id >> thread_id >> to_id >> from_id >> AQ_status >>
          is_answered;

      // 1 ==> mean print question in shape of ( to me )
      if (q_sahpe == 1 && signed_user_id == to_id) {
        // not a thread question
        if (thread_id == "-1") {
          cout << "\nQuestion Id (" << p_question_id << ") ";
        } else {
          // is a thread question
          cout << "\n\tThread: Question Id(" << thread_id << ") ";
        }
        if (!AQ_status)
          cout << "from user id(" << from_id << ") ";
        cout << "\t\tQuestion: ";

        while (iss >> question)
          cout << question << ' ';
        cout << endl;

        if (is_answered)
          print_question_answer(p_question_id, thread_id);
        else
          cout << "\tNot Answered YET" << endl;
      }

      // 2 ==> mean print quesiton from me
      else if (q_sahpe == 2 && signed_user_id == from_id) {
        // not a thread question
        if (thread_id == "-1") {
          cout << "\nQuestion Id (" << p_question_id << ") "
               << (AQ_status ? "" : "!AQ ") << "to user id (" << to_id
               << ")\t\tQuestion: ";
        } else {
          // is a thread question
          cout << "\nThread Parent Question Id(" << p_question_id
               << ") Question Id(" << thread_id << ") "
               << (AQ_status ? "" : "!AQ ") << "to user id(" << to_id
               << ")\t\tThread Question: ";
        }

        while (iss >> question)
          cout << question << ' ';
        cout << endl;
        print_question_answer(p_question_id, thread_id);
      }

      // 3 ==> mean print a specific question
      else if (q_sahpe == 3 && to_id == signed_user_id &&
               (question_id == p_question_id || question_id == thread_id)) {
        cout << "\nQuestion Id (" << question_id << ") ";
        if (!AQ_status)
          cout << "from user id(" << from_id << ") ";

        cout << "\tQuestion: ";
        while (iss >> question)
          cout << question << ' ';
        cout << endl;
        if (is_answered) {
          print_question_answer(p_question_id, thread_id);
          cout << "\n\nWarning: Already answered. Answer will be updated"
               << endl;
        } else
          cout << "\tNot Answered YET" << endl;
      }

      // 4 ==> mean print all answered quesions (feeds)
      else if (q_sahpe == 4 && is_answered) {

        if (thread_id == "-1") {
          cout << "\nQuestion Id(" << p_question_id << ") ";

        } else {
          // is a thread question
          cout << "\nThread Parent Question ID(" << p_question_id
               << ") Question Id(" << thread_id << ") ";
        }

        if (!AQ_status)
          cout << "from user id(" << from_id << ") ";

        cout << "To user id(" << to_id << ")";
        cout << "\tQuestion: ";

        while (iss >> question)
          cout << question << ' ';
        cout << endl;

        print_question_answer(p_question_id, thread_id);
      }
    }
    fin_questions.close();
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_questions_to_me() { print_question(1); }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void print_questions_from_me() { print_question(2); }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void answer_question() {
    string question_id;
    cout << "Enter Question id or -1 to cancel: ";
    cin >> question_id;
    if (question_id == "-1") {
      return;
    }
    ifstream fin_questions("questions.txt");

    string line;
    getline(fin_questions, line);

    while (getline(fin_questions, line)) {
      istringstream iss(line);
      string p_question_id, thread_id, to_id, from_id, question;
      bool is_answered, AQ_status;
      iss >> p_question_id >> thread_id >> to_id >> from_id >> AQ_status >>
          is_answered;
    }

    string new_answer;
    cout << "Enter answer: ";
    cin >> new_answer;

    ifstream fin_answers("answers.txt");
    ofstream out_answers("tmp.txt");

    string answer_id, thread_id, answer;
    getline(fin_answers, line);

    while (getline(fin_answers, line)) {
      istringstream iss(line);
      iss >> answer_id >> thread_id;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void delete_question() {
    string question_id;
    cout << "Enter Question id or -1 to cancel: ";
    cin >> question_id;

    if (question_id == "-1")
      return;

    ifstream questions_handler("questions.txt");
    ofstream qtmp("tmp.txt", ios::out);

    string line;
    bool is_deleted = false;

    while (getline(questions_handler, line)) {
      // questions line scanner
      istringstream iss(line);
      string p_question_id, thread_id, to_id, from_id, question;
      bool is_answered, AQ_status;
      iss >> p_question_id >> thread_id >> to_id >> from_id >> AQ_status >>
          is_answered;

      // just delete my questions
      if (signed_user_id == from_id &&
          (question_id == p_question_id || question_id == thread_id)) {
        is_deleted = true;
        continue;
      }
      qtmp << line << endl;
    }
    questions_handler.close();
    qtmp.close();
    remove("questions.txt");
    rename("tmp.txt", "questions.txt");

    ifstream answers_handler("answers.txt");
    ofstream atmp("tmp.txt", ios::out);
    while (getline(answers_handler, line)) {
      // answers line scanner
      istringstream iss(line);
      string answer_id, thread_id;
      iss >> answer_id >> thread_id;

      // just delete my questions
      if (is_deleted &&
          (question_id != answer_id && question_id != thread_id)) {
        atmp << line << endl;
      }
    }

    answers_handler.close();
    atmp.close();
    remove("answers.txt");
    rename("tmp.txt", "answers.txt");

    if (is_deleted)
      cout << "\nQuestion has been Deleted Successfully" << endl;
    else
      cout << "ERROR: Question not found. please enter a valid question ID!"
           << endl;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void ask_question() {
    string reciver_id;
    cout << "Enter User id or -1 to cancel: ";
    cin >> reciver_id;

    if (reciver_id == "-1")
      return;

    bool is_user = false;
    ifstream fin("users.txt");
    string line, cnt_user_id, cnt_user_name, cnt_password, cnt_name, cnt_email,
        sender_AQ_status;
    getline(fin, line);
    while (getline(fin, line)) {
      istringstream iss(line);
      iss >> cnt_user_id >> cnt_user_name >> cnt_password >> cnt_name >>
          cnt_email >> sender_AQ_status;

      if (cnt_user_id == reciver_id) {
        is_user = true;
        fin.close();
        break;
      }
    }
    if (!is_user) {
      cout << "\nNot a valid user id!" << endl;
      fin.close();
    }

    string question_status;
    if (sender_AQ_status == "0") {
      cout << "Note: Anonymous questions are not allowed for this user" << endl;
    } else {
      cout << "Note: Anonymous questions are allowed for this user." << endl;
      cout << "Send as Anonymous question (0 or 1): ";
      cin >> question_status;
      if (question_status != "0" || question_status != "1")
        cout << "Invalid question status. please enter (0 or 1)" << endl;
      return;
    }

    string p_thread_id;
    cout << "For thread question: Enter Question id or -1 for new question: ";
    cin >> p_thread_id;

    // if it is a thread question
    fstream fin_questions("questions.txt", ios::app);
    if (p_thread_id != "-1") {
      bool is_question = false;
      string line, cnt_question_id;
      getline(fin, line);
      while (getline(fin, line)) {
        istringstream iss(line);
        iss >> cnt_question_id;

        if (cnt_question_id == p_thread_id) {
          is_question = true;
          break;
        }
      }

      if (!is_question) {
        cout << "You have entered an invalid parent question id!" << endl;
        return;
      }
    }

    string sended_question;
    cout << "Enter question text: ";
    cin.ignore();
    getline(cin, sended_question);

    // make sure that is not duplicate question;
    ifstream read_questions("questions.txt");
    getline(read_questions, line);

    while (getline(read_questions, line)) {
      istringstream iss(line);
      string p_question_id, thread_id, to_id, from_id, question, full_question;
      bool is_answered, AQ_status;
      iss >> p_question_id >> thread_id >> to_id >> from_id >> AQ_status >>
          is_answered;
      while (iss >> question)
        full_question += question + ' ';
      full_question.pop_back();

      if (signed_user_id == from_id && to_id == reciver_id &&
          full_question == sended_question &&
          sender_AQ_status == question_status) {
        cout << "\nThis is a duplicate question." << endl;
        return;
      }
    }

    ostringstream oss;

    // if it is a thread question
    // p_thread_id is accutully a question id
    if (p_thread_id != "-1")
      oss << p_thread_id << ' ' << nthreads + 1 << ' ' << reciver_id << ' '
          << signed_user_id << ' ' << question_status << ' ' << 0 << ' '
          << sended_question;
    else
      oss << nquestions + 1 << ' ' << -1 << ' ' << reciver_id << ' '
          << signed_user_id << ' ' << question_status << ' ' << 0 << ' '
          << sended_question;

    fin_questions << oss.str() << endl;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void list_system_users() {
    ifstream fin("users.txt");
    string cnt_user_id, cnt_user_name, cnt_password, cnt_name;

    // to skip first line which contain titles
    string line;
    getline(fin, line);

    while (getline(fin, line)) {
      istringstream iss(line);
      iss >> cnt_user_id >> cnt_user_name >> cnt_password >> cnt_name;
      cout << "ID: " << cnt_user_id << "\t\tName: " << cnt_name
           << (cnt_user_id == signed_user_id ? "\t\tYou" : "") << endl;
    }
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void feed() { print_question(4); }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  void logout() {
    signed_user_id = "", signed_user_name = "";
    signed_user = false;
  }

  ///////////////////////////////////////////////
  ///
  ///////////////////////////////////////////////

  string menu() {
    string user_choice;
    cout << "\nMenu:" << endl;
    if (signed_user) {
      // if (first_time) {
      //   cout <<
      //   "*********************************************************"
      //        << endl;
      //   cout << "\t\tWelcome " << cnt_user_name << endl;
      //   cout <<
      //   "*********************************************************"
      //        << endl;
      // }
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

      if (signed_user) {
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
