#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

int main() {
    int arr[] = {10, 25, 30, 45, 50, 65, 80, 95};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    linearSearch(arr, size, target);
    
    return 0;
}
