#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_BOOKS = 1000;
const int MAX_BORROWED = 21;
const int MAX_USERS = 101;

struct book {
  int id, quantity, borrowed;
  string name;

  book() { borrowed = 0; }

  book(int _id, string _name, int _quantity, int _borrowed) {
    id = _id;
    name = _name;
    quantity = _quantity;
    borrowed = _borrowed;
  }
};

struct user {
  int id, n_borrowed_books = 0;
  string name;
  book borrowed_books[MAX_BORROWED];

  user() {}

  user(string _name, int _id) {
    id = _id;
    name = _name;
  }
};

bool compare_books_by_id(book &a, book &b) { return a.id < b.id; }
bool compare_books_by_name(book &a, book &b) { return a.name < b.name; }

struct library_system {
  book library[MAX_BOOKS];
  user library_users[MAX_USERS];
  int all_books, n_of_users;

  library_system() {
    all_books = 0;
    n_of_users = 0;
  }

  int is_user(string user_name) {
    for (int i = 0; i < n_of_users; i++)
      if (library_users[i].name == user_name)
        return i;
    return -1;
  }

  int is_book(string book_name) {
    for (int i = 0; i < all_books; i++)
      if (library[i].name == book_name)
        return i;
    return -1;
  }

  bool is_prefix(string book_name, string prefix) {
    int prefix_size = prefix.size();
    for (int i = 0; i < prefix_size; i++)
      if (book_name[i] != prefix[i])
        return false;
    return true;
  }

  void add_book() {
    book new_book;
    cout << "Enter your book info: id & name & total quantity: ";
    cin >> new_book.id >> new_book.name >> new_book.quantity;
    library[all_books] = new_book;
    all_books++;
  }

  void search_books_by_prefix() {
    string prefix;
    cout << "Enter book name prefix: ";
    cin >> prefix;
    bool is_exist = false;

    for (int i = 0; i < all_books; i++) {
      string book_name = library[i].name;
      if (is_prefix(book_name, prefix)) {
        is_exist = true;
        cout << book_name << endl;
      }
    }
    if (!is_exist)
      cout << "No books with such prefix\n";

    cout << endl;
  }

  void print_who_borrowed_book_by_name() {
    string book_name;
    cout << "Enter book name: ";
    cin >> book_name;

    if (!is_book(book_name)) {
      cout << "Invalid book name.";
      return;
    }

    bool user_borrowed_thebook = false;
    for (int i = 0; i < n_of_users; i++) {
      user current_user = library_users[i];
      int user_borrowed_books = current_user.n_borrowed_books;
      for (int j = 0; j < user_borrowed_books; j++) {
        if (current_user.borrowed_books[j].name == book_name) {
          user_borrowed_thebook = true;
          cout << current_user.name << endl;
        }
      }
    }
    if (!user_borrowed_thebook)
      cout << "there is no user borrowed this book yet.\n";
  }

  void print_library_by_id() {
    cout << "\nThe whole library sorted by book id:\n";
    sort(library, library + all_books, compare_books_by_id);

    for (int i = 0; i < all_books; i++) {
      book cnt_book = library[i];
      cout << "id = " << cnt_book.id << " name = " << cnt_book.name
           << " total_quantity " << cnt_book.quantity << " total_borrowed "
           << cnt_book.borrowed << endl;
    }
    cout << endl;
  }

  void print_library_by_name() {
    cout << "\nThe whole library sorted by book name:\n";
    sort(library, library + all_books, compare_books_by_name);

    for (int i = 0; i < all_books; i++) {
      book cnt_book = library[i];
      cout << "id = " << cnt_book.id << " name = " << cnt_book.name
           << " total_quantity " << cnt_book.quantity << " total_borrowed "
           << cnt_book.borrowed << endl;
    }
    cout << endl;
  }
  void add_user() {
    user new_user;
    cout << "Enter your name & nationa id: ";
    cin >> new_user.name >> new_user.id;
    library_users[n_of_users] = new_user;
    n_of_users++;
  }

  void user_borrow_book() {
    string borrower, book_name;
    cout << "Enter user name and book name: ";
    cin >> borrower >> book_name;

    int user_idx = is_user(borrower);
    int book_idx = is_book(book_name);
    bool is_book_avalibale =
        library[book_idx].borrowed < library[book_idx].quantity;
    if (user_idx != -1 && book_idx != -1) {
      if (!is_book_avalibale)
        cout << "you can't borrow this book there is no copy for you.\n";

      library_users[user_idx]
          .borrowed_books[library_users[user_idx].n_borrowed_books] =
          library[book_idx];
      library_users[user_idx].n_borrowed_books++;
      library[book_idx].borrowed++;
    } else
      cout << "make sure that your name and the book name is right.\n";
  }

  void rearange_user_borrowed_books(user &cnt_user) {
    int user_borrowed_books = cnt_user.n_borrowed_books;
    for (int i = 0; i < user_borrowed_books; i++) {
      cnt_user.borrowed_books[i] = cnt_user.borrowed_books[i + 1];
    }
  }

  void user_return_book() {
    string returner, book_name;
    cout << "Enter user name and book name: ";
    cin >> returner >> book_name;

    int user_idx = is_user(returner);
    int book_idx = is_book(book_name);

    if (user_idx != -1 && book_idx != -1) {
      library_users[user_idx].n_borrowed_books--;
      rearange_user_borrowed_books(library_users[user_idx]);
      library[book_idx].borrowed--;

    } else
      cout << "make sure that your name and the book name is right.\n";
  }

  void print_users() {
    for (int i = 0; i < n_of_users; i++) {
      user current_user = library_users[i];

      cout << "user " << current_user.name << " id " << current_user.id
           << " borrowed books ids: ";

      int user_borrowed_books = current_user.n_borrowed_books;

      for (int j = 0; j < user_borrowed_books; j++) {
        int book_id = current_user.borrowed_books[j].id;
        cout << book_id << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

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
