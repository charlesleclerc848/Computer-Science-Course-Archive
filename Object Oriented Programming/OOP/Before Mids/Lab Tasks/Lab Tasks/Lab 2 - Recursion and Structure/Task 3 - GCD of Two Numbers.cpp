#include <iostream>
using namespace std;

// Recursive function to find the GCD of two numbers
int gcd(int x, int y) {
    if (x % y == 0) // Base case: If y divides x, return y
        return y;
    else
        return gcd(y, x % y); // Recursive case: Call gcd with y and remainder
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Call the gcd function and print the result
    cout << "The GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;

    return 0;
}

