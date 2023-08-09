#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// unfinished project my first intention was to make deals with files but iam in
// harry because i have to go back to my militry service but i got the whole
// logic behind the project

// helper methods
int strToInt(std::string &numberStr) {
  int number;
  std::istringstream iss(numberStr);
  iss >> number;
  return number;
}

void ReadFileToMemory(const std::string &path,
                      std::vector<std::string> &lines) {
  std::ifstream fin(path.c_str());

  if (fin.fail())
    std::cout << "Error: Can't open the file" << std::endl;

  std::string line;
  while (std::getline(fin, line)) {
    lines.push_back(line);
  }

  fin.close();
}

void WriteFile(const std::string &path, std::vector<std::string> &lines,
               bool isAppend = true) {

  auto status = std::ios::in | std::ios::out | std::ios::app;
  if (!isAppend)
    status = std::ios::in | std::ios::out | std::ios::trunc;

  std::ofstream fout(path.c_str(), status);

  if (fout.fail())
    std::cout << "Error: Can't open the file" << std::endl;

  for (const auto &line : lines)
    fout << line << std::endl;

  fout.close();
}

const std::string delimter = ",";

std::vector<std::string> SplitLine(const std::string &line,
                                   std::string delimiter = ",") {
  std::vector<std::string> RawData;
  std::string linecpy{line};
  std::string substr;

  int pos = 0;
  while ((pos = linecpy.find(delimiter)) != -1) {
    substr = linecpy.substr(0, pos);
    RawData.push_back(substr);
    linecpy.erase(0, pos + delimiter.length());
  }
  RawData.push_back(linecpy);
  return RawData;
}

std::string return_current_time_and_date() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
  return ss.str();
}

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class ReadingSession {
private:
  std::string bookTitle, TimeDate;
  int bookPages, currentPage;

public:
  ReadingSession() : bookPages(-1), currentPage(-1) {}

  ReadingSession(std::vector<std::string> &sessionData) {
    bookTitle = sessionData[0];
    currentPage = strToInt(sessionData[1]);
    bookPages = strToInt(sessionData[2]);
    TimeDate = sessionData[3];
  }

  void Print() const {
    std::cout << bookTitle << " Page: " << currentPage << "/" << bookPages
              << " - " << TimeDate;
  }

  const std::string ToStr() {
    std::ostringstream oss;
    oss << delimter << bookTitle << delimter << currentPage << delimter
        << bookPages << delimter << TimeDate;
    return oss.str();
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class Menu {
private:
  std::vector<std::string> defaultMenu{"LogIn", "Sign Up"};
  std::vector<std::string> customerMenu{
      "View Profile", "List & Select from My Reading History",
      "list & Select from Available Books", "Logout"};
  std::vector<std::string> adminMenu{"View Profile", "Add Book", "Logout"};

  void Print(std::vector<std::string> currentUserMenu) const {
    int currentUserMenuSize = currentUserMenu.size();

    std::cout << "Menu:" << std::endl;
    for (int i = 0; i < currentUserMenuSize; ++i)
      std::cout << "\t" << i + 1 << ": " << currentUserMenu[i] << std::endl;
  }

  int readMenuChoice(const int menuSize) const {
    std::string userChoiceStr;
    int userChoice;

    do {
      std::cout << "Enter number in range 1 - " << menuSize << ": ";
      std::cin >> userChoiceStr;
      userChoice = strToInt(userChoiceStr);

      if (!(1 <= userChoice && userChoice <= menuSize))
        std::cout << "Invalid number...Try again!" << std::endl;
    } while (!(1 <= userChoice && userChoice <= menuSize));

    return userChoice;
  }

  Menu() {}
  static Menu *MenuInstance;
  ~Menu() { delete MenuInstance; }
  Menu(const Menu &) = delete;
  void operator=(const Menu &) = delete;

public:
  static Menu *Get() {
    if (MenuInstance == nullptr)
      MenuInstance = new Menu();
    return MenuInstance;
  }

  // printers
  void PrintDefalutMenu() const { Print(defaultMenu); }
  void PrintCustomerMenu() const { Print(customerMenu); }
  void PrintAdminMenu() const { Print(adminMenu); }

  int ReadDefaultChoice() const { return readMenuChoice(defaultMenu.size()); }
  int ReadCustomerChoice() const { return readMenuChoice(customerMenu.size()); }
  int ReadAdminChoice() const { return readMenuChoice(adminMenu.size()); }
};
///////////////////////////////////////////////
///
///////////////////////////////////////////////

Menu *Menu::MenuInstance = nullptr;

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class Book {
private:
  std::string ISBN;
  std::string title;
  std::string authorName;
  std::vector<std::string> pages;

public:
  Book() {}
  Book(const std::string &line) {
    std::vector<std::string> RawData;
    RawData = SplitLine(line);
    ISBN = RawData[0];
    title = RawData[1];
    authorName = RawData[2];

    int RawDataSize = RawData.size();
    for (int i = 3; i < RawDataSize; ++i)
      pages.push_back(RawData[i]);
  }
  // Getters
  const std::string &getTitle() const { return title; }
  const std::string &getISBN() const { return ISBN; }
  const std::string &getAuthorName() const { return authorName; }
  const std::vector<std::string> &getPages() const { return pages; }

  // setters
  void setISBN(const std::string ISBN) { this->ISBN = ISBN; }
  void setTitle(const std::string title) { this->title = title; }
  void setAuthorName(const std::string authorName) {
    this->authorName = authorName;
  }
  void setPages(const std::vector<std::string> &pages) { this->pages = pages; }

  std::string toStr() const {
    std::string bookInfo{ISBN + delimter + title + delimter + authorName};

    for (const auto &page : pages)
      bookInfo += {delimter + page};

    return bookInfo;
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////
class viewer {
  // its logic is simple take the given session and printed it out with the
  // viewer controller whcih it implementation is really simple
};
///////////////////////////////////////////////
///
///////////////////////////////////////////////

class User {
private:
  std::string userName;
  std::string password;
  std::string name;
  std::string email;
  // make the user type string if there more than two types of users
  std::string userType;

  // this should be just for the customer which should inhererate from the
  // parent class User
  std::vector<ReadingSession> readingSessions;

public:
  User() : userType("None") {}

  User(const std::string &line) {
    std::vector<std::string> RawData;
    RawData = SplitLine(line);
    userName = RawData[0];
    password = RawData[1];
    name = RawData[2];
    email = RawData[3];
    userType = RawData[4];

    if (userType == "Customer") {
      int RawDataSize = RawData.size();
      std::vector<std::string> UserReadingSessions;
      for (int i = 5; i < RawDataSize;) {
        UserReadingSessions.clear();
        UserReadingSessions.push_back(RawData[i]);   // book title
        UserReadingSessions.push_back(RawData[++i]); // current book page
        UserReadingSessions.push_back(RawData[++i]); // book pages
        UserReadingSessions.push_back(RawData[++i]); // date and time

        ReadingSession newReadingSession(UserReadingSessions);
        readingSessions.push_back(newReadingSession);
      }
    }
  }

  // Getters
  std::string getUserName() const { return userName; }
  std::string getName() const { return name; }
  std::string getEmail() const { return email; }
  std::string getPassword() const { return password; }
  std::string getUserType() const { return userType; }
  const std::vector<ReadingSession> &getReadingSessions() const {
    return readingSessions;
  }

  // Setters
  void setUserName(const std::string &userName) { this->userName = userName; }
  void setPassword(const std::string &password) { this->password = password; }
  void setName(const std::string &name) { this->name = name; }
  void setEmail(const std::string &email) { this->email = email; }
  void setUsetType(const std::string &userType) { this->userType = userType; }

  std::string toStr() const {
    return userName + delimter + password + delimter + name + delimter + email +
           delimter + userType;
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class BooksManager {
private:
  std::map<std::string, Book> BooksMap;

  void LoadBooks() {
    std::vector<std::string> RawDataInLines;
    ReadFileToMemory("books.txt", RawDataInLines);
    BooksMap.clear();
    for (const auto &line : RawDataInLines) {
      Book NewBook(line);
      BooksMap[NewBook.getTitle()] = NewBook;
    }
  }

  void AddBookToDataBase(const Book &AddedBook) {
    std::vector<std::string> RawDataBooks;
    RawDataBooks.push_back(AddedBook.toStr());
    WriteFile("books.txt", RawDataBooks);
  }

  void UpdateDataBase() {
    std::vector<std::string> RawDataBooks;
    for (auto const &bookTitle : BooksMap) {
      const Book &book = bookTitle.second;
      RawDataBooks.push_back(book.toStr());
    }
    WriteFile("books.txt", RawDataBooks, false);
  }

public:
  BooksManager() { LoadBooks(); }

  void addBook() {
    std::string bookInpput;
    Book newBook;

    // we always user cin.ignore() after cin >> something

    std::cout << "Enter ISBN: ";
    std::cin >> bookInpput;
    std::cin.ignore();
    newBook.setISBN(bookInpput);

    do {
      std::cout << "Enter Title: ";
      std::getline(std::cin, bookInpput, '\n');

      if (BooksMap.count(bookInpput))
        std::cout << "There already a book with the same title." << std::endl;

    } while (BooksMap.count(bookInpput));
    newBook.setTitle(bookInpput);

    std::cout << "Enter Author Name: ";
    std::getline(std::cin, bookInpput, '\n');
    newBook.setAuthorName(bookInpput);

    int bookPages;
    do {
      std::cout << "Enter How many pages: ";
      std::cin >> bookInpput;
      std::cin.ignore();
      bookPages = strToInt(bookInpput);

      if (bookPages <= 0)
        std::cout << "Please Enter Valid number of book pages." << std::endl;
    } while (bookPages <= 0);

    std::vector<std::string> bookPagesText;
    for (int i = 0; i < bookPages; ++i) {
      std::cout << "Enter page # " << i + 1 << ": ";
      std::getline(std::cin, bookInpput, '\n');
      bookPagesText.push_back(bookInpput);
    }
    newBook.setPages(bookPagesText);

    BooksMap[newBook.getTitle()] = newBook;
    AddBookToDataBase(newBook);
  }

  void showAvilableBooks() const {
    std::cout << "\nOur Current book collection: " << std::endl;
    int i = 1;
    for (const auto &book : BooksMap)
      std::cout << i++ << book.first << std::endl;
  }

  int readBookNumber() const {
    std::string userChoiceStr;
    int userChoice;
    int booksMapSize = BooksMap.size();

    do {
      std::cout << "Which book to read?: " << std::endl;
      std::cout << "Enter number in range 1 - " << booksMapSize << ": ";
      std::cin >> userChoiceStr;
      userChoice = strToInt(userChoiceStr);
      if (!(1 <= userChoice && userChoice >= booksMapSize))
        std::cout << "Invalid choice... Try again!" << std::endl;
    } while (!(1 <= userChoice && userChoice >= booksMapSize));

    return userChoice;
  }

  const Book &GetChosenBook(const int userChoice) const {
    auto bookIterator = BooksMap.begin();
    std::advance(bookIterator, userChoice - 1);

    if (bookIterator != BooksMap.end())
      return bookIterator->second;
    else
      throw std::runtime_error("Invalid book choice.");
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class AdminUser {
private:
  User admin;
  BooksManager booksManager;

public:
  User getUser() const { return admin; }

  void addBook() { booksManager.addBook(); }

  void ViewProfile() {
    std::cout << "Name: " << admin.getName() << std::endl;
    std::cout << "Email: " << admin.getEmail() << std::endl;
    std::cout << "User name: " << admin.getUserName() << std::endl;
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class CustomerUser {
private:
  User customer;
  BooksManager booksManager;
  std::vector<ReadingSession> readingSessions;

public:
  CustomerUser() { readingSessions = customer.getReadingSessions(); }
  void ViewProfile() {
    std::cout << "Name: " << customer.getName() << std::endl;
    std::cout << "Email: " << customer.getEmail() << std::endl;
    std::cout << "User name: " << customer.getUserName() << std::endl;
  }

  void ListSelectFromAvilableBoos() {
    // not working because it will require more time to make it work with files
    booksManager.showAvilableBooks();
    int userChoice = booksManager.readBookNumber();
    const Book &selectedBook = booksManager.GetChosenBook(userChoice);
    ReadingSession newReadingSession();
    viewer(newReadingSession);
  }

  void ListSelectFromReadingSessions() {
    ListReadingSessions();
    ReadingSession selectedReadingSession = readChossenSession();
    viewer(selectedReadingSession);
  }

  void ListReadingSessions() {
    int sessionsSize = readingSessions.size();
    for (int i = 0; i < sessionsSize; ++i) {
      std::cout << "\n" << i + 1 << "; ";
      readingSessions[i].Print();
      std::cout << std::endl;
    }
  }

  const ReadingSession &readChossenSession() {
    std::cout << "Which session to open?: " << std::endl;

    std::string userChoiceStr;
    int userChoice;
    int sessionsNumber = readingSessions.size();
    do {
      std::cout << "Enter number in range 1 - " << sessionsNumber << ": ";
      std::cin >> userChoiceStr;
      userChoice = strToInt(userChoiceStr);

      if (!(1 <= userChoice && userChoice <= sessionsNumber))
        std::cout << "Invalid Choice... Try again.";
    } while (!(1 <= userChoice && userChoice <= sessionsNumber));

    return readingSessions[userChoice - 1];
  }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////

class UsersManager {
private:
  // AdminsManager adminsManager;
  // CustomersManager customersManager;
  AdminUser adminUser;
  CustomerUser customerUser;
  std::map<std::string, User> UsersMap;
  Menu *MenuPtr = Menu::Get();
  User currentUser;

  void LoadUsers() {
    std::vector<std::string> RawDataInLines;
    ReadFileToMemory("users.txt", RawDataInLines);
    UsersMap.clear();
    for (const auto &line : RawDataInLines) {
      User NewUser(line);
      UsersMap[NewUser.getUserName()] = NewUser;
    }
  }

  void PrintWelcomeMessage(const User &currentUser) {
    std::cout << "\nHello " << currentUser.getUserName() << " | "
              << currentUser.getUserType() << " View";
  }

  void UpdateDataBase() {
    std::vector<std::string> RawDataUsers;
    for (auto const &username : UsersMap) {
      const User &user = username.second;
      RawDataUsers.push_back(user.toStr());
    }
    WriteFile("users.txt", RawDataUsers, false);
  }

  void AddUserToDataBase(const User &AddedUser) {
    std::vector<std::string> RawDataUsers;
    RawDataUsers.push_back(AddedUser.toStr());
    WriteFile("users.txt", RawDataUsers);
  }

public:
  UsersManager() { LoadUsers(); }

  void AttempToLogIn() {
    LoadUsers();
    std::string username, password;

    do {
      std::cout << "Enter user name (no spaces): ";
      std::cin >> username;
      std::cout << "Enter password (nospaces): ";
      std::cin >> password;

      if (!(UsersMap.count(username) &&
            UsersMap[username].getPassword() == password))
        std::cout << "Invalid user name or password...Please Try again."
                  << std::endl;

    } while (!(UsersMap.count(username) &&
               UsersMap[username].getPassword() == password));

    currentUser = UsersMap[username];
    PrintWelcomeMessage(currentUser);
  }

  void CreateCustomerAccount() {
    std::string userInput;
    User newCustomerUser;

    do {
      std::cout << "Enter user name (No spaces): ";
      std::cin >> userInput;

      if (UsersMap.count(userInput))
        std::cout << "This User name is already taken...Try another one."
                  << std::endl;
    } while (UsersMap.count(userInput));
    newCustomerUser.setUserName(userInput);

    std::cout << "Enter password (No spaces): ";
    std::cin >> userInput;
    newCustomerUser.setPassword(userInput);

    std::cout << "Enter name (No sppaces): ";
    std::cin >> userInput;
    newCustomerUser.setName(userInput);

    std::cout << "Enter email (No spaces): ";
    std::cin >> userInput;
    newCustomerUser.setEmail(userInput);

    newCustomerUser.setUsetType("Customer");

    currentUser = newCustomerUser;
    UsersMap[currentUser.getUserName()] = currentUser;
    AddUserToDataBase(currentUser);
    PrintWelcomeMessage(currentUser);
  }

  void Logout() { currentUser = User(); }
  User getCurrentUser() const { return currentUser; }
};

///////////////////////////////////////////////
///
///////////////////////////////////////////////
class onLineBookReaderSystem {
private:
  UsersManager usersManager;
  BooksManager booksManager;
  Menu *MenuPtr = Menu::Get();

  void accessSystem() {
    int userChoice;
    if (usersManager.getCurrentUser().getUserType() == "Admin") {
      AdminUser adminUser;
      MenuPtr->PrintAdminMenu();
      userChoice = MenuPtr->ReadAdminChoice();
      if (userChoice == 1)
        adminUser.ViewProfile();
      else if (userChoice == 2)
        adminUser.addBook();
      else
        usersManager.Logout();
    }
    /////////////////////////////////////////
    ///
    ////////////////////////////////////////
    else if (usersManager.getCurrentUser().getUserType() == "Customer") {
      CustomerUser customerUser;
      MenuPtr->PrintAdminMenu();
      userChoice = MenuPtr->ReadCustomerChoice();
      if (userChoice == 1)
        customerUser.ViewProfile();
      else if (userChoice == 2)
        customerUser.ListSelectFromReadingSessions();
      else if (userChoice == 3) {
        customerUser.ListSelectFromReadingSessions();
      } else
        usersManager.Logout();
    }
    /////////////////////////////////////////
    ///
    ////////////////////////////////////////
    else {
      MenuPtr->PrintDefalutMenu();
      userChoice = MenuPtr->ReadDefaultChoice();
      if (userChoice == 1)
        usersManager.AttempToLogIn();
      else
        usersManager.CreateCustomerAccount();
    }
  }

public:
  void run() {
    while (true) {
      accessSystem();
    }
  }
};
int main(int argc, char *argv[]) {
  onLineBookReaderSystem service;
  service.run();
  return 0;
}
