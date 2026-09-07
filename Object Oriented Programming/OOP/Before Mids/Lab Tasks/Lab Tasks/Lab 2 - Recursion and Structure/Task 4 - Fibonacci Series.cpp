#include <iostream>
using namespace std;
// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1)  // Base case: fib(0) = 0, fib(1) = 1
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}
int main() {
    int n;
    cout << "Enter the number of terms for the Fibonacci series: ";
    cin >> n;  
    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";  // Print Fibonacci numbers
    }
    cout << endl;
    return 0;
}

