#include <iostream>
using namespace std;

// Recursive function to count occurrences of 'search' in 'str'
int numChars(char search, char str[], int index) {
    if (str[index] == '\0') // Base case: End of string
        return 0;
    else if (str[index] == search) // If a match is found, add 1
        return 1 + numChars(search, str, index + 1);
    else // If no match, just continue checking the rest of the string
        return numChars(search, str, index + 1);
}

int main() {
    char array[] = "abcddddef"; // Sample string
    
    // Count occurrences of 'd'
    cout << "The letter d appears " << numChars('d', array, 0) << " times." << endl;
    
    return 0;
}

