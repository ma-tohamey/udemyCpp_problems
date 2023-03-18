#include <algorithm>
#include <iostream>
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
  int id, len = 0;
  string name;
  book borrowed_books[MAX_BORROWED];

  user() {}

  user(string _name, int _id) {
    id = _id;
    name = _name;
  }

  void read() {
    cout << "Enter your name & nationa id: ";
    cin >> name >> id;
  }

  bool is_borrowed(string book_name) {
    for (int i = 0; i < len; i++) {
      if (borrowed_books[i].name == book_name) {
        return true;
      }
    }
    return false;
  }

  void borrow_book(book borrowed_book) {
    for (int i = 0; i < len; i++)
      if (borrowed_books[i].name == borrowed_book.name) {
        cout << name
             << " already have a copy of this book you can't borrow book "
                "twice.\n";
        return;
      }

    borrowed_books[len] = borrowed_book;
    ++len;
  }

  void rearange_user_borrowed_books() {
    for (int i = 0; i < len; i++) {
      borrowed_books[i] = borrowed_books[i + 1];
    }
  }

  void return_copy(book returned_book) {
    bool is_borrowed = false;
    for (int i = 0; i < len; i++)
      if (borrowed_books[i].name == returned_book.name) {
        is_borrowed = true;
        rearange_user_borrowed_books();
        len--;
        break;
      }

    if (!is_borrowed) {
      cout << name
           << " doesn't have copy of this book you can't return a book you "
              "didn't borrow it in the first place.\n";
    }
  }

  void print() {
    cout << "user " << name << " id " << id << " borrowed books ids: ";

    for (int i = 0; i < len; i++) {
      int book_id = borrowed_books[i].id;
      cout << book_id << " ";
    }
    cout << endl;
  }
};

bool compare_books_by_id(book &a, book &b) { return a.id < b.id; }
bool compare_books_by_name(book &a, book &b) { return a.name < b.name; }

struct library_system {
  book books[MAX_BOOKS];
  user users[MAX_USERS];
  int total_books, total_users;

  library_system() { total_books = total_users = 0; }

  ////////////////////////////////////////////////////////

  int is_user(string user_name) {
    for (int i = 0; i < total_users; i++)
      if (users[i].name == user_name)
        return i;
    return -1;
  }

  int is_book(string book_name) {
    for (int i = 0; i < total_books; i++)
      if (books[i].name == book_name)
        return i;
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

    if (is_book(book_name) == -1) {
      cout << "Invalid book name.\n";
      return;
    }

    bool user_borrowed_thebook = false;

    for (int i = 0; i < total_users; i++) {
      if (users[i].is_borrowed(book_name)) {
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
    sort(books, books + total_books, compare_books_by_id);

    for (int i = 0; i < total_books; i++) {
      books[i].print();
    }
    cout << endl;
  }

  void print_library_by_name() {
    cout << "\nThe whole library sorted by book name:\n";
    sort(books, books + total_books, compare_books_by_name);

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

    int user_idx = is_user(borrower);
    int book_idx = is_book(book_name);

    if (user_idx != -1 && book_idx != -1) {
      books[book_idx].borrow_copy();
      users[user_idx].borrow_book(books[book_idx]);
    } else
      cout << "make sure that your name and the book name is right.\n";
  }

  //////////////////////////////////////////////////////////

  void user_return_book() {
    string returner, book_name;
    cout << "Enter user name and book name: ";
    cin >> returner >> book_name;

    int user_idx = is_user(returner);
    int book_idx = is_book(book_name);

    if (user_idx != -1 && book_idx != -1) {
      books[book_idx].return_copy();
      users[user_idx].return_copy(books[book_idx]);
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
