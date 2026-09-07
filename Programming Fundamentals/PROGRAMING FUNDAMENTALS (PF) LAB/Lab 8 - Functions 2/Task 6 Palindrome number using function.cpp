#include <iostream>
using namespace std;

bool palindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;

    // Reversing the number
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num = num / 10;
    }

    // Comparing original number with reversed number
    if (originalNum == reversedNum) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (palindrome(num)) {
        cout << "The number is a palindrome." << endl;
    }
    else {
        cout << "The number is not a palindrome." << endl;
    }
    return 0;
}

