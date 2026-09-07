#include <iostream>
using namespace std;

int main() {
    int num, factorial = 1, i = 1;
    cout << "Enter a positive integer: ";
    cin >> num;
    while (i <= num) {
        factorial *= i;
        i++;
    }
    cout << "Factorial of " << num << " is: " << factorial << endl;
    return 0;
}

