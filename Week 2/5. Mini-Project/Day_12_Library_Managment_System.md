Great! Here’s what you need to focus on for Week 2, Day 5 of your OOP in C++ learning plan:

## Week 2, Day 5: Practice and Review

### Topics to Cover:
1. **Review Concepts:**
    - Encapsulation and Abstraction
    - Inheritance
    - Polymorphism
    - Virtual Destructors
    - Pure Virtual Functions
    - Type Identification and Casting

2. **Practice Exercises:**
    - Implement a mini-project that incorporates all the concepts you've learned this week.

### Mini-Project: Library Management System

Let's build a simple library management system that incorporates encapsulation, inheritance, polymorphism, virtual destructors, pure virtual functions, and type identification and casting.

### Classes and Features:
1. **Book (Base Class)**
    - Attributes: Title, Author, ISBN
    - Pure virtual function: displayInfo()

2. **Derived Classes: Fiction, NonFiction**
    - Override displayInfo()

3. **Library (Manages Books)**
    - Add Book
    - Remove Book
    - Display all Books
    - Find Book by ISBN

### Comprehensive Example Code

```cpp
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
```

### Explanation:

1. **Encapsulation:**
   - `Book` class encapsulates the details of a book.
   - Getter for `isbn` provides controlled access.

2. **Inheritance:**
   - `Fiction` and `NonFiction` classes inherit from `Book`.

3. **Polymorphism:**
   - `Library` class uses a vector of `Book*` to store different types of books.
   - Virtual `displayInfo` function allows calling the correct `displayInfo` for each book type.

4. **Virtual Destructors:**
   - Ensures that the correct destructor is called for each book type.

5. **Pure Virtual Functions:**
   - `displayInfo` is a pure virtual function in `Book` and is overridden in `Fiction` and `NonFiction`.

6. **Type Identification and Casting:**
   - `const_cast` is used in the `findBookByISBN` method to cast away the constness for modification if needed.

### Summary

This mini-project example demonstrates how to integrate the key concepts you have learned, such as encapsulation, inheritance, polymorphism, virtual destructors, pure virtual functions, and type casting, into a single coherent application. This practical application helps in solidifying your understanding of these concepts in a real-world context.