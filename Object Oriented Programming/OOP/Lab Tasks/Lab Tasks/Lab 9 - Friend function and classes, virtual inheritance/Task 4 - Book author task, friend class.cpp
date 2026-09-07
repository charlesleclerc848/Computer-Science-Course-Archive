#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string isbn;
    int pages;

public:
    Book(string bookTitle, string bookIsbn, int bookPages)
        : title(bookTitle), isbn(bookIsbn), pages(bookPages) {}

    friend class Author;
};

class Author {
private:
    string name;

public:
    Author(string authorName) : name(authorName) {}

    void printBookDetails(const Book& book) {
        cout << "Author: " << name << endl;
        cout << "Book Title: " << book.title << endl;
        cout << "ISBN: " << book.isbn << endl;
        cout << "Pages: " << book.pages << endl;
    }
};

int main() {
    Book book1("C++ Basics", "123456789", 300);
    Book book2("Advanced C++", "987654321", 400);

    Author author("John Smith");

    cout << "Book Details:" << endl;
    author.printBookDetails(book1);
    author.printBookDetails(book2);

    return 0;
}

