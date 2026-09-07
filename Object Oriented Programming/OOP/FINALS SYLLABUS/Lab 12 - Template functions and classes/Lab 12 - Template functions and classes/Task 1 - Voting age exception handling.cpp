#include <iostream>
#include <string>
using namespace std;

// User-defined exception
class NotEligibleToVoteException {
    string message;
public:
    NotEligibleToVoteException(string msg) : message(msg) {}
    string what() {
        return message;
    }
};

class Person {
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
        if (age < 18) {
            throw NotEligibleToVoteException("Person is not eligible to vote. Minimum age is 18.");
        }
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << ". Eligible to vote." << endl;
    }
};

int main() {
    try {
        Person person("Ali Ahmad", 1000); // Age less than 18
        person.display();
    } catch (NotEligibleToVoteException e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
