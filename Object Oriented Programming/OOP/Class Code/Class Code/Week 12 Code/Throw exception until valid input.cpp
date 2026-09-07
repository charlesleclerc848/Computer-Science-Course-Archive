#include <iostream>
using namespace std;

// Function to get valid input
int getValidNumber() {
    int number;
    while (true) {
        try {
            cout << "Enter a valid number: ";
            cin >> number;
			
			// This function returns true if the last cin command failed and false otherwise. 
            if (cin.fail()) {  // Check if input is invalid
                throw string("Invalid input. Please enter a number.");
            }

            // If input is valid, return the number
            return number;
        } catch (string message) {
            cin.clear();             // Clear the error state
            
            //After clearing the fail state, cin.ignore() discards up to 1000 characters or until a newline ('\n') is encountered.
            cin.ignore(1000, '\n');  // Discard invalid input
            
            cout<<message<<endl;
        }
    }
}

int main() {
    try {
        int validNumber = getValidNumber();
        cout << "You entered: " << validNumber << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    cout << "Program continues normally..." << endl;

    return 0;
}
