#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int nationalID;

public:
    Person(string n = "", int id = 0) : name(n), nationalID(id) {}

    void displayInfo() {
        cout << "Name: " << name << ", National ID: " << nationalID << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNumber;

public:
    Student(string n, int id, int roll) : Person(n, id), rollNumber(roll) {}

    void study() {
        cout << name << " is studying." << endl;
    }

    void displayInfo() {
        cout << "Student Info:" << endl;
        Person::displayInfo();
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string n, int id, string subj) : Person(n, id), subject(subj) {}

    void teach() {
        cout << name << " is teaching " << subject << "." << endl;
    }

    void displayInfo() {
        cout << "Teacher Info:" << endl;
        Person::displayInfo();
        cout << "Subject: " << subject << endl;
    }
};

class ResearchAssistant : public Student, public Teacher {
protected:
    string researchField;

public:
    ResearchAssistant(string n, int id, int roll, string subj, string field)
        : Person(n, id), Student(n, id, roll), Teacher(n, id, subj), researchField(field) {}

    void conductResearch() {
        cout << name << " is conducting research in " << researchField << "." << endl;
    }

    void displayInfo() {
        cout << "Research Assistant Info:" << endl;
        Person::displayInfo();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subject: " << subject << endl;
        cout << "Research Field: " << researchField << endl;
    }
};

int main() {
    ResearchAssistant ra("Alice", 12345, 678, "Physics", "Quantum Mechanics");
    ra.displayInfo();
    ra.conductResearch();
    ra.study();
    ra.teach();

    return 0;
}

