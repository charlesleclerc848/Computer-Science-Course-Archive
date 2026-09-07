#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("sequential.txt");
    file << "Line 1\nLine 2\nLine 3";
    file.close();

    ifstream readFile("sequential.txt");
    string line;
    while (getline(readFile, line)) { // Read line by line
        cout << line << endl;
    }
    readFile.close();
    return 0;
}
