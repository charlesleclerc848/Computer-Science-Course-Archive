#include <iostream>
#include <string>
using namespace std;

// Template function to concatenate two arrays
template <typename T>
void concatenateArrays(T array1[], int size1, T array2[], int size2, T result[]) {
    for (int i = 0; i < size1; ++i) {
        result[i] = array1[i];
    }
    for (int i = 0; i < size2; ++i) {
        result[size1 + i] = array2[i];
    }
}

int main() {
    // Example 1: Integer arrays
    int intArray1[] = {1, 2, 3};
    int intArray2[] = {4, 5, 6};
    int intSize1 = 3, intSize2 = 3;
    int intResult[6];

    concatenateArrays(intArray1, intSize1, intArray2, intSize2, intResult);

    cout << "Concatenated Integer Array: ";
    for (int i = 0; i < intSize1 + intSize2; ++i) {
        cout << intResult[i] << " ";
    }
    cout << endl;

    // Example 2: String arrays
    string strArray1[] = {"Hello", "World"};
    string strArray2[] = {"C++", "Templates"};
    int strSize1 = 2, strSize2 = 2;
    string strResult[4];

    concatenateArrays(strArray1, strSize1, strArray2, strSize2, strResult);

    cout << "Concatenated String Array: ";
    for (int i = 0; i < strSize1 + strSize2; ++i) {
        cout << strResult[i] << " ";
    }
    cout << endl;

    return 0;
}
