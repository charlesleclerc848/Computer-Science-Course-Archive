#include <iostream>
using namespace std;

class Professor {
public:
    string name;

    Professor(string name) : name(name) {}
};

class Department {
public:
    string name;
    Professor* professors[2]; // Aggregation: Department holds references to Professor objects
    int professorCount;

    Department(string name) : name(name), professorCount(0) {}

    void addProfessor(Professor* professor) {
        if (professorCount < 2) {
            professors[professorCount] = professor;
            professorCount++;
        } else {
            cout << "Department is full!" << endl;
        }
    }

    void displayProfessors() {
        cout << "Department: " << name << " has the following professors:" << endl;
        for (int i = 0; i < professorCount; ++i) {
            cout << "- " << professors[i]->name << endl;
        }
    }
};

int main() {
    Professor professor1("Dr. Adams");
    Professor professor2("Dr. Brown");

    Department department1("Computer Science");
    department1.addProfessor(&professor1);
    department1.addProfessor(&professor2);

    Department department2("Mathematics");
    department2.addProfessor(&professor2); // Professor can belong to multiple departments

    department1.displayProfessors();
    department2.displayProfessors();

    return 0;
}

