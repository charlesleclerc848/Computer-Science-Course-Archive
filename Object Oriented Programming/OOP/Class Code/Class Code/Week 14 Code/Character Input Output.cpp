#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("character.txt");
    file.put('A'); // Write a single character
    file.put('B');
    file.close();

    ifstream readFile("character.txt");
    char ch;
    while (readFile.get(ch)) { // Read character by character
        cout << ch << " ";
    }
    readFile.close();
    return 0;
}
