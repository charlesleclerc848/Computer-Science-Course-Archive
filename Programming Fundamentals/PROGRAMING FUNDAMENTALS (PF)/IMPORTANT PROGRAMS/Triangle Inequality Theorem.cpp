#include <iostream>
using namespace std;
int main() {
    double side1, side2, side3;

    do {
        cout << "Enter the lengths of the sides of the triangle:\n";
        cout << "Side 1: ";
        cin >> side1;

        cout << "Side 2: ";
        cin >> side2;

        cout << "Side 3: ";
        cin >> side3;

        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            cout << "Invalid side lengths! The sum of any two sides must be greater than the length of the third side.\n";
        }
    } while (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1);

    double perimeter = side1 + side2 + side3;
    cout << "The perimeter of the triangle is: " << perimeter;

    return 0;
}

