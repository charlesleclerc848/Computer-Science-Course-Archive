#include <iostream>
using namespace std;

template <typename T>
T calculateAverage(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {2.5, 3.5, 4.5, 5.5, 6.5};

    cout << "Average of int array is : " << calculateAverage(intArr, 5) << endl;
    cout << "Average of double array is : " << calculateAverage(doubleArr, 5) << endl;

    return 0;
}
