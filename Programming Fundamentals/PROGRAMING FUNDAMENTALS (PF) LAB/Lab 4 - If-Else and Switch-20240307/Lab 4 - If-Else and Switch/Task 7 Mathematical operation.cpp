#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: division by zero." << endl;
            }
            else {
                cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
            }
            break;
        default:
            cout << "Invalid operator entered." << endl;
            break;
    }

    return 0;
}

