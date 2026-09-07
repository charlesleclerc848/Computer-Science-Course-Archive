#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the first element as pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Move i to the right until an element greater than pivot is found
        while (pivot >= arr[i] && i < high) {
            i++;
        }

        // Move j to the left until an element less than or equal to pivot is found
        while (pivot < arr[j] && j > low) {
            j--;
        }

        // Swap elements if i < j
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot element at its correct position
    swap(arr[low], arr[j]);
    return j; // Return the index of pivot
}

// Recursive function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find pivot's correct position
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Main function
int main() {
    int arr[] = {2, 6, 5, 1, 3, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call quick sort function
    quickSort(arr, 0, arrSize - 1);

    cout << "After Sorting: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
