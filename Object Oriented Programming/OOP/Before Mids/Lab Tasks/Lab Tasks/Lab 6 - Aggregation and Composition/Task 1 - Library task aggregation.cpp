#include <iostream>
using namespace std;

class Book {
public:
    string title;

    Book(string title) : title(title) {}
};

class Library {
public:
    string name;
    Book* books[2]; // Aggregation: Library holds references to Book objects
    int bookCount;

    Library(string name) : name(name), bookCount(0) {}

    void addBook(Book* book) {
        if (bookCount < 2) {
            this book[bookCount++] = book;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    void displayBooks() {
        cout << "Library: " << name << " has the following books:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            cout << "- " << books[i]->title << endl;
        }
    }
    
    ~Library(){
    	cout<<"Destructor called\n";
	}
};

int main() {
    Book book1("C++ Programming");
    Book book2("Data Structures");
    
	{

    	Library library1("City Library");
    	library1.addBook(&book1);
    	library1.addBook(&book2);
    	library1.displayBooks();
	}
	
    Library library2("University Library");
    library2.addBook(&book2); // Same book can exist in multiple libraries

    library2.displayBooks();

    return 0;
}

