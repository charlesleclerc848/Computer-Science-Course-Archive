#include <iostream>
using namespace std;

// Merge two sorted halves into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left half
    int n2 = right - mid;     // Size of right half

    int L[n1];
    int R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) 
		L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
		R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
			arr[k++] = L[i++];
        else 
			arr[k++] = R[j++];
    }

    // Copy remaining elements of L[]
    while (i < n1) 
		arr[k++] = L[i++];

    // Copy remaining elements of R[]
    while (j < n2) 
		arr[k++] = R[j++];
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half
        merge(arr, left, mid, right);    // Merge sorted halves
    }
}

// Display array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) 
		cout << arr[i] << " ";
    cout << endl;
}

// Display top 5 and bottom 5 scores
void displayTopBottom(int arr[], int size) {
    cout << "\nTop 5 scores: ";
    for (int i = size - 1, count = 0; i >= 0 && count < 5; i--, count++) {
		cout << arr[i] << " ";
	}
	cout << endl;

    cout << "\nBottom 5 scores: ";
    for (int i = 0; i <= 4; i++) 
		cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int scores[] = {72, 85, 90, 65, 78, 99, 58, 88, 94, 60, 70, 83, 76, 89, 91};
    int n = sizeof(scores) / sizeof(scores[0]);

    cout << "Original scores:\n";
    display(scores, n);

    mergeSort(scores, 0, n - 1);

    cout << "\nSorted scores (ascending):\n";
    display(scores, n);

    displayTopBottom(scores, n);

    return 0;
}
