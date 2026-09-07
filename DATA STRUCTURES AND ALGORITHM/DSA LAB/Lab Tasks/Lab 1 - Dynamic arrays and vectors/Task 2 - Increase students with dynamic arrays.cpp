#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the initial number of students: ";
    cin >> n;

    // Dynamically allocate memory
    int* marks = new int[n];

    // Taking input
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Asking for new size
    int newSize;
    cout << "Enter the new number of students: ";
    cin >> newSize;

    // Allocating new memory
    int* newMarks = new int[newSize];

    // Copying old data to new array
    for (int i = 0; i < n; i++) {
        newMarks[i] = marks[i];
    }

    // Taking input for new students
    cout << "Enter marks for new students:\n";
    for (int i = n; i < newSize; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> newMarks[i];
    }

    // Displaying updated marks list
    cout << "\nUpdated Marks List:\n";
    for (int i = 0; i < newSize; i++) {
        cout << "Student " << i + 1 << ": " << newMarks[i] << endl;
    }

    // Free old and new allocated memory
    delete[] marks;
    delete[] newMarks;

    return 0;
}
