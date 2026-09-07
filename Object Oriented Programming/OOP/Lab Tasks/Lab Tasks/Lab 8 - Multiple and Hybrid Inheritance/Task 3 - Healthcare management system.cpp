#include <iostream>
using namespace std;

class Patient {
protected:
    int patientID;
    string name;
    int age;

public:
    Patient(int id = 0, string n = "", int a = 0) : patientID(id), name(n), age(a) {}

    void viewPatientInfo() {
        cout << "Patient Info:" << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Billing {
protected:
    double billingAmount;
    string paymentStatus;

public:
    Billing(double amount = 0.0) : billingAmount(amount), paymentStatus("Unpaid") {}

    void processPayment() {
        paymentStatus = "Paid";
        cout << "Processing Payment of $" << billingAmount << endl;
        cout << "Payment Status: " << paymentStatus << endl;
    }

    void checkInsuranceCoverage() {
        if (billingAmount > 100.0) {
            cout << "Insurance Coverage is applied." << endl;
        } else {
            cout << "No Insurance Coverage applicable." << endl;
        }
    }
};

class RegularPatient : public Patient {
public:
    RegularPatient(int id, string n, int a) : Patient(id, n, a) {}

    void displayRegularPatientInfo() {
        cout << "Regular Patient Information:" << endl;
        viewPatientInfo();
        cout << "This patient is a regular patient with no insurance." << endl;
    }
};

class InsurancePatient : public Patient, public Billing {
public:
    InsurancePatient(int id, string n, int a, double amount) : Patient(id, n, a), Billing(amount) {}

    void displayInsurancePatientInfo() {
        cout << "Insurance Patient Information:" << endl;
        viewPatientInfo();
        checkInsuranceCoverage();
    }
};

class PatientManagement : public RegularPatient, public InsurancePatient {
public:
    PatientManagement(int id, string n, int a, double amount) : RegularPatient(id, n, a), InsurancePatient(id, n, a, amount) {}

    void displayCompletePatientInfo() {
        cout << "Complete Patient Management Info:" << endl;
        RegularPatient::viewPatientInfo();
        if (billingAmount > 0.0) {
            cout << "Billing Amount: $" << billingAmount << endl;
            checkInsuranceCoverage();
        } else {
            cout << "No billing information available." << endl;
        }
    }
};

int main() {
    // Regular patient example
    RegularPatient regPatient(101, "John Doe", 45);
    regPatient.displayRegularPatientInfo();

    cout << "\n---------------------------------\n";

    // Insurance patient example
    InsurancePatient insPatient(102, "Jane Smith", 38, 150.0);
    insPatient.displayInsurancePatientInfo();

    cout << "\n---------------------------------\n";

    // Complete patient management example
    PatientManagement patientMgmt(103, "David Brown", 50, 250.0);
    patientMgmt.displayCompletePatientInfo();

    return 0;
}

