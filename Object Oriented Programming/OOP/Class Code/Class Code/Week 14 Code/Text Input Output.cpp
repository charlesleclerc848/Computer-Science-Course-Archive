#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("text.txt");
    file << "This is a line of text.\nAnother line of text.";
    file.close();

    ifstream readFile("text.txt");
    string line;
    while (getline(readFile, line)) { // Read line by line
        cout << line << endl;
    }
    readFile.close();
    return 0;
}
