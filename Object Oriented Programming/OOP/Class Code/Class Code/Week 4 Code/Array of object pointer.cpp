#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Parameterized constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Function to display the person's details
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Dynamically allocate an array of 3 Person objects using a pointer
    Person* persons = new Person[3] {
        Person("Alice", 25),
        Person("Bob", 30),
        Person("Charlie", 35)
    };

    // Access and display each object's data using pointer notation
    for (int i = 0; i < 3; i++) {
        (persons + i)->display();
    }

    // Free the dynamically allocated memory
    delete[] persons;

    return 0;
}

