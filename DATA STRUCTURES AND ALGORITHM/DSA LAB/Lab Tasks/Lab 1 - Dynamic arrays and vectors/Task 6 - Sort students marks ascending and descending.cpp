#include <iostream>
#include <vector>
#include <algorithm>  // For sort()
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Sorting in ascending order
    sort(marks.begin(), marks.end());
    cout << "\nMarks in Ascending Order:\n";
    for (int mark : marks) {
        cout << mark << " ";
    }

    // Sorting in descending order
    sort(marks.begin(), marks.end(), greater<int>());
    cout << "\nMarks in Descending Order:\n";
    for (int mark : marks) {
        cout << mark << " ";
    }

    return 0;
}
