#include <assert.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// i made it in about 3 days there is much more we can use
// in this project we really don't care so much about data sturcutre
//
// helper methods
void ReadFileToMemory(const std::string &path,
                      std::vector<std::string> &lines) {
  std::ifstream FileHandler(path.c_str());

  if (FileHandler.fail()) {
    std::cout << "Error: can't open the file\n\n" << std::endl;
    return;
  }

  lines.clear();
  std::string line;

  while (std::getline(FileHandler, line))
    lines.push_back(line);

  FileHandler.close();
}

void WriteFile(const std::string &path, const std::vector<std::string> &lines,
               bool append = true) {

  auto status = std::ios_base::in | std::ios_base::out |
                (append ? std::ios_base::app : std::ios_base::trunc);

  std::fstream FileHandler(path.c_str(), status);

  if (FileHandler.fail()) {
    std::cout << "Error: Can't open the file.\n\n" << std::endl;
    return;
  }

  for (const auto &line : lines) {
    FileHandler << line << std::endl;
  }

  FileHandler.close();
}

std::vector<std::string> SplitLine(const std::string &line,
                                   const std::string delimiter = ",") {
  std::vector<std::string> CleanData;
  std::string linecpy{line};

  int pos = 0;
  std::string substr;
  while ((pos = linecpy.find(delimiter)) != -1) {
    substr = linecpy.substr(0, pos);
    CleanData.push_back(substr);
    linecpy.erase(0, pos + delimiter.length());
  }
  CleanData.push_back(linecpy);

  return CleanData;
}

int StrToInt(const std::string &str) {
  std::istringstream iss(str);
  int number;
  iss >> number;
  return number;
}

static std::string delimiter = ",";

class QuestionAnswer {
private:
  int QuestionId, ParentQuestionId, ToId, FromId;
  bool QuestionStatus; // is it Anonymous Question or not
  std::string Question, Answer;

public:
  QuestionAnswer()
      : QuestionId(-1), ParentQuestionId(-1), ToId(-1), FromId(-1) {}

  QuestionAnswer(const std::string &line) {
    std::vector<std::string> RawQuestionAnswerData;
    RawQuestionAnswerData = SplitLine(line);
    assert(RawQuestionAnswerData.size() == 7);

    QuestionId = StrToInt(RawQuestionAnswerData[0]);
    ParentQuestionId = StrToInt(RawQuestionAnswerData[1]);
    ToId = StrToInt(RawQuestionAnswerData[2]);
    FromId = StrToInt(RawQuestionAnswerData[3]);
    QuestionStatus = StrToInt(RawQuestionAnswerData[4]);
    Question = RawQuestionAnswerData[5];
    Answer = RawQuestionAnswerData[6];
  }

  // Getters
  int GetQuestionId() const { return QuestionId; }
  int GetParentQuestionId() const { return ParentQuestionId; }
  int GetToId() const { return ToId; }
  int GetFromId() const { return FromId; }
  bool GetQuestionStatus() const { return QuestionStatus; }
  std::string GetQuestionText() const { return Question; }
  std::string GetAnswerText() const { return Answer; }

  // Setters
  void SetQuestionId(int QuestionId) { this->QuestionId = QuestionId; }
  void SetParentQuestionId(int ParentQuestionId) {
    this->ParentQuestionId = ParentQuestionId;
  }
  void SetToId(int ToId) { this->ToId = ToId; }
  void SetFromId(int FromId) { this->FromId = FromId; }
  void SetQuestionStatus(bool QuestionStatus) {
    this->QuestionStatus = QuestionStatus;
  }
  void SetQuestionText(const std::string &QuestionText) {
    this->Question = QuestionText;
  }
  void SetAnswerText(const std::string &AnswerText) {
    this->Answer = AnswerText;
  }

  // QuestionAnswer Functions
  std::string ToStrFormat(const std::string &delimiter) {
    std::ostringstream oss;
    oss << GetQuestionId() << delimiter << GetParentQuestionId() << delimiter
        << GetToId() << delimiter << GetFromId() << delimiter
        << GetQuestionStatus() << delimiter << GetQuestionText() << delimiter
        << GetAnswerText();
    return oss.str();
  };

  // 3 Styles of Printing the Question and Answer
  //
  // 1) Print To Me Question and it's Answer Format
  void PrintToMe() {
    bool HasParentQuestionId = (ParentQuestionId != -1);
    bool IsAnonymousQuestion = (GetQuestionStatus());
    bool IsAnswerd = (GetAnswerText() != "");

    if (HasParentQuestionId)
      std::cout << "\tThread: ";

    std::cout << "Question Id(" << GetQuestionId() << ") ";

    if (!IsAnonymousQuestion)
      std::cout << "from user id(" << GetFromId() << ") ";

    std::cout << "Question: " << GetQuestionText() << std::endl;

    if (HasParentQuestionId && IsAnswerd)
      std::cout << "\tThread: ";
    if (IsAnswerd)
      std::cout << "\tAnswer: " << GetAnswerText() << std::endl << std::endl;
  }

  // 2) Print From Me Questions and it's Answer Format
  void PrintFromMe() {
    bool IsAnonymousQuestion = GetQuestionStatus();
    std::cout << "Question Id(" << GetQuestionId() << ")";

    if (!IsAnonymousQuestion)
      std::cout << " !AQ ";

    std::cout << "to user id(" << GetToId() << ")";

    std::cout << "\tQuestion: " << GetQuestionText();

    if (GetAnswerText() == "") {
      std::cout << "\t\tNOT Answered YET !" << std::endl;
      return;
    } else {
      std::cout << "\t\tAnswer:" << GetAnswerText() << std::endl;
    }
  }

  // 3) Print Feed Quesiton and it's Answer Format
  void PrintFeed() {
    bool HasParentQuestionId = GetParentQuestionId() != -1;
    bool IsAnonymousQuestion = GetQuestionStatus();
    if (HasParentQuestionId)
      std::cout << "\nThread Parent Question ID (" << GetParentQuestionId()
                << ") ";

    std::cout << "Question Id (" << GetQuestionId() << ") ";

    if (!IsAnonymousQuestion)
      std::cout << "from user id(" << GetFromId() << ") ";

    std::cout << "To user id(" << GetToId() << ") ";

    std::cout << "\tQuestion: " << GetQuestionText() << std::endl;
    std::cout << "\tAnswer: " << GetAnswerText() << std::endl;
  }
};

class User {
private:
  int UserId;
  std::string UserName, Password, Name, Email;
  bool AllowAnonymousQuestions;

public:
  User()
      : UserId(-1) {
  } // other strings will have default consturctor and bool default false

  User(const std::string &line) {
    std::vector<std::string> RawUserData = SplitLine(line);
    assert(RawUserData.size() == 6);

    UserId = StrToInt(RawUserData[0]);
    UserName = RawUserData[1];
    Password = RawUserData[2];
    Name = RawUserData[3];
    Email = RawUserData[4];
    AllowAnonymousQuestions = StrToInt(RawUserData[5]);
  }

  // Getters
  int GetUserId() const { return UserId; }
  std::string GetUserName() const { return UserName; }
  std::string GetPassword() const { return Password; }
  std::string GetName() const { return Name; }
  std::string GetEmail() const { return Email; }
  bool GetAllowAnonymousQuestions() const { return AllowAnonymousQuestions; }

  // Setters
  void SetUserId(const int UserId) { this->UserId = UserId; }
  void SetUserName(const std::string &UserName) { this->UserName = UserName; }
  void SetPassword(const std::string &Password) { this->Password = Password; }
  void SetName(const std::string &Name) { this->Name = Name; }
  void SetEmail(const std::string &Email) { this->Email = Email; }
  void SetAllowAnonymousQuestions(const bool AllowAnonymousQuestions) {
    this->AllowAnonymousQuestions = AllowAnonymousQuestions;
  }

  // returning a line which is The RawDate Style to be written in users.txt
  std::string ToStrFormat(const std::string &delimiter) const {
    std::ostringstream oss;
    oss << GetUserId() << delimiter << GetUserName() << delimiter
        << GetPassword() << delimiter << GetName() << delimiter << GetEmail()
        << delimiter << GetAllowAnonymousQuestions();
    return oss.str();
  }

  void Print() const {
    std::cout << "ID: " << GetUserId() << "\t\tName: " << GetUserName()
              << std::endl;
  }
};

class QAManager {
private:
  std::map<int, QuestionAnswer> QuestionsMAP;
  int LastQuesitonId;
  // static QAManager QAManagerInstance;

  void LoadQuestionsDataBase() {

    std::vector<std::string> RawQuestionAnswerData;
    ReadFileToMemory("questions.txt", RawQuestionAnswerData);
    LastQuesitonId = RawQuestionAnswerData.size() + 1;
    QuestionsMAP.clear();

    for (const std::string &line : RawQuestionAnswerData) {
      QuestionAnswer NewQuestionAnswer(line);
      QuestionsMAP[NewQuestionAnswer.GetQuestionId()] = NewQuestionAnswer;
    }
  }

  void UpdateDataBase() {
    std::vector<std::string> RawQuestionAnswerData;
    for (auto &Question : QuestionsMAP)
      RawQuestionAnswerData.push_back(Question.second.ToStrFormat(delimiter));
    WriteFile("questions.txt", RawQuestionAnswerData, false);
  }

  // QAManager() { LoadQuestionsDataBase(); }

public:
  QAManager() { LoadQuestionsDataBase(); }
  // static QAManager &GetQAManager() { return QAManagerInstance; }

  void GetToMeQuestions(std::map<int, std::set<int>> &ToMeQuestionIds,
                        const User &CurrentUser) {

    for (const auto &Question : QuestionsMAP) {
      const QuestionAnswer &question = Question.second;
      bool IsToMeQuestion = (question.GetToId() == CurrentUser.GetUserId());
      bool IsThreadQuestion = (question.GetParentQuestionId() != -1);

      if (IsToMeQuestion) {
        if (IsThreadQuestion)
          ToMeQuestionIds[question.GetParentQuestionId()].insert(
              Question.second.GetQuestionId());
        else
          ToMeQuestionIds[question.GetQuestionId()];
      }
    }
  }

  void GetFromMeQuestionId(std::vector<int> &FromMeQuestionId,
                           const User &CurrentUser) {
    for (const auto &Question : QuestionsMAP) {
      const QuestionAnswer &question = Question.second;
      bool IsFromMeQuestion = (question.GetFromId() == CurrentUser.GetUserId());

      if (IsFromMeQuestion)
        FromMeQuestionId.push_back(Question.first);
    }
  }

  void GetFeed(std::vector<int> &FeedIds) {
    for (const auto &Question : QuestionsMAP) {
      const QuestionAnswer &question = Question.second;
      bool IsAnswerd = (question.GetAnswerText() != "");

      if (IsAnswerd)
        FeedIds.push_back(Question.first);
    }
  }

  void GetMainQuestionIds(int ToUserId, std::set<int> &MainQuestionIds) {
    bool HasParentQuestionId;
    bool IsToTheSameUser;
    for (const auto &Question : QuestionsMAP) {
      auto const &question = Question.second;
      HasParentQuestionId = question.GetParentQuestionId() != -1;
      IsToTheSameUser = question.GetToId() == ToUserId;
      if (!HasParentQuestionId && IsToTheSameUser)
        MainQuestionIds.insert(Question.first);
    }
  }

  void PrintToMeQuestions(const User &CurrentUser) {
    std::map<int, std::set<int>> ToMeQuestionIds;
    GetToMeQuestions(ToMeQuestionIds, CurrentUser);

    if (ToMeQuestionIds.size() == 0) {
      std::cout << "\t\nNo Questions.\n";
      return;
    }
    // loop on every main question and print it
    for (auto const &Question : ToMeQuestionIds) {
      QuestionsMAP[Question.first].PrintToMe();

      // loop on every id under this main id and print it to be printed in
      // sequence
      for (auto const &ThreadQuestion : Question.second)
        QuestionsMAP[ThreadQuestion].PrintToMe();
    }
  }

  void PrintFromMeQuestions(const User &CurrentUser) {
    std::vector<int> FromMeQuestionId;
    GetFromMeQuestionId(FromMeQuestionId, CurrentUser);

    if (FromMeQuestionId.size() == 0) {
      std::cout << "\n\tNo Questions Asked To You.\n";
      return;
    }

    for (const auto &Question : FromMeQuestionId)
      QuestionsMAP[Question].PrintFromMe();
  }

  void PrintFeed(const User &CurrentUser) {
    std::vector<int> FeedIds;
    GetFeed(FeedIds);

    if (FeedIds.size() == 0) {
      std::cout << "\n\t\tThere's no Feeds Till this moment...\n";
      return;
    }

    for (const auto Question : FeedIds)
      QuestionsMAP[Question].PrintFeed();
  }

  void DeleteQusetion(const User &CurrentUser) {
    std::map<int, std::set<int>> ToMeQuestionIds;
    int QuestionId = ReadToMeQuestionId(ToMeQuestionIds, CurrentUser);

    if (QuestionId == -1)
      return;

    for (const auto &Question : ToMeQuestionIds) {
      // erase the main question
      QuestionsMAP.erase(Question.first);
      // erase thread question if there
      const auto &ThreadIds = Question.second;
      for (const auto &ThreadId : ThreadIds)
        QuestionsMAP.erase(ThreadId);
    }
    UpdateDataBase();
  }

  void AnswerQuestion(const User &CurrentUser) {
    std::map<int, std::set<int>> ToMeQuestionIds;
    int QuestionId = ReadToMeQuestionId(ToMeQuestionIds, CurrentUser);

    if (QuestionId == -1)
      return;

    QuestionAnswer &CurrentQuestion = QuestionsMAP[QuestionId];
    if (CurrentQuestion.GetAnswerText() != "")
      std::cout << "Warning: Already answered. Answer will be updated.\n";

    std::string NewAnswer;
    std::cout << "Enter answer: ";
    std::cin.ignore();
    std::getline(std::cin, NewAnswer);
    CurrentQuestion.SetAnswerText(NewAnswer);
    UpdateDataBase();
  }

  void AskQuestion(const User &CurrentUser,
                   const std::pair<int, bool> &ReciverData) {
    if (ReciverData.first == -1)
      return;

    QuestionAnswer NewQuestion;
    if (ReciverData.second == 0) {
      std::cout
          << "\tNote: Anonymous questions are not allowed for this user.\n";
      NewQuestion.SetQuestionStatus(0);
    } else {
      std::string QuestionStatusStr;
      int QuestionStatus;
      std::cout << "Send as anonymous questions?: (0 or 1): ";
      std::cin >> QuestionStatusStr;
      QuestionStatus = StrToInt(QuestionStatusStr);
      NewQuestion.SetQuestionStatus(QuestionStatus);
    }

    int QuestionId = ReadMainQuestionId(ReciverData.first);
    std::string QuestionText;
    std::cout << "Enter question text: ";
    std::cin.ignore();
    std::getline(std::cin, QuestionText);

    NewQuestion.SetQuestionId(LastQuesitonId);
    NewQuestion.SetToId(ReciverData.first);
    NewQuestion.SetFromId(CurrentUser.GetUserId());
    NewQuestion.SetQuestionText(QuestionText);

    QuestionsMAP[LastQuesitonId] = NewQuestion;
    UpdateDataBase();
  }

  int ReadToMeQuestionId(std::map<int, std::set<int>> ToMeQuestionIds,
                         const User &CurrentUser) {

    std::string QuestionsIdstr;
    int QuestionId;
    bool IsFound;
    GetToMeQuestions(ToMeQuestionIds, CurrentUser);

    do {
      IsFound = false;
      std::cout << "Enter Question id or -1 to cancel: ";
      std::cin >> QuestionsIdstr;
      QuestionId = StrToInt(QuestionsIdstr);

      if (QuestionId == -1)
        return QuestionId;

      // check if Question Id is in ToMeQuestionIds
      for (auto const &Question : ToMeQuestionIds) {
        // found as main question
        if (ToMeQuestionIds.count(QuestionId)) {
          IsFound = true;
          return QuestionId;
        }

        // check if Question is ThreadQuestion
        auto const &question = Question.second;
        auto it = question.find(QuestionId);
        if (it != question.end()) {
          IsFound = true;
          return QuestionId;
        }
      }

      if (!IsFound)
        std::cout << "\tInvalid Quesiton ID. Please try again or enter -1 to "
                     "cancel.\n"
                  << std::endl;
    } while (!IsFound);
    return QuestionId;
  }

  int ReadMainQuestionId(int ToUserId) {
    std::string QuestionIdStr;
    int QuestionId;
    bool IsFound;
    std::set<int> MainQuestionIds;
    GetMainQuestionIds(ToUserId, MainQuestionIds);

    do {
      IsFound = false;
      std::cout << "For thread question: Enter Question id or -1 for new "
                   "question: ";
      std::cin >> QuestionIdStr;
      QuestionId = StrToInt(QuestionIdStr);

      if (QuestionId == -1)
        return QuestionId;

      if (MainQuestionIds.count(QuestionId))
        return QuestionId;

      if (!IsFound)
        std::cout << "\tInavlid Question ID. Please try again or enter -1 to "
                     "cancel.\n";

    } while (!IsFound);
    return QuestionId;
  }
};

// QAManager QAManager::QAManagerInstance;

class UsersManager {
private:
  std::map<std::string, User> Users;
  User CurrentUser;
  int LastUserId;

  void PrintWelcomeMessage() {
    std::cout << "\n\t\tWelcome " << CurrentUser.GetUserName() << std::endl;
  }

  void LoadUsers() {
    std::vector<std::string> RawDataInLines;
    ReadFileToMemory("users.txt", RawDataInLines);
    LastUserId = RawDataInLines.size() + 1;
    Users.clear();
    for (const auto &line : RawDataInLines) {
      User NewUser(line);
      Users[NewUser.GetUserName()] = NewUser;
    }
  }

  // written just an extention to the system because
  // system will just Add New Users without any cahnges to the old ones
  void UpdateDataBase() {
    std::vector<std::string> RawDataUsers;
    for (auto const &user : Users)
      RawDataUsers.push_back(user.second.ToStrFormat(delimiter));
    WriteFile("users.txt", RawDataUsers, false);
  }

  // this function will be light for the system because it's just do the job
  // on the right way
  void AddUserToDataBase(const User &AddedUser) {
    std::vector<std::string> RawDataUsers;
    RawDataUsers.push_back(AddedUser.ToStrFormat(delimiter));
    WriteFile("users.txt", RawDataUsers);
  }

public:
  UsersManager() { LoadUsers(); }

  User GetCurrentUser() { return CurrentUser; }

  // extention welcome message to the system when user sign up or signed in

  void AttempToLogIn() {
    LoadUsers();

    std::string username, password;
    do {
      std::cout << "Enter user name & password: ";
      std::cin >> username >> password;

      if (!(Users.count(username) && Users[username].GetPassword() == password))
        std::cout << "Invalid User Name or Password" << std::endl;

    } while (
        !(Users.count(username) && Users[username].GetPassword() == password));

    CurrentUser = Users[username];
    PrintWelcomeMessage();
  };

  void CreateUserAccount() {
    std::string str;
    do {
      std::cout << "Enter user name. (No spaces): ";
      std::cin >> str;
      if (Users.count(str))
        std::cout << "This user name Already in user...Try another one.\n";
    } while (Users.count(str));
    CurrentUser.SetUserName(str);

    std::cout << "Enter Password: ";
    std::cin >> str;
    CurrentUser.SetPassword(str);

    std::cout << "Enter name: ";
    std::cin >> str;
    CurrentUser.SetName(str);

    std::cout << "Enter Email: ";
    std::cin >> str;
    CurrentUser.SetEmail(str);

    std::cout << "Allow anonymous questions? (0 or 1): ";
    std::cin >> str;
    CurrentUser.SetAllowAnonymousQuestions(StrToInt(str));

    CurrentUser.SetUserId(LastUserId);
    Users[CurrentUser.GetUserName()] = CurrentUser;
    AddUserToDataBase(CurrentUser);
    PrintWelcomeMessage();
  };

  // just return the user id insted of returning the whole User with it's
  // internal data which shouldn't be exposed because it's diffrent user from
  // the user that has been signed in
  std::pair<int, bool> const ReadUserId() const {
    std::string UserIdStr;
    int UserId;
    bool IsFound, IsAnonymousQuestion;

    do {
      std::cout << "Enter User id or -1 to cancel: ";
      std::cin >> UserIdStr;
      UserId = StrToInt(UserIdStr);
      IsFound = false;

      if (UserId == -1)
        return std::make_pair(UserId, IsAnonymousQuestion);

      for (const auto &user : Users) {
        const User &current_user = user.second;
        if (current_user.GetUserId() == UserId) {
          IsFound = true;
          IsAnonymousQuestion = current_user.GetAllowAnonymousQuestions();
          return std::make_pair(UserId, IsAnonymousQuestion);
        }
      }

      if (!IsFound) {
        std::cout << "\tInvalid User ID Please try again.\n";
      }
    } while (!IsFound);
    return std::make_pair(UserId, IsAnonymousQuestion);
  }

  void ListSystemUsers() const {
    for (const auto &User : Users)
      User.second.Print();
  }

  void LogOut() { CurrentUser = User(); }
};

class Menu {
private:
  std::vector<std::string> UnSignedUserMenu{"LogIn", "Sign Up"};

  std::vector<std::string> SignedUserMenu{"Print Questions To Me",
                                          "Print Questions From Me",
                                          "Answer Question",
                                          "Delete Question",
                                          "Ask Question",
                                          "List System Users",
                                          "Feed",
                                          "LogOut"};
  int UnSignedUserMenuSize = UnSignedUserMenu.size();
  int SignedUserMenuSize = SignedUserMenu.size();

public:
  // Getters
  const int GetMenuSize(const User &CurrentUser) {
    if (CurrentUser.GetUserId() == -1)
      return UnSignedUserMenuSize;
    return SignedUserMenuSize;
  }

  void Print(const User &CurrentUser) {
    std::cout << "\nMenu:" << std::endl;

    if (CurrentUser.GetUserId() == -1) {
      for (int i = 0; i < UnSignedUserMenuSize; ++i)
        std::cout << '\t' << i + 1 << ": " << UnSignedUserMenu[i] << std::endl;
    }

    else {
      for (int i = 0; i < SignedUserMenuSize; ++i)
        std::cout << '\t' << i + 1 << ": " << SignedUserMenu[i] << std::endl;
    }
    std::cout << std::endl;
  }
};

class AskMeSystem {
private:
  UsersManager users_manager;
  QAManager question_answer_manger;
  Menu systemMenu;

  int ReadUserChoice(const User &CurrentUser) {
    std::string UserChoice;
    int UserChoiceNumber;
    int max = systemMenu.GetMenuSize(CurrentUser);

    do {
      std::cout << "Enter a number in the range 1 - " << max << ": ";
      std::cin >> UserChoice;
      UserChoiceNumber = StrToInt(UserChoice);

      if (!(1 <= UserChoiceNumber && UserChoiceNumber <= max))
        std::cout << "Error: Invalid number...Try again\n" << std::endl;
    } while (!(1 <= UserChoiceNumber && UserChoiceNumber <= max));

    return UserChoiceNumber;
  }

  void AccessSystem() {
    const User &CurrentUser = users_manager.GetCurrentUser();

    if (CurrentUser.GetUserId() == -1) {
      systemMenu.Print(CurrentUser);
      int UserChoice = ReadUserChoice(CurrentUser);
      if (UserChoice == 1)
        users_manager.AttempToLogIn();
      else {
        users_manager.CreateUserAccount();
      }
    } else {
      HandleUserChoice();
    }
  }

  void HandleUserChoice() {
    systemMenu.Print(users_manager.GetCurrentUser());
    int UserChoice = ReadUserChoice(users_manager.GetCurrentUser());

    if (UserChoice == 1)
      question_answer_manger.PrintToMeQuestions(users_manager.GetCurrentUser());
    else if (UserChoice == 2)
      question_answer_manger.PrintFromMeQuestions(
          users_manager.GetCurrentUser());
    else if (UserChoice == 3)
      question_answer_manger.AnswerQuestion(users_manager.GetCurrentUser());
    else if (UserChoice == 4)
      question_answer_manger.DeleteQusetion(users_manager.GetCurrentUser());
    else if (UserChoice == 5)
      question_answer_manger.AskQuestion(users_manager.GetCurrentUser(),
                                         users_manager.ReadUserId());
    else if (UserChoice == 6)
      users_manager.ListSystemUsers();
    else if (UserChoice == 7)
      question_answer_manger.PrintFeed(users_manager.GetCurrentUser());
    else if (UserChoice == 8)
      users_manager.LogOut();
  }

public:
  AskMeSystem(){};

  void run() {
    while (true) {
      AccessSystem();
    }
  }
};

int main(int argc, char *argv[]) {
  AskMeSystem AskMe;
  AskMe.run();
  return 0;
}
