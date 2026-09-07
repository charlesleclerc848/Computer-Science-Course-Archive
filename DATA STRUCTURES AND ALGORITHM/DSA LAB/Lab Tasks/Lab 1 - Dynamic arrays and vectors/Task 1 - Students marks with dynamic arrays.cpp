#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Dynamically allocate memory for storing marks
    int* marks = new int[n];

    // Taking input
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Finding highest and lowest marks
    int highest = marks[0], lowest = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];
    }

    // Displaying marks
    cout << "\nStored Marks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
    }

    // Displaying highest and lowest marks
    cout << "\nHighest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;

    // Free allocated memory
    delete[] marks;

    return 0;
}
