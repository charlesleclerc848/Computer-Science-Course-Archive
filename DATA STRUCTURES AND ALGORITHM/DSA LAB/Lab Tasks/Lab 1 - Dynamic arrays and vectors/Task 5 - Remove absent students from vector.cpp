#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);

    // Taking input
    cout << "Enter marks of students (-1 for absent):\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Removing all -1 values
    for (int i=0; i<marks.size(); i++) {
        if (marks[i] == -1) {
            marks.erase(marks.begin()+i);
        }
    }

    // Displaying updated marks list
    cout << "\nUpdated Marks List (Absent students removed):\n";
    for (int i = 0; i < marks.size(); i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
    }

    return 0;
}
