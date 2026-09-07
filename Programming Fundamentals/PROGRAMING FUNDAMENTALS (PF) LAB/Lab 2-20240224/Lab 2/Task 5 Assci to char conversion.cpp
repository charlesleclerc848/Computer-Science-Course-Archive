#include <iostream>
using namespace std;

int main() {
    int asciiValue;

    cout << "Enter an ASCII value: ";
    cin >> asciiValue;

    // Display the next five characters after the ASCII value
    for (int i = 1; i <= 5; i++) {
        char nextChar = asciiValue + i;
        cout << nextChar << " ";
    }
    cout << endl;

    return 0;
}

