#include <iostream>
using namespace std;

int linearSearchChar(string str, char target) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == target) {
            return i; // Return index of first occurrence
        }
    }
    return -1; // Return -1 if character not found
}

int main() {
    string str;
    char target;

    cout << "Enter a string: ";
    getline(cin, str); // Taking string input with spaces

    cout << "Enter the character to search: ";
    cin >> target;

    int index = linearSearchChar(str, target);

    if (index != -1) {
        cout << "Character '" << target << "' found at index: " << index << endl;
    } else {
        cout << "Character not found in the string." << endl;
    }

    return 0;
}
