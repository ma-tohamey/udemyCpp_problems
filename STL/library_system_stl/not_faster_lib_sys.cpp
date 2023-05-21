#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////

struct book {
  // book_id, book_name, total_borrowed, total_quantity;
  string name;
  int id, total_borrowed, total_quantity;
  book &operator[](int id) { return *this; }

  book() { total_borrowed = total_quantity = 0; }

  book(int _id, string _name, int _quantity, int _borrowed) {
    id = _id;
    name = _name;
    total_quantity = _quantity;
    total_borrowed = _borrowed;
  }

  /////////////////////////////////////////////////////////

  void read() {
    string name;
    cout << "Enter your book info: id & name & total quantity: ";
    cin >> id >> name >> total_quantity;
  };

  /////////////////////////////////////////////////////////

  bool is_prefix(string prefix) {
    int prefix_size = prefix.size();
    for (int i = 0; i < prefix_size; i++)
      if (name[i] != prefix[i])
        return false;
    return true;
  }

  /////////////////////////////////////////////////////////

  void borrow_copy() {
    if (total_quantity > total_borrowed) {
      cout << "you can't borrow this book there is no copy for you.\n";
      return;
    }
    total_borrowed++;
    return;
  };

  /////////////////////////////////////////////////////////

  void return_copy() { total_borrowed--; }

  /////////////////////////////////////////////////////////

  void print() {
    cout << "id = " << id << " name = " << name << " total_quantity "
         << total_quantity << " total_borrowed " << total_borrowed << endl;
  }
};

/////////////////////////////////////////////////////////

struct user {
  int id;
  string name;
  set<int> borrowed_books;
  user &operator[](int id) { return *this; }

  user() {}

  user(string _name, int _id) {
    id = _id;
    name = _name;
  }

  /////////////////////////////////////////////////////////

  void read() {
    cout << "Enter your name & notion id ";
    cin >> name >> id;
  }

  /////////////////////////////////////////////////////////

  bool is_borrowed(int book_id) { return borrowed_books.count(book_id); }

  /////////////////////////////////////////////////////////

  void borrow_book(int book_id) {
    if (borrowed_books.count(book_id)) {
      cout << name
           << " already have a copy of this book you can't borrow book "
              "twice.\n";
      return;
    }

    borrowed_books.insert(book_id);
  }

  /////////////////////////////////////////////////////////

  void return_copy(int book_id) {
    if (is_borrowed(book_id))
      borrowed_books.erase(book_id);
    else
      cout << name
           << " doesn't have copy of this book you can't return a book you "
              "didn't borrow it in the first place.\n";
  }

  /////////////////////////////////////////////////////////

  void print() {
    cout << "user " << name << " id " << id << " borrowed books ids: ";

    for (int cnt_book_id : borrowed_books)
      cout << cnt_book_id << ' ';
    cout << endl;
  }
};

/////////////////////////////////////////////////////////

// bool compare_books_by_name(book &a, book &b) {
//   return get<0>(a.book_info[a.id]) < get<0>(a.book_info[a.id]);
// }
// bool compare_books_by_name(book &a, book &b) {
//   return get<0>(a[a.id]) < get<0>(a[a.id]);
// }
// bool compare_books_by_name(book &a, book &b) { return a.name < b.name; }

/////////////////////////////////////////////////////////

struct library_system {
  set<int> books;
  set<int> users;
  int total_books, total_users;

  library_system() {
    total_books = books.size();
    total_users = users.size();
  }

  ////////////////////////////////////////////////////////

  int is_user(string user_name) {
    user target_user;
    for (int user_id : users)
      if (target_user[user_id].name == user_name)
        return user_id;
    return -1;
  }

  int is_book(string book_name) {
    book target_book;
    for (int book_id : books)
      if (target_book[book_id].name == book_name)
        return book_id;
    return -1;
  }

  ///////////////////////////////////////////////////////

  void add_book() {
    book new_book;
    new_book.read();
    books.insert(new_book.id);
  }

  /////////////////////////////////////////////////////////

  void search_books_by_prefix() {
    string prefix;
    cout << "Enter book name prefix: ";
    cin >> prefix;
    bool is_exist = false;

    for (int book_id : books) {
      book cnt_book;
      if (cnt_book[book_id].is_prefix(prefix)) {
        is_exist = true;
        cout << cnt_book.name << endl;
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

    bool borrowed_book = false;

    for (int user_id : users) {
      user cnt_user[user_id];
      if (cnt_user->borrowed_books.count(book_id)) {
        borrowed_book = true;
        cout << cnt_user[user_id].name << endl;
      }
    }

    if (!borrowed_book)
      cout << "there is no user borrowed this book yet.\n";
  }

  ////////////////////////////////////////////////////////

  void print_library_by_id() {
    cout << "\nThe whole library sorted by book id:\n";

    for (int book_id : books) {
      book cnt_book[book_id];
      cnt_book[book_id].print();
    }
    cout << endl;
  }

  /////////////////////////////////////////////////////////

  void print_library_by_name() {
    cout << "\nThe whole library sorted by book name:\n";
    // sort(books.begin(), books.end(), compare_books_by_name);

    for (int book_id : books) {
      book cnt_book[book_id];
      cnt_book[book_id].print();
    }
    cout << endl;
  }

  /////////////////////////////////////////////////////////

  void add_user() {
    user new_user;
    new_user.read();
    users.insert(new_user.id);
  }

  /////////////////////////////////////////////////////////

  void user_borrow_book() {
    string borrower, book_name;
    cout << "Enter user name and book name: ";
    cin >> borrower >> book_name;

    int user_id = is_user(borrower);
    int book_id = is_book(book_name);

    if (user_id != -1 && book_id != -1) {
      book target_book;
      user target_user;
      target_book[book_id].borrow_copy();
      target_user[user_id].borrow_book(book_id);
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
      book target_book;
      user target_user;
      target_book.return_copy();
      target_user.return_copy(book_id);
    } else
      cout << "make sure that your name and the book name is right.\n";
  }

  ///////////////////////////////////////////////////////////////

  void print_users() {
    for (int user_id : users) {
      user target_user;
      target_user[user_id].print();
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
