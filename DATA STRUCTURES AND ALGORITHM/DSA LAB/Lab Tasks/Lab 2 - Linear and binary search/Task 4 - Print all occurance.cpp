#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllOccurrences(int arr[], int size, int target) {
    vector<int> indices;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            indices.push_back(i); // Store index of occurrence
        }
    }
    return indices;
}

int main() {
    int arr[] = {10, 25, 30, 25, 50, 65, 25, 95, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    vector<int> indices = findAllOccurrences(arr, size, target);

    if (!indices.empty()) {
        cout << "Element " << target << " found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
