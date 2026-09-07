#include <iostream>
using namespace std;
int main() {
    int lower_limit, upper_limit, i, num;
    cout << "Enter the lower limit: ";
    cin >> lower_limit;
    cout << "Enter the upper limit: ";
    cin >> upper_limit;

    cout << "Factors of numbers between " << lower_limit << " and " << upper_limit << " are:\n";
    for (num = lower_limit; num <= upper_limit; num++) {
        cout << "Factors of " << num << " are: ";
        for (i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                if (num / i == i)
                    cout << i << " ";
                else
                    cout << i << " " << num / i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

