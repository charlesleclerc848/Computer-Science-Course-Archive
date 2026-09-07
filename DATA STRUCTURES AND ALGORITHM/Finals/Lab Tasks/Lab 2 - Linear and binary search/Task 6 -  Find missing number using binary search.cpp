#include <iostream>
using namespace std;

// Function to find the missing number using Binary Search
int findMissingNumber(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // If the index and value match, the missing number is in the right half
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1; // Otherwise, it's in the left half
        }
    }

    return left + 1; // Missing number is at position (left + 1)
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10}; // Missing 5
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, size);
    cout << "Missing number is: " << missingNumber << endl;

    return 0;
}
