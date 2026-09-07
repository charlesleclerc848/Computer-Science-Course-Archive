#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, i;
    char choice;

    do {
        bool isPrime = true;
        
        cout << "Enter a number: ";
        cin >> num;

        if (num == 0 || num == 1) {
            isPrime = false;
        }

        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " is a prime number." << endl;
        } else {
            cout << num << " is not a prime number." << endl;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting program." << endl;

    return 0;
}

