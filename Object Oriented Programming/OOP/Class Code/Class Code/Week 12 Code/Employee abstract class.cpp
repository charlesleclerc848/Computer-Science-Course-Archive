#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Employee {
protected:
    string firstName;
    string lastName;

public:
    Employee(string first, string last) : firstName(first), lastName(last) {}

    virtual float earnings() = 0; // Pure virtual function
    virtual void print() = 0;     // Pure virtual function

    virtual ~Employee() {}
};

// Salaried Employee
class SalariedEmployee : public Employee {
private:
    float weeklySalary;

public:
    SalariedEmployee(string first, string last, float salary)
        : Employee(first, last) {
			if(salary > 0)
			{
				weeklySalary = salary;
			}
			else
			{
				weeklySalary = 0;
			}
		}

    float earnings() override {
        return weeklySalary;
    }

    void print() override {
        cout << "Salaried Employee: " << firstName << " " << lastName;
    }
};

// Commission Worker
class CommissionWorker : public Employee {
private:
    float commission;
    int quantity;

public:
    CommissionWorker(string first, string last, float comm, int qty)
        : Employee(first, last) {
        	if(comm > 0)
			{
				commission = comm;
			}
			else
			{
				commission = 0;
			}
			
			if(qty > 0)
			{
				quantity = qty;
			}
			else
			{
				quantity = 0;
			}
		}

    float earnings() override {
        return commission * quantity;
    }

    void print() override {
        cout << "Commission Worker: " << firstName << " " << lastName;
    }
};

// Hourly Worker
class HourlyWorker : public Employee {
private:
    float wage;
    float hours;

public:
    HourlyWorker(string first, string last, float hourlyWage, float workedHours)
        : Employee(first, last), wage(hourlyWage > 0 ? hourlyWage : 0) {
        	if(hourlyWage > 0)
			{
				wage = hourlyWage;
			}
			else
			{
				wage = 0;
			}
        	
			if(workedHours > 0 && workedHours <= 168)
			{
				hours = workedHours;
			}
			else
			{
				hours = 0;
			}
		}

    float earnings() override {
        return wage * hours;
    }

    void print() override {
        cout << "Hourly Worker: " << firstName << " " << lastName;
    }
};

// Base-Plus-Commission Employee
class BasePlusCommissionEmployee : public CommissionWorker {
private:
    float baseSalary;

public:
    BasePlusCommissionEmployee(string first, string last, float comm, int qty, float base)
        : CommissionWorker(first, last, comm, qty) {
			if(base > 0)
			{
				baseSalary = base;
			}
			else
			{
				baseSalary = 0;
			}
		}

    float earnings() override {
        return baseSalary + CommissionWorker::earnings();
    }

    void print() override {
        cout << "Base-Plus-Commission Employee: " << firstName << " " << lastName;
    }
};

int main() {
    // Create different employee objects
    SalariedEmployee salaried("Nauman", "Sarwar", 800.00);
    CommissionWorker commission("Qasim", "Ali", 3.0, 150);
    HourlyWorker hourly("Samer", "Tufail", 13.75, 40);
    BasePlusCommissionEmployee basePlusCommission("Mehshan", "Mustafa", 2.5, 200, 1000.0);

    // Array of Employee pointers
    Employee *employees[] = {&salaried, &commission, &hourly, &basePlusCommission};
    
    // Size of the employees array
    const int numEmployees = sizeof(employees) / sizeof(employees[0]);
    
    // Process each employee
    for (int i = 0; i < numEmployees; ++i) {
        employees[i]->print();
        cout << " earned $" << employees[i]->earnings() << endl;
    }

    return 0;
}
