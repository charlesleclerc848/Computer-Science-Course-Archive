#include <iostream>
using namespace std;

// Structure declaration
struct Person {
    string name;
    int age;
    float salary;
};

// Function that takes a structure as a parameter
void displayPerson(Person person) {
    cout << "\nName: " << person.name << endl;
    cout << "Age: " << person.age << endl;
    cout << "Salary: " << person.salary << endl;
}

int main() {
    // Create a structure instance
    Person bill;
    cout<<"Enter name : ";
    cin>>bill.name;
    cout<<"Enter age : ";
	cin>>bill.age;
	cout<<"Enter salary : ";
    cin>>bill.salary;

    // Pass the structure to the function
    displayPerson(bill);

    return 0;
}

