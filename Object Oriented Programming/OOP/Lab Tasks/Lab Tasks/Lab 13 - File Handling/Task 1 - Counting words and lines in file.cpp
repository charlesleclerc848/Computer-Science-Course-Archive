#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	// Writing content into file
    ofstream outFile("sample.txt");
    if (outFile.is_open()) {
        outFile << "Hello, this is a sample text file.\n";
        outFile << "It contains multiple lines and words.\n";
        outFile << "Counting them is your task!\n";
        outFile.close();
        cout << "File 'sample.txt' created and content added successfully." << endl;
    } else {
        cout << "Error creating file!" << endl;
    }
    
    // Reading content from file
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;

    while (getline(file, line)) {
        lineCount++; // Increment line count
        
        // Use a stringstream to count words in the line
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++; // Increment word count for each word
        }
    }

    file.close();

    // Display results
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of words: " << wordCount << endl;

    return 0;
}
