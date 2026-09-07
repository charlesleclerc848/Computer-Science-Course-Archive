#include <iostream>

using namespace std;

int main() {
    int year;
    cout << "Enter year of birth: ";
    cin >> year;

    int offset = year - 1900;

    switch (offset % 12) {
        case 0:
            cout << "Rat\n";
            break;
        case 1:
            cout << "Ox\n";
            break;
        case 2:
            cout << "Tiger\n";
            break;
        case 3:
            cout << "Rabbit\n";
            break;
        case 4:
            cout << "Dragon\n";
            break;
        case 5:
            cout << "Snake\n";
            break;
        case 6:
            cout << "Horse\n";
            break;
        case 7:
            cout << "Goat\n";
            break;
        case 8:
            cout << "Monkey\n";
            break;
        case 9:
            cout << "Rooster\n";
            break;
        case 10:
            cout << "Dog\n";
            break;
        case 11:
            cout << "Boar\n";
            break;
    }

    return 0;
}

