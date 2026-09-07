#include <iostream>
using namespace std;

int main() {
    int binary, decimal = 0, base = 1, rem;
    cout << "Enter the binary number: ";
    cin >> binary;
    
    do {
        rem = binary % 10;
        decimal += rem * base;
        base *= 2;
        binary /= 10;
        
    } while(binary > 0);
    
    cout << "Decimal equivalent is: " << decimal;
    return 0;
}

