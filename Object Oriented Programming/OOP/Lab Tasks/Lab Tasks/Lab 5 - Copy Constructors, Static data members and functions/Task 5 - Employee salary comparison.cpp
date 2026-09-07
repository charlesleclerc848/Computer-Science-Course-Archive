#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    // Constructor to initialize name and salary
    Employee() {
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
        cin.ignore(); // Clear newline character from the buffer
    }

    // Method to compare salaries with another Employee
    string compareSalary(const Employee& other) const {
        return (salary > other.salary) ? name : other.name;
    }

    // Method to display employee details
    void display() const {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

int main() {
    // Create two Employee objects
    cout << "Enter details for the first employee:\n";
    Employee employee1;

    cout << "\nEnter details for the second employee:\n";
    Employee employee2;

    // Compare salaries and get the name of the employee with the higher salary
    string higherSalaryEmployee = employee1.compareSalary(employee2);

    // Display employee details
    cout << "\nEmployee Details:\n";
    employee1.display();
    employee2.display();

    // Display the employee with the higher salary
    cout << "\nEmployee with the higher salary: " << higherSalaryEmployee << endl;

    return 0;
}

