#include <iostream>
using namespace std;

int main() {
    int rows, i, j;

    cout << "Enter the number of rows: ";
    cin >> rows;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

