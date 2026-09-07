#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Employee {
private:
    string filename; // CSV file name

public:
    Employee(string file){
		filename = file;
	}

    // Function to add an employee
    void create() {
        ofstream file(filename, ios::app); // Open file in append mode for writing in file
        if (!file.is_open()) {
            cout << "Error opening file.\n";
            return;
        }

        int id;
        string name, department;
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Department: ";
        getline(cin, department);

        file << id << "," << name << "," << department << "\n";
        file.close();

        cout << "Employee added successfully!\n";
    }

    // Function to display all employees
    void read() {
        ifstream file(filename); // Open file for read
        if (!file.is_open()) {
            cout << "Error opening file.\n";
            return;
        }

        string line;
        cout << "Employee Details:\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, department;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, department, ',');
            cout << "ID: " << id << ", Name: " << name << ", Department: " << department << endl;
        }
        file.close();
    }

    // Function to search for an employee by ID
    void search() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file.\n";
            return;
        }

        int searchId;
        cout << "Enter Employee ID to search: ";
        cin >> searchId;

        string line;
        bool found = false;
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, name, department;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, department, ',');

            if (stoi(idStr) == searchId) {
                cout << "Employee Found:\n";
                cout << "ID: " << idStr << ", Name: " << name << ", Department: " << department << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Employee with ID " << searchId << " not found.\n";
        }
        file.close();
    }

    // Function to update employee details
	void update() {
	    string idStr, name, department;
	    int updateId;
	    cout << "Enter Employee ID to update: ";
	    cin >> updateId;
	
	    ifstream inFile(filename); // Open old file for read
	    ofstream outFile("temp.csv"); // Open new file for write
	    bool found = false;
	
	    if (!inFile.is_open() || !outFile.is_open()) {
	        cout << "Error opening file.\n";
	        return;
	    }
	
	    string line;
	    while (getline(inFile, line)) {
	        stringstream ss(line);
	        getline(ss, idStr, ',');
	        getline(ss, name, ',');
	        getline(ss, department, ',');
	
	        if (stoi(idStr) == updateId) {
	            found = true;
	            cout << "Enter new name: ";
	            cin.ignore();
	            getline(cin, name);
	            cout << "Enter new department: ";
	            getline(cin, department);
	        }
	        outFile << idStr << "," << name << "," << department << "\n";
	    }
	
	    inFile.close();
	    outFile.close();
	
	    if (found) {
	        remove(filename.c_str()); // Converts the filename string to a C-style
	        rename("temp.csv", filename.c_str());
	        cout << "Employee updated successfully!\n";
	    } else {
	        remove("temp.csv");
	        cout << "Employee with ID " << updateId << " not found.\n";
	    }
	}
	
	// Function to delete employee details
	void deleteRecord() {
	    string idStr, name, department;
	    int deleteId;
	    cout << "Enter Employee ID to delete: ";
	    cin >> deleteId;
	
	    ifstream inFile(filename);
	    ofstream outFile("temp.csv");
	    bool found = false;
	
	    if (!inFile.is_open() || !outFile.is_open()) {
	        cout << "Error opening file.\n";
	        return;
	    }
	
	    string line;
	    while (getline(inFile, line)) {
	        stringstream ss(line);
	        getline(ss, idStr, ',');
	        getline(ss, name, ',');
	        getline(ss, department, ',');
	
	        if (stoi(idStr) == deleteId) {
	            found = true;
	            cout << "Employee deleted successfully!\n";
	            continue; // Skip writing this record to the updated file
	        }
	        outFile << idStr << "," << name << "," << department << "\n";
	    }
	
	    inFile.close();
	    outFile.close();
	
	    if (found) {
	        remove(filename.c_str());
	        rename("temp.csv", filename.c_str());
	    } else {
	        remove("temp.csv");
	        cout << "Employee with ID " << deleteId << " not found.\n";
	    }
	}
};

int main() {
    Employee emp("employees.csv");
    int choice;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.create();
                break;
            case 2:
                emp.read();
                break;
            case 3:
                emp.search();
                break;
            case 4:
                emp.update();
                break;
            case 5:
                emp.deleteRecord();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

