#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    if (islower(ch)) {
        cout << ch << " is a lowercase letter." << endl;
        ch = toupper(ch);
        cout << "Converting to uppercase: " << ch << endl;
    }
    else if (isupper(ch)) {
        cout << ch << " is an uppercase letter." << endl;
        ch = tolower(ch);
        cout << "Converting to lowercase: " << ch << endl;
    }
    else {
        cout << ch << " is not a letter." << endl;
    }

    return 0;
}

