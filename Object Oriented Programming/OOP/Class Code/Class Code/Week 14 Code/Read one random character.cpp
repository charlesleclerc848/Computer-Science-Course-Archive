#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Writing a file
    ofstream outfile("example.txt");
    outfile << "ABCDEFGH";
    outfile.close();

    // Reading the file
    ifstream infile("example.txt");

    if (infile.is_open()) {
        char ch;

        // Move the read pointer to the 4th character
        infile.seekg(3, ios::beg); // Offset 3 from beginning (0-based index)
        infile.get(ch);           // Read the character
        cout << "Character at position 4: " << ch << endl;

        infile.close();
    } else {
        cout << "Error opening file for reading." << endl;
    }

    return 0;
}
