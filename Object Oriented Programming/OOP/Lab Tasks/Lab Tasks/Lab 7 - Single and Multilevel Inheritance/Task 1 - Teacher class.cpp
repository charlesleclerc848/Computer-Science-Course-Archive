#include <iostream>
using namespace std;

// Base class for Teacher
class Teacher {
protected:
    string name;
    string subject;
    double salary;

public:
    // Constructor for Teacher class
    Teacher(string n, string sub, double sal) 
        : name(n), subject(sub), salary(sal) {}

    // Method to display teacher details
    void displayTeacher() {
        cout << "Teacher Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Derived class for HeadTeacher
class HeadTeacher : public Teacher {
    double responsibilityAllowance;
    string department;

public:
    // Constructor for HeadTeacher class
    HeadTeacher(string n, string sub, double sal, double allowance, string dept) 
        : Teacher(n, sub, sal), responsibilityAllowance(allowance), department(dept) {}

    // Method to calculate total earnings (salary + responsibility allowance)
    double calculateTotalEarnings() {
        return salary + responsibilityAllowance;
    }

    // Method to display HeadTeacher details
    void displayHeadTeacher() {
        displayTeacher();  // Display base class details
        cout << "Responsibility Allowance: $" << responsibilityAllowance << endl;
        cout << "Department: " << department << endl;
        cout << "Total Earnings: $" << calculateTotalEarnings() << endl;
    }
};

// Main function to demonstrate the classes
int main() {
    // Create a HeadTeacher object
    HeadTeacher headTeacher("John Smith", "Math", 5000.00, 1000.00, "Mathematics Department");

    cout << "HeadTeacher Details:" << endl;
    headTeacher.displayHeadTeacher();

    return 0;
}

