
#include <iostream>
using namespace std;

int main() {
    int n, first = 0, second = 1, next, i = 2;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: " << first << " " << second << " ";

    do {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
        i++;
    } while (i < n);

    return 0;
}

