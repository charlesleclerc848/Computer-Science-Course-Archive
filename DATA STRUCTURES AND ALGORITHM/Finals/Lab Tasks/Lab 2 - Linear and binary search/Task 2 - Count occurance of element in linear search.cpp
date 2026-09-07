#include <iostream>
using namespace std;

int countOccurrences(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {10, 25, 30, 25, 50, 65, 25, 95, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int occurrences = countOccurrences(arr, size, target);

    if (occurrences > 0) {
        cout << "Element " << target << " appears " << occurrences << " times in the array." << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
