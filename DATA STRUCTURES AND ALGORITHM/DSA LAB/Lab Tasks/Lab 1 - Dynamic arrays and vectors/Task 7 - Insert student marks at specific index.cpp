#include <iostream>
#include <vector>
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

    // Taking input for new mark and index
    int newMark, index;
    cout << "\nEnter the marks to insert: ";
    cin >> newMark;
    cout << "Enter the position (0-based index): ";
    cin >> index;

    // Inserting marks at the specified index
    if (index >= 0 && index <= marks.size()) {
        marks.insert(marks.begin() + index, newMark);
    } else {
        cout << "Invalid index!" << endl;
    }

    // Displaying updated list
    cout << "\nUpdated Marks List:\n";
    for (int mark : marks) {
        cout << mark << " ";
    }

    return 0;
}
