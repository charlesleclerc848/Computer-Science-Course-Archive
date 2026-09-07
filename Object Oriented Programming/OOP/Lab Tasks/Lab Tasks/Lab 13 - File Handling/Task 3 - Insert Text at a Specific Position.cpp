#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Accept input from the user
    string filename, name;
    int position;

    cout << "Enter the filename: ";
    cin >> filename;

    cout << "Enter the position where you want to insert your name: ";
    cin >> position;

    cout << "Enter your name: ";
    cin.ignore();  // To ignore the newline left in the buffer by previous input
    getline(cin, name);

    // Open the file in read-write mode
    fstream file(filename, ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    // Move the write pointer to the specified position
    file.seekp(position);

    // Insert the name overwriting existing content
    file << name;

    file.close();

    cout << "Your name has been inserted successfully!" << endl;

    return 0;
}
