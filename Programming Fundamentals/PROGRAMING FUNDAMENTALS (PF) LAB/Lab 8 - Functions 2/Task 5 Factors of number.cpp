#include <iostream>
using namespace std;

// Function to find the factors of a given number
void findFactors(int findFactors1) {
    cout << "Factors of " << findFactors1 << " are: ";
    for (int i = 1; i <= findFactors1; ++i) {
        if (findFactors1 % i == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    findFactors(n);
    return 0;
}

