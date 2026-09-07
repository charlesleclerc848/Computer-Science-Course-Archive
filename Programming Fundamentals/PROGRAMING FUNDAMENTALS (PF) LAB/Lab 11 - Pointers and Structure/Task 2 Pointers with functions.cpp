#include <iostream>
using namespace std;

void add(int* a, int* b) {
    int result = *a + *b;
    cout << "Sum: " << result << endl;
}

void subtract(int* a, int* b) {
    int result = *a - *b;
    cout << "Difference: " << result << endl;
}

void multiply(int* a, int* b) {
    int result = *a * *b;
    cout << "Product: " << result << endl;
}

int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    add(&num1, &num2);
    subtract(&num1, &num2);
    multiply(&num1, &num2);

    return 0;
}

