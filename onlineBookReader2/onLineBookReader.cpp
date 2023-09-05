#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int strToInt(std::string &numberStr) {
  int number;
  std::istringstream iss(numberStr);
  iss >> number;
  return number;
}

int getUserInput(int maxNumber) {
  std::string userInputStr;
  int userInput;

  do {
    std::cout << "Enter number in range 1 - " << maxNumber << ": ";
    std::cin >> userInputStr;
    userInput = strToInt(userInputStr);

    if (!(1 <= userInput && userInput <= maxNumber))
      std::cout << "Error: Invalid number...Try again.\n";
  } while (!(1 <= userInput && userInput <= maxNumber));
  return userInput;
}

std::string GetCurrentTimeDate() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
  return ss.str();
}

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class UI {
private:
  std::vector<std::string> defaultMenu{"Login", "Sign Up"};
  std::vector<std::string> adminMenu{"View Profile", "Add Book", "Logout"};
  std::vector<std::string> customerMenu{
      "View Profile", "List & Select from My Reading History",
      "List & Select from Available Books", "Logout"};
  std::vector<std::string> bookViewerMenu{"Next Page", "Previous Page",
                                          "Stop Reading"};

  UI() {}
  static UI ui_instance;

public:
  static UI &getUI() { return ui_instance; }
  void printDefalut() {
    int menuSize = defaultMenu.size();
    std::cout << "\nMenu:";
    for (int i = 0; i < menuSize; ++i)
      std::cout << "\n\t" << i + 1 << ": " << defaultMenu[i];
    std::cout << std::endl;
  }

  void printCustomer() {
    int menuSize = customerMenu.size();
    std::cout << "\nMenu:";
    for (int i = 0; i < menuSize; ++i)
      std::cout << "\n\t" << i + 1 << ": " << customerMenu[i];
    std::cout << std::endl;
  }

  void printAdmin() {
    int menuSize = adminMenu.size();
    std::cout << "\nMenu:";
    for (int i = 0; i < menuSize; ++i)
      std::cout << "\n\t" << i + 1 << ": " << adminMenu[i];
    std::cout << std::endl;
  }

  void printBookViewer() {
    int menuSize = bookViewerMenu.size();
    std::cout << "\nMenu:";
    for (int i = 0; i < menuSize; ++i)
      std::cout << "\n\t" << i + 1 << ": " << bookViewerMenu[i];
    std::cout << std::endl;
  }

  const int getDefaultMenuSize() const { return defaultMenu.size(); }
  const int getCustomerMenuSize() const { return customerMenu.size(); }
  const int getAdminMenuSize() const { return adminMenu.size(); }
  const int getBookViewerMenuSize() const { return bookViewerMenu.size(); }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

UI UI::ui_instance;

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class Book {
private:
  std::string ISBN;
  std::string title;
  std::string authorName;
  std::vector<std::string> pages;

public:
  Book() {}

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
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class ReadingSession {
private:
  Book *book;
  int currentPage;
  std::string lastAccessInfo;

public:
  ReadingSession(Book *book)
      : book(book), currentPage(0), lastAccessInfo(GetCurrentTimeDate()){};

  // getters
  int getCurrentPage() const { return currentPage + 1; }
  int getBookPages() const { return book->getPages().size(); }
  std::string getCurrentPageContent() const {
    return book->getPages()[currentPage];
  }

  const Book &getBook() const { return *book; }

  void NextPage() {
    if (currentPage < book->getPages().size() - 1)
      ++currentPage;
  }

  void PreviousPage() {
    if (currentPage > 0)
      --currentPage;
  }

  void updateLastAccessDate() { lastAccessInfo = GetCurrentTimeDate(); }

  void print() const {
    std::cout << book->getTitle() << " Page: " << currentPage + 1 << "/"
              << book->getPages().size() << " - " << lastAccessInfo
              << std::endl;
  }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class BooksManager {
private:
  std::map<std::string, Book> booksMap;

public:
  BooksManager() {
    Book defaultBook;
    std::vector<std::string> defaultBookPages{
        "hi from first page", "what is the weather like today",
        "sunny, wow! nice weather to start my work", "bey..."};
    defaultBook.setAuthorName("me");
    defaultBook.setISBN("91823741");
    defaultBook.setPages(defaultBookPages);
    defaultBook.setTitle("cpp how to program");
    booksMap[defaultBook.getTitle()] = defaultBook;
  }
  Book *getBook(const std::string &bookName) { return &booksMap[bookName]; }
  int getBooksMapSize() const { return booksMap.size(); }

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

      if (booksMap.count(bookInpput))
        std::cout << "There already a book with the same title." << std::endl;

    } while (booksMap.count(bookInpput));
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
    booksMap[newBook.getTitle()] = newBook;
  }

  void showAvilableBooks() const {
    std::cout << "\nOur Current book collection: " << std::endl;
    int i = 1;
    for (const auto &book : booksMap)
      std::cout << "\t" << i++ << " " << book.first << std::endl;
  }

  const std::string chooseABook() {
    std::cout << "\nwhich book to read?:" << std::endl;
    int userChoice = getUserInput(booksMap.size());

    int i = 0;
    for (auto &pair : booksMap) {
      if (++i == userChoice) {
        return pair.first;
      }
    }
    return "";
  }

  void sessionViewer(ReadingSession *readingSession) {
    while (true) {
      std::cout << "Current Page: " << readingSession->getCurrentPage() << "/"
                << readingSession->getBookPages();

      std::cout << "\n" << readingSession->getCurrentPageContent() << std::endl;

      UI::getUI().printBookViewer();
      int userChoice = getUserInput(UI::getUI().getBookViewerMenuSize());

      if (userChoice == 1)
        readingSession->NextPage();
      else if (userChoice == 2)
        readingSession->PreviousPage();
      else if (userChoice == 3)
        break;

      readingSession->updateLastAccessDate();
    }
  }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class User {
private:
  std::string userName;
  std::string password;
  std::string name;
  std::string email;
  bool isAdmin;
  std::vector<ReadingSession *> userReadingSessions;

public:
  User() { isAdmin = false; };

  // getters
  std::string getUserName() const { return userName; }
  std::string getName() const { return name; }
  std::string getEmail() const { return email; }
  std::string getPassword() const { return password; }
  bool getIsAdmin() const { return isAdmin; }
  std::vector<ReadingSession *> &getReadingSession() {
    return userReadingSessions;
  }

  // make getters and setters for reading sessions

  // Setters
  void setUserName(const std::string &userName) { this->userName = userName; }
  void setPassword(const std::string &password) { this->password = password; }
  void setName(const std::string &name) { this->name = name; }
  void setEmail(const std::string &email) { this->email = email; }
  void setIsAdmin(const bool isAdmin) { this->isAdmin = isAdmin; }
  void addNewReadingSession(ReadingSession *newReadingSession) {
    userReadingSessions.push_back(newReadingSession);
  }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class AdminManager {
private:
  User &currentUser;
  BooksManager &booksManger;

public:
  AdminManager(User &currentUser, BooksManager &booksManger)
      : currentUser(currentUser), booksManger(booksManger) {}

  void viewProfile() {
    std::cout << "Name: " << currentUser.getName() << std::endl;
    std::cout << "Email: " << currentUser.getEmail() << std::endl;
    std::cout << "User name: " << currentUser.getUserName() << std::endl;
  }

  void addBook() { booksManger.addBook(); }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class CustomerManager {
private:
  User &currentUser;
  BooksManager &booksMaanger;

public:
  CustomerManager(User &currentUser, BooksManager &booksManager)
      : currentUser(currentUser), booksMaanger(booksManager) {}

  ~CustomerManager() {
    for (auto session : currentUser.getReadingSession())
      delete session;
  }

  void viewProfile() {
    std::cout << "Name: " << currentUser.getName() << std::endl;
    std::cout << "Email: " << currentUser.getEmail() << std::endl;
    std::cout << "User name: " << currentUser.getUserName() << std::endl;
  }

  void listSelectReadingHistory() {
    if (currentUser.getReadingSession().size() < 1) {
      std::cout << "\tThere are no reading session made!\n";
      return;
    }

    int i = 0;
    for (const auto &session : currentUser.getReadingSession()) {
      std::cout << ++i << ": ";
      session->print();
    }
    int userChoice = getUserInput(i);
    booksMaanger.sessionViewer(currentUser.getReadingSession()[--userChoice]);
  }

  void listSelectAvailableBooks() {
    if (booksMaanger.getBooksMapSize() < 1) {
      std::cout << "\tSorry...but there stil no books till this momment. Try "
                   "again Later (:\n";
      return;
    }

    booksMaanger.showAvilableBooks();
    ReadingSession *newReadingSession =
        new ReadingSession(booksMaanger.getBook(booksMaanger.chooseABook()));

    // ReadingSession newReadingSession( // /// //// this isn't going to work
    // because it makes a temporary object then destoryed after getting out of
    // this function so to keep the reading session in memory (use daynamic
    // memory allocation)
    //     booksMaanger.getBook(booksMaanger.chooseABook()));

    booksMaanger.sessionViewer(newReadingSession);
    currentUser.addNewReadingSession(newReadingSession);
  }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class UsersManager {
private:
  User *currentUser;
  std::map<std::string, User> usersMap;

public:
  UsersManager() {
    User adminUser;
    adminUser.setUserName("admin");
    adminUser.setIsAdmin(true);
    adminUser.setName("mahmoud");
    adminUser.setEmail("mahmoud@gmail.com");
    adminUser.setPassword("mahmoud992");
    usersMap[adminUser.getUserName()] = adminUser;

    User customerUser;
    customerUser.setUserName("ramy");
    customerUser.setName("ramy");
    customerUser.setEmail("ramy@gmail.com");
    customerUser.setPassword("ramy");
    usersMap[customerUser.getUserName()] = customerUser;
  }

  void PrintWelcomeMessage(const User *currentUser) {
    std::cout << "\nHello " << currentUser->getUserName() << " | "
              << (currentUser->getIsAdmin() ? "Admin" : "User") << " View";
  }

  void DoLogin() {
    std::string username, password;

    do {
      std::cout << "Enter user name (no spaces): ";
      std::cin >> username;
      std::cout << "Enter password (nospaces): ";
      std::cin >> password;

      if (!(usersMap.count(username) &&
            usersMap[username].getPassword() == password))
        std::cout << "Invalid user name or password...Please Try again."
                  << std::endl;

    } while (!(usersMap.count(username) &&
               usersMap[username].getPassword() == password));

    currentUser = new User;
    *currentUser = usersMap[username];
    PrintWelcomeMessage(currentUser);
  }

  void DoSignUp() {
    std::string userInput;
    currentUser = new User;

    do {
      std::cout << "Enter user name (No spaces): ";
      std::cin >> userInput;

      if (usersMap.count(userInput))
        std::cout << "This User name is already taken...Try another one."
                  << std::endl;
    } while (usersMap.count(userInput));
    currentUser->setUserName(userInput);

    std::cout << "Enter password (No spaces): ";
    std::cin >> userInput;
    currentUser->setPassword(userInput);

    std::cout << "Enter name (No sppaces): ";
    std::cin >> userInput;
    currentUser->setName(userInput);

    std::cout << "Enter email (No spaces): ";
    std::cin >> userInput;
    currentUser->setEmail(userInput);

    usersMap[currentUser->getUserName()] = *currentUser;
    PrintWelcomeMessage(currentUser);
  }

  bool IsAdmin() const { return currentUser->getIsAdmin(); }

  void adminsController(BooksManager *booksManager) {
    AdminManager adminManager(*currentUser, *booksManager);
    while (true) {
      UI::getUI().printAdmin();
      int userChoice = getUserInput(UI::getUI().getAdminMenuSize());

      if (userChoice == 1)
        adminManager.viewProfile();
      else if (userChoice == 2)
        adminManager.addBook();
      else if (userChoice == 3) {
        delete currentUser;
        break;
      }
    }
  }

  void customerController(BooksManager *booksManger) {
    CustomerManager customerManager(*currentUser, *booksManger);
    while (true) {
      UI::getUI().printCustomer();
      int userChoice = getUserInput(UI::getUI().getCustomerMenuSize());

      if (userChoice == 1)
        customerManager.viewProfile();
      else if (userChoice == 2)
        customerManager.listSelectReadingHistory();
      else if (userChoice == 3)
        customerManager.listSelectAvailableBooks();
      else if (userChoice == 4) {
        delete currentUser;
        break;
      }
    }
  }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

class OnLineBookReaderSystem {
private:
  UsersManager *usersManager;
  BooksManager *booksManager;

  void accessSystem() {
    UI::getUI().printDefalut();
    int userChoice = getUserInput(UI::getUI().getDefaultMenuSize());

    if (userChoice == 1)
      usersManager->DoLogin();
    else if (userChoice == 2)
      usersManager->DoSignUp();
  }

public:
  OnLineBookReaderSystem()
      : usersManager(new UsersManager), booksManager(new BooksManager) {}

  ~OnLineBookReaderSystem() {
    delete usersManager;
    delete booksManager;
  }
  void run() {
    while (true) {
      accessSystem();

      if (usersManager->IsAdmin())
        usersManager->adminsController(booksManager);
      else
        usersManager->customerController(booksManager);
    }
  }
};

//////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
  OnLineBookReaderSystem system;
  system.run();
  return 0;
}
