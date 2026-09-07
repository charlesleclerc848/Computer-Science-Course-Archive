#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the file in input mode
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Move to the end of the file
    file.seekg(0, ios::end);
    int fileSize = file.tellg();  // Get the size of the file

    // Read the file content in reverse order
    cout << "Reversed Diary Entry:\n";
    for (int i = fileSize - 1; i >= 0; i--) {
        file.seekg(i); // Move the read pointer to position i
        char ch;
        file.get(ch); // Read the character
        cout << ch;    // Display the character
    }

    file.close();
    return 0;
}
