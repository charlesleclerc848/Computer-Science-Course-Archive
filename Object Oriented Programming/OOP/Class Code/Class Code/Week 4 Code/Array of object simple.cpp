#include <iostream>
using namespace std;

class Book {
public:
    string title;
    int pages;

    // Parameterized constructor
    Book(string t, int p) {
        title = t;
        pages = p;
    }

    void display() {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

int main() {
    // Array of 3 Book objects
    Book books[3] = {
        Book("Book A", 150),
        Book("Book B", 200),
        Book("Book C", 300)
    };

    // Accessing and displaying each object's data
    for (int i = 0; i < 3; i++) {
        books[i].display();
    }

    return 0;
}

