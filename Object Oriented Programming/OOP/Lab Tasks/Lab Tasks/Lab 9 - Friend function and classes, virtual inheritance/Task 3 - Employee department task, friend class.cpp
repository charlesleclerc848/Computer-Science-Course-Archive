#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    Employee(string empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    friend class Department;
};

class Department {
private:
    string departmentName;

public:
    Department(string deptName) : departmentName(deptName) {}

    void displayEmployeeDetails(const Employee& emp) {
        cout << "Department: " << departmentName << endl;
        cout << "Employee Name: " << emp.name << endl;
        cout << "Employee ID: " << emp.id << endl;
        cout << "Employee Salary: $" << emp.salary << endl;
    }
};

int main() {
    Employee emp1("Alice", 101, 55000.0);
    Employee emp2("Bob", 102, 60000.0);

    Department dept("Human Resources");

    cout << "Employee Details in Department:" << endl;
    dept.displayEmployeeDetails(emp1);
    dept.displayEmployeeDetails(emp2);

    return 0;
}

