#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the original file in input mode
    ifstream inputFile("sample.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    // Move the file pointer to the end to determine the file size
    inputFile.seekg(0, ios::end);
    int fileSize = inputFile.tellg();
    inputFile.seekg(0, ios::beg); // Move the pointer back to the beginning

    // Determine the midpoint
    int midpoint = fileSize / 2;

    // Open the first output file for the first half of the novel
    ofstream firstHalf("novel_part1.txt");
    if (!firstHalf.is_open()) {
        cout << "Error opening the output file!" << endl;
        return 1;
    }

    // Write the first half to the first output file
    char ch;
    for (int i = 0; i < midpoint; i++) {
        inputFile.get(ch);
        firstHalf.put(ch);
    }

    // Open the second output file for the second half of the novel
    ofstream secondHalf("novel_part2.txt");
    if (!secondHalf.is_open()) {
        cout << "Error opening the output file!" << endl;
        return 1;
    }

    // Write the second half to the second output file
    while (inputFile.get(ch)) {
        secondHalf.put(ch);
    }

    // Close the files
    inputFile.close();
    firstHalf.close();
    secondHalf.close();

    cout << "The novel has been split into two parts successfully!" << endl;

    return 0;
}
