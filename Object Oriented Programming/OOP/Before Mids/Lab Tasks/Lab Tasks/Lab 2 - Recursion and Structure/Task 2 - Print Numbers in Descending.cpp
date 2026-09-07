#include <iostream>
using namespace std;

// Recursive function to print numbers in descending order
void printDescending(int n) {
    if (n <= 0) // Base case: Stop if n is 0 or negative
        return;

    cout << n << " ";  // Print the current number
    printDescending(n - 1);  // Recursive call with n-1
}

int main() {
    int num;
    cout << "Enter a positive number: ";
    cin >> num;

    // Call the function to print numbers in descending order
    printDescending(num);

    return 0;
}

