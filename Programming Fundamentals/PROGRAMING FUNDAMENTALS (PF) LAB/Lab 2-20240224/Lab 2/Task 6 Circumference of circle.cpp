#include <iostream>
using namespace std;

int main() {
    double radius;
    double circumference;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Compute the circumference using the formula C = 2 * pi * r
    circumference = 2 * 3.14159 * radius;

    // Output the circumference
    cout << "The circumference of the circle is " << circumference << endl;

    return 0;
}

