#include <iostream>
#include <cstring>
using namespace std;

void concatenateStrings(char* str1, char* str2, char* result) {
    // Copy str1 to result
    while (*str1 != '\0') {
        *result = *str1;
        str1++;
        result++;
    }
    
    // Add a space character
    *result = ' ';
    result++;

    // Copy str2 to result
    while (*str2 != '\0') {
        *result = *str2;
        str2++;
        result++;
    }

    // Add null terminator to result
    *result = '\0';
}

int main() {
    char str1[100];
    char str2[100];
    char result[200];
	char* ptr1 = str1;
	char* ptr2 = str2;
	char* ptr3 = result;
    cout << "Enter the first string: ";
    cin.getline(str1, 100);

    cout << "Enter the second string: ";
    cin.getline(str2, 100);

    concatenateStrings(ptr1, ptr2, ptr3);

    cout << "Concatenated string: " << ptr3<< endl;

    return 0;
}

