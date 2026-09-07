#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("example.txt", ios::in | ios::out);

    if (file.is_open()) {
        // Get current positions of pointers
        cout << "Initial read pointer (tellg): " << file.tellg() << endl;
        cout << "Initial write pointer (tellp): " << file.tellp() << endl;

        // Move pointers
        file.seekg(5, ios::beg); // Move read pointer
        cout << "After seekg, read pointer: " << file.tellg() << endl;

        file.seekp(3, ios::beg); // Move write pointer        
        cout << "After seekp, write pointer: " << file.tellp() << endl;

        file.close();
    } else {
        cout << "Error opening file." << endl;
    }

    return 0;
}
