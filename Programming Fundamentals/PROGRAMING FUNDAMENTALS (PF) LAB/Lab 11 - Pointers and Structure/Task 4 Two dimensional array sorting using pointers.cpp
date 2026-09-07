#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void sort2DArray(int* arr, int rows, int cols) {
    int* ptr = arr;
    int size = rows * cols;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                // Swap the elements using pointers
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

void display2DArray(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(arr + i * cols + j) << " ";
        }
        cout << endl;
    }
}

int main() {

    int arr[ROWS][COLS] = {
        {9, 8, 6},
        {5, 4, 3},
        {0, -1, -2}
    };

    int* ptr = &arr[0][0];

    cout << "Before sorting:" << endl;
    display2DArray(ptr, ROWS, COLS);

    sort2DArray(ptr, ROWS, COLS);

    cout << "\nAfter sorting:" << endl;
    display2DArray(ptr, ROWS, COLS);

    return 0;
}

