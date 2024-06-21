#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Book
class Book {
protected:
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
    virtual ~Book() {
        cout << "Book Destructor" << endl;
    }
    string getISBN() const {
        return isbn;
    }
    virtual void displayInfo() const = 0; // Pure virtual function
};

// Derived class Fiction
class Fiction : public Book {
public:
    Fiction(string t, string a, string i) : Book(t, a, i) {}
    ~Fiction() {
        cout << "Fiction Destructor" << endl;
    }
    void displayInfo() const override {
        cout << "Fiction Book: " << title << " by " << author << " (ISBN: " << isbn << ")" << endl;
    }
};

// Derived class NonFiction
class NonFiction : public Book {
public:
    NonFiction(string t, string a, string i) : Book(t, a, i) {}
    ~NonFiction() {
        cout << "NonFiction Destructor" << endl;
    }
    void displayInfo() const override {
        cout << "NonFiction Book: " << title << " by " << author << " (ISBN: " << isbn << ")" << endl;
    }
};

// Library class
class Library {
private:
    vector<Book*> books;

public:
    ~Library() {
        for (Book* book : books) {
            delete book;
        }
    }

    void addBook(Book* book) {
        books.push_back(book);
    }

    void removeBook(string isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getISBN() == isbn) {
                delete *it;
                books.erase(it);
                cout << "Book with ISBN " << isbn << " removed." << endl;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }

    void displayAllBooks() const {
        for (const Book* book : books) {
            book->displayInfo();
        }
    }

    Book* findBookByISBN(string isbn) const {
        for (const Book* book : books) {
            if (book->getISBN() == isbn) {
                return const_cast<Book*>(book);
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;

    // Add books to the library
    library.addBook(new Fiction("The Great Gatsby", "F. Scott Fitzgerald", "1234567890"));
    library.addBook(new NonFiction("Sapiens", "Yuval Noah Harari", "0987654321"));

    // Display all books
    cout << "All books in the library:" << endl;
    library.displayAllBooks();
    cout << endl;

    // Find a book by ISBN
    string isbn = "1234567890";
    Book* book = library.findBookByISBN(isbn);
    if (book) {
        cout << "Book found with ISBN " << isbn << ":" << endl;
        book->displayInfo();
    } else {
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }
    cout << endl;

    // Remove a book by ISBN
    library.removeBook(isbn);

    // Display all books after removal
    cout << "All books in the library after removal:" << endl;
    library.displayAllBooks();

    return 0;
}
