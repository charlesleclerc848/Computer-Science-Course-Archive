#include <iostream>
#include <iomanip>
using namespace std;

void threeTimesDecimal(double num) {
    double result = num * 3;
    cout << fixed << setprecision(3) << "3 times " << num << " is " << result << endl;
}

int main() {
    double decimalNum;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;
    threeTimesDecimal(decimalNum);
    return 0;
}

