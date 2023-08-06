#include <assert.h>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// i am not interesting in this project anymore i found it useless to end this
// project i think i got the idead behind it and it's really hard to work on a
// previous project and you know everything should be done without getting any
// more usefull ideas from the project so to stop wasting my time "because i'm
// in the middle of my military" i wont end it and go to the next project to
// challange my self
//
// not finished

// Briefly there's no more challange in this project to end it so i am out

void ReadFile(const std::string &path, std::vector<std::string> &lines) {

  // opend just for reading
  std::ifstream fin(path.c_str());
  // assert(lines.size() == 0);
  if (fin.fail()) {
    std::cout << "Error: Cann't open the file\n\n";
    lines.clear();
    return;
  }

  lines.clear();
  std::string line;
  std::getline(fin, line);
  while (std::getline(fin, line)) {
    if (line.size() == 0)
      continue;
    lines.push_back(line);
  }
  fin.close();
}

void WriteFile(const std::string &path, const std::vector<std::string> &lines,
               bool append = true) {
  auto status = std::ios::in | std::ios::out | std::ios::app;

  if (!append)
    status = std::ios::in | std::ios::out | std::ios::trunc;

  std::ofstream out(path.c_str(), status);
  if (out.fail()) {
    std::cout << "Error: Can't open the file\n\n";
    return;
  }
  for (const auto &line : lines) {
    out << line;
  }
  out.close();
}

std::vector<std::string> SplitLine(const std::string &line,
                                   const std::string &delemiter = ",") {

  std::vector<std::string> CleanData;
  std::string s = line;
  int pos = 0;
  std::string SubStr;
  while ((pos = (int)s.find(delemiter)) != -1) {
    SubStr = s.substr(0, pos);
    CleanData.push_back(SubStr);
    s.erase(0, pos + delemiter.length());
  }

  CleanData.push_back(s);

  return CleanData;
}

int ToInt(const std::string &str) {
  int number;

  std::istringstream iss(str);
  iss >> number;

  return number;
}

class User {
private:
  int UserId;
  std::string UserName;
  std::string Password;
  std::string Name;
  std::string Email;
  int AQStatus;

public:
  User() : UserId(-1), AQStatus(-1) {}

  User(const std::string &line) {
    std::vector<std::string> UserData = SplitLine(line);
    assert(UserData.size() == 6);
    UserId = ToInt(UserData[0]);
    UserName = UserData[1];
    Password = UserData[2];
    Name = UserData[3];
    Email = UserData[4];
    AQStatus = ToInt(UserData[5]);
  }

  // Getters functions
  const int GetId() const { return UserId; }
  const std::string GetUserName() const { return UserName; }
  const std::string GetPassword() const { return Password; }
  const std::string GetName() const { return Name; }
  const std::string GetEmail() const { return Email; }
  const int GetAQStatus() const { return AQStatus; }

  // setters functions
  void SetUserId(const int &user_id) { this->UserId = user_id; }
  void SetUserName(const std::string &user_name) { this->UserName = user_name; }
  void SetPassword(const std::string &password) { this->Password = password; }
  void SetName(const std::string &name) { this->Name = name; }
  void SetEmail(const std::string &email) { this->Email = email; }
  void SetAQStatus(const int AQ_status) { this->AQStatus = AQ_status; }

  std::string ToStr() {
    std::ostringstream oss;
    oss << UserId << ',' << UserName << ',' << Password << ',' << Name << ','
        << Email << ',' << AQStatus << '\n';
    return oss.str();
  }

  void AddNewUser(const std::string &UserName, int &UserId) {
    std::string str;

    SetUserName(UserName);
    SetUserId(UserId);

    std::cout << "Enter password: ";
    std::cin >> str;
    SetPassword(str);

    std::cout << "Enter name: ";
    std::cin >> str;
    SetName(str);

    std::cout << "Enter email: ";
    std::cin >> str;
    SetEmail(str);

    std::cout << "Allow anonymous questions? (0 or 1): ";
    std::cin >> str;
    SetAQStatus(ToInt(str));
  }
};

class QuestionAnswer {
private:
  int ParentQId, ThreadQId, ToId, FromId, AQStatus;
  std::string Question, Answer;

public:
  QuestionAnswer()
      : ParentQId(-1), ThreadQId(-1), ToId(-1), FromId(-1), AQStatus(-1) {}

  QuestionAnswer(std::string &line) {
    std::vector<std::string> QAData = SplitLine(line);
    // assert(QAData.size() == 7);
    ParentQId = ToInt(QAData[0]);
    ThreadQId = ToInt(QAData[1]);
    ToId = ToInt(QAData[2]);
    FromId = ToInt(QAData[3]);
    AQStatus = ToInt(QAData[4]);
    Question = QAData[5];
    Answer = QAData[6];
  }

  // getters
  int GetParentQId() const { return ParentQId; }
  int GetThreadQId() const { return ThreadQId; }
  int GetToId() const { return ToId; }
  int GetFromId() const { return FromId; }
  int GetAQStatus() const { return AQStatus; }
  std::string GetQuestion() const { return Question; }
  std::string GetAnswer() const { return Answer; }

  // setters
  void SetParentQId(int ParentQId) { this->ParentQId = ParentQId; }
  void SetThreadQId(int ThreadQId) { this->ThreadQId = ThreadQId; }
  void SetToId(int ToId) { this->ToId = ToId; }
  void SetFromId(int FromId) { this->FromId = FromId; }
  void SetAQStatus(int AQStatus) { this->AQStatus = AQStatus; }
  void SetQuestion(const std::string &Question) { this->Question = Question; }
  void SetAnswer(const std::string &Answer) { this->Answer = Answer; }

  std::string ToString() const {
    std::ostringstream oss;
    oss << ParentQId << "," << ThreadQId << "," << FromId << "," << ToId << ","
        << AQStatus << "," << Question << "," << Answer;

    return oss.str();
  }

  // Printing Styles
  void PrintToQuestions() const {
    if (GetThreadQId() != -1)
      std::cout << "\n\tThread: ";

    std::cout << "Question Id (" << GetParentQId() << ") ";

    // not anonymous question
    if (GetAQStatus() == 0)
      std::cout << "from user id(" << GetFromId() << ")";

    std::cout << "\t\tQuestion: " << GetQuestion() << std::endl;

    if (GetThreadQId() != -1)
      std::cout << "\tThread: ";

    if (GetAnswer() != "")
      std::cout << "\tAnswer: " << GetAnswer() << std::endl;
  }

  void PrintFromMeQuestions() const {
    std::cout << "\nQuestion Id(" << GetParentQId();

    // not anonymous question = other guy can see my Id
    if (GetAQStatus() != 0)
      std::cout << " !AQ ";

    std::cout << "to user id(" << GetToId() << ")";

    std::cout << "\tQuestion: " << GetQuestion();

    if (GetAnswer() == "")
      std::cout << "\tNot Answered Yet" << std::endl;
    else {
      std::cout << "\tAnswer: " << GetAnswer() << std::endl;
    }
  }
};

class AQManager {
private:
  std::map<int, QuestionAnswer> AQMap;
  std::map<int, std::vector<int>> ParentId_ThreadIds;
  // std::vector<int> FromMeQuestionsId;
  // std::vector<int> ToMeQuestionsId;
  int lastQuestionId;

public:
  void LoadQA() {
    std::vector<std::string> lines;
    ReadFile("questions.txt", lines);
    lastQuestionId = lines.size() + 1;

    for (auto &line : lines) {
      QuestionAnswer CurrentQuestion(line);
      AQMap[CurrentQuestion.GetParentQId()] = CurrentQuestion;

      // not a thread question
      if (CurrentQuestion.GetThreadQId() == -1)
        ParentId_ThreadIds[CurrentQuestion.GetParentQId()];

      // push the thread id to it's parent id
      else
        ParentId_ThreadIds[CurrentQuestion.GetThreadQId()].push_back(
            CurrentQuestion.GetParentQId());
    }
  }

  AQManager() {
    AQMap.clear();
    LoadQA();
  }

  std::vector<int> GetToUserQuestions(const User &SignedUser) {

    std::vector<int> ToMeQuestionsIds;
    for (const auto &question : ParentId_ThreadIds) {
      // question.frist = main question id
      if (AQMap[question.first].GetToId() == SignedUser.GetId())
        ToMeQuestionsIds.push_back(question.first);

      for (const auto &thread_question : question.second) {
        if (AQMap[thread_question].GetToId() == SignedUser.GetId())
          ToMeQuestionsIds.push_back(thread_question);
      }
    }
    return ToMeQuestionsIds;
  }
  void PrintToMeQuestions(const User &SignedUser) {
    std::vector<int> ToMeQuestionIds = GetToUserQuestions(SignedUser);

    if (ToMeQuestionIds.size() == 0)
      std::cout << "There is no Questions" << std::endl;

    for (auto &question : ToMeQuestionIds)
      AQMap[question].PrintToQuestions();
  }

  std::vector<int> GetFromUserQuestions(const User &SignedUser) {

    std::vector<int> FromMeQuestionsIds;
    for (const auto &question : ParentId_ThreadIds) {
      // question.frist = main question id
      if (AQMap[question.first].GetFromId() == SignedUser.GetId())
        FromMeQuestionsIds.push_back(question.first);

      for (const auto &thread_question : question.second) {
        if (AQMap[thread_question].GetFromId() == SignedUser.GetId())
          FromMeQuestionsIds.push_back(thread_question);
      }
    }
    return FromMeQuestionsIds;
  }

  void PrintFromMeQuestions(const User &SignedUser) {
    std::vector<int> FromMeQuestionIds = GetFromUserQuestions(SignedUser);

    if (FromMeQuestionIds.size() == 0)
      std::cout << "There is no Questions" << std::endl;

    for (auto &question : FromMeQuestionIds)
      AQMap[question].PrintToQuestions();
  }

  int CheckToMeQuestion(const User &SignedUser) {
    int QuestionId;
    while (true) {
      std::cout << "Enter Question id or -1 to cancel: ";
      std::cin >> QuestionId;

      if (!AQMap.count(QuestionId)) {
        std::cout << "Error: No Question with such an Id. Try again"
                  << std::endl;
        return -1;
      }

      if (AQMap[QuestionId].GetToId() != SignedUser.GetId())
        std::cout << "Error: Invalid Quesiton Id. Try again" << std::endl;
    }

    return QuestionId;
  }

  int CheckThreadQuestion(const User &SignedUser) {
    int ThreadId;
    while (true) {
      std::cout
          << "For thread question: Enter Question id or -1 for new question: ";
      std::cin >> ThreadId;
    }

    if (ThreadId == -1)
      return -1;

    for ()
      return ThreadId;
  }

  void AnswerQuestion(const User &SignedUser) {
    int QuestionId = CheckToMeQuestion(SignedUser);

    if (QuestionId == -1)
      return;

    QuestionAnswer &CurrnetQuestion = AQMap[QuestionId];
    CurrnetQuestion.PrintToQuestions();
    std::string NewAnswer;

    // if this question already answered
    if (CurrnetQuestion.GetAnswer() != "")
      std::cout << "Warning: Already answered. Answer will be Updated"
                << std::endl;

    std::cout << "Enter answer: ";
    std::cin >> NewAnswer;

    AQMap[QuestionId].SetAnswer(NewAnswer);
  }

  void UpdateQuestionAnswer() {
    std::vector<std::string> lines;
    for (const auto &question : AQMap)
      lines.push_back(question.second.ToString());
    WriteFile("questions.txt", lines);
  }
};

class UsersManager {
private:
  std::map<std::string, User> Users;
  User SignedUser;
  int LastUserId;

public:
  void LoadUsers() {
    std::vector<std::string> lines;
    ReadFile("users.txt", lines);
    LastUserId = lines.size() + 1;

    // user name in idx = 1;
    for (const auto &line : lines) {
      User NewUser(line);
      Users[NewUser.GetUserName()] = NewUser;
    }
  }

  UsersManager() {
    Users.clear();
    LoadUsers();
  }

  const User &GetSignedUser() const { return SignedUser; }

  void LogIn() {
    LoadUsers();
    std::string UserName, Password;
    std::cout << "Enter user name & password: ";
    std::cin >> UserName >> Password;

    if (Users.count(UserName) && (Users[UserName].GetPassword() == Password))
      SignedUser = Users[UserName];
    else {
      std::cout << "Incorrect username or password!\n\n";
      return;
    }
  }

  void UpdateUsers(const User &NewUser) {
    std::vector<std::string> UserInfoLine{SignedUser.ToStr()};
    WriteFile("users.txt", UserInfoLine);
  }

  void SignUp() {
    LoadUsers();
    std::string UserName;
    std::cout << "Enter user name. (No spaces): ";
    std::cin >> UserName;
    while (Users.count(UserName)) {
      std::cout << "This username already used Try another one.\n";
      std::cout << "Enter user name. (No spaces): ";
      std::cin >> UserName;
    }

    SignedUser.AddNewUser(UserName, LastUserId);
    UpdateUsers(SignedUser);
  }

  void ListSystemUsers() {
    for (auto user : Users) {
      std::cout << "ID: " << user.second.GetId() << "\t\tName: " << user.first
                << (user.second.GetId() == SignedUser.GetId() ? "\t\t(You)"
                                                              : "")
                << std::endl;
    }
  }

  void LogOut() { SignedUser = User(); }
};

class AskMeManager {
private:
  std::vector<std::string> LoginMenu{"Login", "Sign UP"};
  std::vector<std::string> UserMenu{"Print Questions To Me",
                                    "Print Questions From Me",
                                    "Answer Question",
                                    "Delete Question",
                                    "Ask Question",
                                    "List System Users",
                                    "Feed",
                                    "Logout"};

  UsersManager users_manager;
  AQManager questions_answers_manager;

public:
  AskMeManager() {}

  void PrintMenu(const std::vector<std::string> &Menu) const {
    std::cout << "Menu:" << std::endl;
    int MenuSize = Menu.size();
    std::string UserChoice;
    for (int i = 0; i < MenuSize; ++i)
      std::cout << "\t" << i + 1 << ": " << Menu[i] << '\n';
  }

  int ValidUserChoice(const int max) {
    while (true) {
      std::string UserChoice;
      std::cout << "\nEnter number in range 1 - " << max << ": ";
      std::cin >> UserChoice;
      int UserChoiceNum = ToInt(UserChoice);
      if (1 <= UserChoiceNum && UserChoiceNum <= max)
        return UserChoiceNum;
      std::cout << "\nError Invalid number...Try again\n\n";
    }
  }

  void run() {
    while (true) {
      int UserChoice;
      if (users_manager.GetSignedUser().GetId() == -1) {
        PrintMenu(LoginMenu);
        UserChoice = ValidUserChoice(LoginMenu.size());

        if (UserChoice == 1)
          users_manager.LogIn();
        else if (UserChoice == 2)
          users_manager.SignUp();
      }

      else {
        PrintMenu(UserMenu);
        UserChoice = ValidUserChoice(UserMenu.size());

        if (UserChoice == 1)
          questions_answers_manager.PrintToMeQuestions(
              users_manager.GetSignedUser());
        if (UserChoice == 2)
          questions_answers_manager.PrintFromMeQuestions(
              users_manager.GetSignedUser());
        if (UserChoice == 3)
          questions_answers_manager.AnswerQuestion();
        if (UserChoice == 6)
          users_manager.ListSystemUsers();
        if (UserChoice == 8)
          users_manager.LogOut();
      }
    }
  }
};

int main(int argc, char *argv[]) {
  AskMeManager ask;
  ask.run();
  return 0;
}
