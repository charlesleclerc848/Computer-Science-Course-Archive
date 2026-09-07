#include <iostream>
using namespace std;

template <class T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 10 and 20 is : " << findMax(10, 20) << endl;
    cout << "Max of 10.5 and 7.3 is : " << findMax(10.5, 7.3) << endl;
    cout << "Max of 'A' and 'B' is : " << findMax('A', 'B') << endl;
    return 0;
}
