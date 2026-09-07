#include <iostream>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {} // Constructor to initialize name and id
    void displayInfo() {
        cout << "Employee Name: " << name << ", ID: " << id << endl;
    }
};

// Derived class from Employee
class FullTimeEmployee : public Employee {
protected:
    double baseSalary;
public:
    FullTimeEmployee(string n, int i, double salary) : Employee(n, i), baseSalary(salary) {}
    void displaySalary() {
        cout << "Base Salary: $" << baseSalary << endl;
    }
};

// Derived class from FullTimeEmployee
class Manager : public FullTimeEmployee {
    double bonus;
public:
    Manager(string n, int i, double salary, double b) : FullTimeEmployee(n, i, salary), bonus(b) {}
    void displayTotalSalary() {
        double total = baseSalary + bonus;
        cout << "Total Salary (Base + Bonus): $" << total << endl;
    }
};

int main() {
    Manager m("Alice", 101, 50000, 10000);
    m.displayInfo();          // From Employee
    m.displaySalary();        // From FullTimeEmployee
    m.displayTotalSalary();   // From Manager
    return 0;
}

