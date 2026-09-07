#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string fileName;

    try {
        cout << "Enter the file name to open: ";
        cin >> fileName;

        ifstream inputFile(fileName);

        // Check if file exists and is open
        if (!inputFile.is_open()) {
            throw string("Error: File does not exist or cannot be opened.");
        }

        cout << "File opened successfully. Reading content...\n";

        string content;
        while (getline(inputFile, content)) {
            cout << content << endl;
        }

        inputFile.close();
        cout << "File reading completed." << endl;

    } 
    catch (string e) {
        cerr << e << endl;
        cerr << "Program terminating..." << endl;
        return 1; // Non-zero exit code indicates failure
    }

    cout << "Program completed successfully." << endl;
    return 0;
}
