#include <iostream>
using namespace std;

// Merge two subarrays L and R into arr
void merge(int arr[], int left, int mid, int right) {
    // Sizes of two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];       // left half: arr[left...mid]
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];    // right half: arr[mid+1...right]

    // Merge the two temporary arrays back into arr[left...right]
    int i = 0, j = 0, k = left;
    
    // Compare elements of L and R, and copy the smaller one
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements of L[] if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements of R[] if any
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = (left + right) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Driver function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform merge sort
    mergeSort(arr, 0, size - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
