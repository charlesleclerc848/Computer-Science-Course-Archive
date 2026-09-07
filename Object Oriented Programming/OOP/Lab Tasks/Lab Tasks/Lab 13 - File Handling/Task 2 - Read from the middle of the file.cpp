#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Move the file pointer to the end to get the file size
    file.seekg(0, ios::end); // Move to the end of the file
    int fileSize = file.tellg(); // Get the size of the file
    file.seekg(fileSize / 2); // Move to the middle of the file

    cout << "Reading from the middle of the file:\n";

    // Read and display the content from the middle to the end
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
