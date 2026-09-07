#include <iostream>
using namespace std;

void isPerfectSquare(int n) {
    for(int i = 1; i < n; i++) {
        if (i * i == n) {
        	cout << n << " is a perfect square of "<<i << endl;
            return;
        }
    }
    cout << n << " is not a perfect square." << endl;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    isPerfectSquare(num);
    return 0;
}

