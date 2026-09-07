#include <iostream>
#include <cmath>
using namespace std;

bool checkPower(double num1, double num2, double num3) {
    if (pow(num1, num2) == num3) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double num1, num2, num3;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;
    
    if (checkPower(num1, num2, num3)) {
        cout << num1 << " to the power of " << num2 << " equals " << num3 << endl;
    } else {
        cout << num1 << " to the power of " << num2 << " does not equal " << num3 << endl;
    }    
    return 0;
}

