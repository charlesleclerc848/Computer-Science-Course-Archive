#include <iostream>
#include <vector>  // Required for using vectors

using namespace std;

int main() {
    int n;  
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);  // Declaring a vector of size 'n'

    // Taking input for student marks
    cout << "Enter marks for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Displaying all student marks
    cout << "\nStudents Marks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
    }

    return 0;
}
