#include <iostream>
#include <string>
using namespace std;
// Template function for Selection Sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
				minIndex = j;
            }
        }
        // Swap elements
		  if (minIndex != i) {
        	T temp = arr[i];  
        	arr[i] = arr[minIndex];
        	arr[minIndex] = temp;
		  }
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
    selectionSort(intArr, n);
    cout << "After sorting (integers): ";
    printArray(intArr, n);
    return 0;
}
