#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("random.txt", ios::out | ios::in);
    file << "1234567890\n"; // Write 10 characters
    file << "abcdefg";
    file.seekp(2);        // Move write pointer to 6th position
    file << "ABCDE";      // Overwrite starting from 6th position
    file.seekg(13);        // Move read pointer to the beginning
    string content;
    file >> content;      // Read the entire file
    cout << "File Content: " << content << endl;
    file.close();
    return 0;
}
