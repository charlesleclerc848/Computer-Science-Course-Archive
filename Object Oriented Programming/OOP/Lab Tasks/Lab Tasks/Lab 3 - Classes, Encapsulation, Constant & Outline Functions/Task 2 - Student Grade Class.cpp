#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    char grade;

public:
    void setName(string n) {
        name = n;
    }

    void setRollNumber(int r) {
        rollNumber = r;
    }

    void setGrade(char g) {
        if(g >= 'A' && g <= 'F') {
            grade = g;
        } else {
            cout << "Invalid grade! Setting default grade 'F'." << endl;
            grade = 'F';
        }
    }

    string getName() {
        return name;
    }

    int getRollNumber() {
        return rollNumber;
    }

    char getGrade() {
        return grade;
    }
};

int main() {
    Student s;
    s.setName("Ali");
    s.setRollNumber(101);

    cout << "Student Name: " << s.getName() << endl;
    cout << "Roll Number: " << s.getRollNumber() << endl;
    s.setGrade('g');
    cout << "Grade: " << s.getGrade() << endl;

    return 0;
}

