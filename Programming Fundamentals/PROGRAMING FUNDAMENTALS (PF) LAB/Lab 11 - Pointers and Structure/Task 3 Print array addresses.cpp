#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    cout << "Addresses of the elements in the array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i + 1 << ": " << ptr << endl;
        ptr++;
    }

    return 0;
}

