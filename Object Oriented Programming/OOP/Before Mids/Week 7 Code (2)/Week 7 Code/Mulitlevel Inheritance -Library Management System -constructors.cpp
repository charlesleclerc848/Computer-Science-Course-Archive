#include <iostream>
using namespace std;

// Base class
class Publication {
protected:
    string title;
    string publisher;

public:
    Publication(string t, string p) : title(t), publisher(p) {}

    void displayInfo() {
        cout << "Title: " << title << ", Publisher: " << publisher << endl;
    }
};

// Derived class from Publication
class Book : public Publication {
protected:
    int pageCount;

public:
    Book(string t, string p, int pc) : Publication(t, p), pageCount(pc) {}

    void displayPageCount() {
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class from Book
class Magazine : public Book {
    int issueNumber;

public:
    Magazine(string t, string p, int pc, int issue) 
        : Book(t, p, pc), issueNumber(issue) {}

    void displayFullDetails() {
        displayInfo();           // Method from Publication
        displayPageCount();      // Method from Book
        cout << "Issue Number: " << issueNumber << endl;
    }
};

int main() {
    Magazine m("Tech Trends", "TechMedia", 80, 12);
    m.displayFullDetails();
    return 0;
}

