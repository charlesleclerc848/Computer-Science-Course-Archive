#include <iostream>
using namespace std;

int main() {
    int num, largest, smallest;
    cout << "Enter a series of integers (-99 to stop): ";
    cin >> num;
    largest = smallest = num;
    while (num != -99) {
        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
        cin >> num;
    }
    cout << "Largest number entered: " << largest << endl;
    cout << "Smallest number entered: " << smallest << endl;
    return 0;
}
