#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
using namespace std;

const int MAX_BOOKS = 1000;
const int MAX_BORROWED = 21;
const int MAX_USERS = 101;

struct book {
  int id, total_quantity, total_borrowed;
  string name;

  book() { total_borrowed = total_quantity = 0; }

  book(int _id, string _name, int _quantity, int _borrowed) {
    id = _id;
    name = _name;
    total_quantity = _quantity;
    total_borrowed = _borrowed;
  }

  void read() {
    cout << "Enter your book info: id & name & total quantity: ";
    cin >> id >> name >> total_quantity;
    total_borrowed = 0;
  };

  bool is_prefix(string prefix) {
    int prefix_size = prefix.size();
    for (int i = 0; i < prefix_size; i++)
      if (name[i] != prefix[i])
        return false;
    return true;
  }

  void borrow_copy() {
    if (total_quantity - total_borrowed == 0) {
      cout << "you can't borrow this book there is no copy for you.\n";
      return;
    }
    total_borrowed++;
    return;
  };

  void return_copy() {
    if (total_borrowed > 0)
      total_borrowed--;
  }

  void print() {
    cout << "id = " << id << " name = " << name << " total_quantity "
         << total_quantity << " total_borrowed " << total_borrowed << endl;
  }
};

struct user {
  int id, n_borrowed_books;
  string name;

  set<int> borrowed_books_id;

  user(){};

  user(string _name, int _id) {
    id = _id;
    name = _name;
    n_borrowed_books = borrowed_books_id.size();
  }

  void read() {
    cout << "Enter your name & nationa id: ";
    cin >> name >> id;
  }

  bool is_borrowed(int book_id) {
    auto it = borrowed_books_id.find(book_id);
    return it != borrowed_books_id.end();
  }

  void borrow_book(int book_id) {
    if (is_borrowed(book_id)) {
      cout << name
           << " already have a copy of this book you can't borrow book "
              "twice.\n";
      return;
    }

    borrowed_books_id.insert(book_id);
  }

  void return_copy(int book_id) {
    if (is_borrowed(book_id)) {
      auto it = borrowed_books_id.find(book_id);
      borrowed_books_id.erase(it);
    } else {
      cout << name
           << " doesn't have copy of this book you can't return a book you "
              "didn't borrow it in the first place.\n";
    }
  }

  void print() {
    cout << "user " << name << " id " << id << " borrowed books ids: ";
    for (int book_id : borrowed_books_id)
      cout << book_id << " ";
    cout << endl;
  }
};

bool compare_books_by_id(book &a, book &b) { return a.id < b.id; }
bool compare_books_by_name(book &a, book &b) { return a.name < b.name; }

struct library_system {
  vector<book> books;
  vector<user> users;
  int total_books, total_users;

  library_system() {
    total_books = books.size();
    total_users = users.size();
  }

  ////////////////////////////////////////////////////////

  int is_user(string user_name) {
    for (user cnt_user : users)
      if (cnt_user.name == user_name)
        return cnt_user.id;
    return -1;
  }

  int is_book(string book_name) {
    for (book cnt_book : books)
      if (cnt_book.name == book_name)
        return cnt_book.id;
    return -1;
  }

  ///////////////////////////////////////////////////////

  void add_book() { books[total_books++].read(); }

  void search_books_by_prefix() {
    string prefix;
    cout << "Enter book name prefix: ";
    cin >> prefix;
    bool is_exist = false;

    for (int i = 0; i < total_books; i++) {
      if (books[i].is_prefix(prefix)) {
        is_exist = true;
        cout << books[i].name << endl;
      }
    }

    if (!is_exist)
      cout << "No books with such prefix\n";

    cout << endl;
  }

  ////////////////////////////////////////////////////////

  void print_who_borrowed_book_by_name() {
    string book_name;
    cout << "Enter book name: ";
    cin >> book_name;

    int book_id = is_book(book_name);
    if (book_id == -1) {
      cout << "Invalid book name.\n";
      return;
    }

    bool user_borrowed_thebook = false;

    for (int i = 0; i < total_users; i++) {
      if (users[i].is_borrowed(book_id)) {
        user_borrowed_thebook = true;
        cout << users[i].name << endl;
      }
    }

    if (!user_borrowed_thebook)
      cout << "there is no user borrowed this book yet.\n";
  }

  ////////////////////////////////////////////////////////

  void print_library_by_id() {
    cout << "\nThe whole library sorted by book id:\n";
    sort(books.begin(), books.end(), compare_books_by_id);

    for (int i = 0; i < total_books; i++) {
      books[i].print();
    }
    cout << endl;
  }

  void print_library_by_name() {
    cout << "\nThe whole library sorted by book name:\n";
    sort(books.begin(), books.end(), compare_books_by_name);

    for (int i = 0; i < total_books; i++) {
      books[i].print();
    }
    cout << endl;
  }

  void add_user() { users[total_users++].read(); }

  /////////////////////////////////////////////////////////

  void user_borrow_book() {
    string borrower, book_name;
    cout << "Enter user name and book name: ";
    cin >> borrower >> book_name;

    int user_id = is_user(borrower);
    int book_id = is_book(book_name);

    if (user_id != -1 && book_id != -1) {
      books[book_id].borrow_copy();
      users[user_id].borrow_book(book_id);
    } else
      cout << "make sure that your name and the book name is right.\n";
  }

  //////////////////////////////////////////////////////////

  void user_return_book() {
    string returner, book_name;
    cout << "Enter user name and book name: ";
    cin >> returner >> book_name;

    int user_id = is_user(returner);
    int book_id = is_book(book_name);

    if (user_id != -1 && book_id != -1) {
      books[book_id].return_copy();
      users[user_id].return_copy(book_id);
    } else
      cout << "make sure that your name and the book name is right.\n";
  }

  ///////////////////////////////////////////////////////////////

  void print_users() {
    for (int i = 0; i < total_users; i++) {
      users[i].print();
    }
    cout << endl;
  }

  //////////////////////////////////////////////////////////////

  int menu() {
    int user_choice;
    cout << "Library Mneu:\n";
    cout << "1) add_book\n";
    cout << "2) search_books_by_prefix\n";
    cout << "3) print_who_borrowed_book_by_name\n";
    cout << "4) print_library_by_id\n";
    cout << "5) print_library_by_name\n";
    cout << "6) add_user\n";
    cout << "7) user_borrow_book\n";
    cout << "8) user_return_book\n";
    cout << "9) print_users\n";
    cout << "10) Exit\n";
    cout << "\nEnter your menu choice [1 - 10]: ";
    cin >> user_choice;
    return user_choice;
  }

  ///////////////////////////////////////////////////////////////

  void run() {
    while (true) {
      int user_choice = menu();

      if (user_choice > 10 || user_choice < 1)
        cout << "Invalid choice please try again.\n\n";
      else if (user_choice == 1)
        add_book();
      else if (user_choice == 2)
        search_books_by_prefix();
      else if (user_choice == 3)
        print_who_borrowed_book_by_name();
      else if (user_choice == 4)
        print_library_by_id();
      else if (user_choice == 5)
        print_library_by_name();
      else if (user_choice == 6)
        add_user();
      else if (user_choice == 7)
        user_borrow_book();
      else if (user_choice == 8)
        user_return_book();
      else if (user_choice == 9)
        print_users();
      else if (user_choice == 10)
        return;
    }
  }
};

int main(int argc, char *argv[]) {
  library_system lib;
  lib.run();
  return 0;
}
