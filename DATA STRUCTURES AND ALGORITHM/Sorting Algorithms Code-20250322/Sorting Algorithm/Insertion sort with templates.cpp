#include <iostream>
#include <string>
using namespace std;

// Template function for Insertion Sort
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];  // Store the current element
        int j = i - 1;
        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Insert the element in the correct position
    }
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
	  int intArr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Before sorting (integers): ";
    printArray(intArr, n);
    insertionSort(intArr, n);
    cout << "After sorting (integers): ";
    printArray(intArr, n);
    return 0;
}
