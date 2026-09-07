#include <iostream>
using namespace std;

int main() {
    int lowerLimit = 100, upperLimit = 200;
    int count = 0;

    for (int num = lowerLimit; num <= upperLimit; num++) {
        int reversedNum = 0;

        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            reversedNum = reversedNum * 10 + digit;
            temp /= 10;
        }

        if (num == reversedNum) {
            count++;
            cout<<"No. "<<count<<" palindromic number is : "<<num<<endl;
        }
    }

    cout << "Number of palindromic numbers in the range: " << count << endl;

    return 0;
}

