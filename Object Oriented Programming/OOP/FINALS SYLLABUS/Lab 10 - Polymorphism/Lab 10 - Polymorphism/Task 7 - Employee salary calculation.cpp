#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;

public:
    Employee(string n) : name(n) {}

    virtual void calculateSalary() {
        cout << "Base Employee salary calculation for: " << name << endl;
    }

    virtual ~Employee() {
        cout << "Employee destructor called for " << name << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyWage;
    int hoursWorked;

public:
    HourlyEmployee(string n, double wage, int hours)
        : Employee(n), hourlyWage(wage), hoursWorked(hours) {}

    void calculateSalary() override {
        double salary = hourlyWage * hoursWorked;
        cout << "Hourly Employee " << name << "'s Salary: $" << salary << endl;
    }

    ~HourlyEmployee() {
        cout << "HourlyEmployee destructor called for " << name << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(string n, double salary)
        : Employee(n), annualSalary(salary) {}

    void calculateSalary() override {
        cout << "Salaried Employee " << name << "'s Annual Salary: $" << annualSalary << endl;
    }

    ~SalariedEmployee() {
        cout << "SalariedEmployee destructor called for " << name << endl;
    }
};

int main() {
    HourlyEmployee hourlyEmp("John", 20.0, 40);
    SalariedEmployee salariedEmp("Jane", 50000);

    Employee* emp;
    
    emp = &hourlyEmp;
	emp->calculateSalary();
    
    emp = &salariedEmp;
    emp->calculateSalary();
    
    return 0;
}
