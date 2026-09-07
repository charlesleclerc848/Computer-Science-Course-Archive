#include<iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    void setData(string n, int i, double s);
    void getData() const;
};

void Employee::setData(string n, int i, double s) {
    name = n;
    id = i;
    salary = s;
}

void Employee::getData() const {
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Salary: $" << salary << endl;
}

int main() {
    Employee emp;
    emp.setData("Alice", 1001, 75000);
    emp.getData();

    return 0;
}

