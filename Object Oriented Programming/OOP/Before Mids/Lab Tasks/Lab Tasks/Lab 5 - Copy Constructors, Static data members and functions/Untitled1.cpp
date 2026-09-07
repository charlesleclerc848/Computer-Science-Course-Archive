#include <iostream>
#include <string>
using namespace std;

class Professor {
public:
    string name;

    // Constructor for Professor
    Professor(string name) {
        this->name = name;
    }
};

class Department {
public:
    Professor* ptr[2]; // Array to hold pointers to Professor objects
    int profCount;

    // Constructor for Department to initialize profCount
   // Department() : profCount(0) {}

    // Function to add a professor
    void add(Professor* prof) {
        if (profCount < 2) {
            ptr[profCount++] = prof; // Add professor to the array
        } else {
            cout << "Cannot add more professors. Limit reached." << endl;
        }
    }

    // Function to display professor names
    void display() {
        cout << "Professors in the department:" << endl;
        for (int i = 0; i < profCount; i++) {
            cout << "- " << ptr[i]->name << endl; // Access professor's name using the pointer
        }
    }
};

int main() {
    // Create Professor objects
    Professor prof1("Ali");
    Professor prof2("Ustad e Mohtram");

    // Create a Department object
    Department dep;

    // Add professors to the department
    dep.add(&prof1);
    dep.add(&prof2);

    // Display professors in the department
    dep.display();

    return 0;
}
