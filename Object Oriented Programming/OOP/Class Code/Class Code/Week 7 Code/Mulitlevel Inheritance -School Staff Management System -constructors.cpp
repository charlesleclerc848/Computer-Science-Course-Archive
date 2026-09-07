#include <iostream>
using namespace std;

// Base class
class Staff {
protected:
    string name;
    int staffID;

public:
    Staff(string n, int id) : name(n), staffID(id) {}

    void displayBasicInfo() {
        cout << "Staff Name: " << name << ", Staff ID: " << staffID << endl;
    }
};

// Derived class from Staff
class Teacher : public Staff {
protected:
    string subject;

public:
    Teacher(string n, int id, string sub) : Staff(n, id), subject(sub) {}

    void displaySubject() {
        cout << "Subject: " << subject << endl;
    }
};

// Derived class from Teacher
class DepartmentHead : public Teacher {
    string department;
    double baseSalary;
    double bonus;

public:
    DepartmentHead(string n, int id, string sub, string dept, double salary, double b)
        : Teacher(n, id, sub), department(dept), baseSalary(salary), bonus(b) {}

    void displayTotalSalary() {
        double totalSalary = baseSalary + bonus;
        displayBasicInfo();    // Display name and ID from Staff
        displaySubject();       // Display subject from Teacher
        cout << "Department: " << department << endl;
        cout << "Total Salary (Base + Bonus): $" << totalSalary << endl;
    }
};

int main() {
    DepartmentHead dh("Alice Smith", 101, "Mathematics", "Science", 50000, 7000);
    dh.displayTotalSalary();
    return 0;
}

