#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int firstNum, secondNum;
    int oddSum = 0, evenSum = 0, oddSquareSum = 0;

    cout << "Enter first integer: ";
    cin >> firstNum;

    cout << "Enter second integer (must be greater than first integer): ";
    cin >> secondNum;

    // Output all odd numbers between firstNum and secondNum
    cout << "Odd numbers between " << firstNum << " and " << secondNum << ":\n";
    for (int i = firstNum; i <= secondNum; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Output the sum of all even numbers between firstNum and secondNum
    cout << "Sum of even numbers between " << firstNum << " and " << secondNum << ":\n";
    for (int i = firstNum; i <= secondNum; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        }
    }
    cout << evenSum << endl;

    // Output the numbers and their squares between firstNum and secondNum
    cout << "Numbers and their squares between " << firstNum << " and " << secondNum << ":\n";
    for (int i = firstNum; i <= secondNum; i++) {
        cout << i << " " << pow(i, 2) << endl;
    }

    // Output the sum of the square of the odd numbers between firstNum and secondNum
    cout << "Sum of the squares of odd numbers between " << firstNum << " and " << secondNum << ":\n";
    for (int i = firstNum; i <= secondNum; i++) {
        if (i % 2 != 0) {
            oddSquareSum += pow(i, 2);
        }
    }
    cout << oddSquareSum << endl;
    return 0;
}
