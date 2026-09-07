#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int upperLimit;

    cout << "Enter the upper limit: ";
    cin >> upperLimit;

    cout << "The series (1,3,9,27,81...n) is : ";
    for (int i = 0; pow(3, i) <= upperLimit; i++) {
        cout << pow(3, i) << " ";
    }

    cout << endl << endl;
    
    cout << "The series (1,2,3,0,5,6,7,0,9...n) is: ";
    for (int j = 1; j <= upperLimit; j++) {
    	cout<<j<<" = "<<j%10<<endl;
        if (j % 10 == 4 || j % 10 == 8) {
            cout << "0 ";
        } else {
            cout << j << " ";
        }
    }

    cout << endl;

    return 0;
}

