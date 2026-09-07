#include <iostream>
using namespace std;

// Template function to search for an element in an array
template <typename T>
int findElement(T arr[], int size, T target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    // Example 1: Integer array
    int intArr[] = {10, 20, 30, 40, 50};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int intTarget = 30;

    int intResult = findElement(intArr, intSize, intTarget);
    if (intResult != -1) {
        cout << "Integer target found at index: " << intResult << endl;
    } else {
        cout << "Integer target not found." << endl;
    }

    // Example 2: Double array
    double doubleArr[] = {10.5, 20.3, 30.8, 40.1, 50.6};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    double doubleTarget = 50.8;

    int doubleResult = findElement(doubleArr, doubleSize, doubleTarget);
    if (doubleResult != -1) {
        cout << "Double target found at index: " << doubleResult << endl;
    } else {
        cout << "Double target not found." << endl;
    }

    // Example 3: String array
    string stringArr[] = {"apple", "banana", "orange", "mango"};
    int stringSize = sizeof(stringArr) / sizeof(stringArr[0]);
    string stringTarget = "banana";

    int stringResult = findElement(stringArr, stringSize, stringTarget);
    if (stringResult != -1) {
        cout << "String target found at index: " << stringResult << endl;
    } else {
        cout << "String target not found." << endl;
    }

    return 0;
}
