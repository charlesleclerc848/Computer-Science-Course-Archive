#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of 5 and 10 is : " << add(5, 10) << endl;        // T is int
    cout << "Sum of 3.5 and 2.5 is : " << add(3.5, 2.5) << endl; // T is double
    return 0;
}
