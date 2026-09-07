#include <iostream>
#include <vector>
using namespace std;

// Function to remove a student's marks by index
void removeStudentMark(vector<int>& marks, int index) {
    if (index >= 0 && index < marks.size()) {
        marks.erase(marks.begin() + index);
        cout << "Marks removed successfully.\n";
    } else {
        cout << "Invalid index! No changes made.\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);

    // Taking input for student marks
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    int rollNumber;
    cout << "\nEnter the roll number (index) of the student to remove: ";
    cin >> rollNumber;

    // Calling function to remove student mark
    removeStudentMark(marks, rollNumber);

    // Displaying updated list
    cout << "\nUpdated Marks List:\n";
    for (int i = 0; i < marks.size(); i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
    }

    return 0;
}
