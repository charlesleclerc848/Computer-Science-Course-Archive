#include <iostream>
using namespace std;

class Doctor {
protected:
    string name;
    string specialization;
    string licenseNumber;

public:
    Doctor(string n, string s, string l) : name(n), specialization(s), licenseNumber(l) {}

    void diagnosePatient() {
        cout << "Diagnosing Patient..." << endl;
    }
};

class Manager {
protected:
    string departmentName;
    string employeeID;

public:
    Manager(string d, string e) : departmentName(d), employeeID(e) {}

    void scheduleShifts() {
        cout << "Scheduling Shifts..." << endl;
    }
};

class SeniorDoctor : public Doctor, public Manager {
public:
    SeniorDoctor(string n, string s, string l, string d, string e)
        : Doctor(n, s, l), Manager(d, e) {}

    void overseeDepartment() {
        cout << "Overseeing Department Activities..." << endl;
    }

    void displayInfo() {
        cout << "Senior Doctor: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "License Number: " << licenseNumber << endl;
        cout << "Department: " << departmentName << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

int main() {
    SeniorDoctor sd("Dr. John Smith", "Cardiology", "MD12345", "Cardiology", "MGR456");

    sd.displayInfo();
    sd.diagnosePatient();
    sd.scheduleShifts();
    sd.overseeDepartment();

    return 0;
}

