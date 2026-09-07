#include <iostream>
#include <cmath>

using namespace std;

double power(double n, int p = 2) {
    return pow(n, p);
}

int main() {
    double n;
    int p;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter a power: ";
    cin >> p;
    cout << n << " raised to the power of " << p << " is " << power(n, p) << endl;
    cout << n << " squared is " << power(n) << endl;
    return 0;
}

