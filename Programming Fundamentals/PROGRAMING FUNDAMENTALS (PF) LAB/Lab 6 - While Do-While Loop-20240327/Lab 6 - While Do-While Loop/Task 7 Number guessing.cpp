#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int target = rand() % 100 + 1;
    int guess, attempts = 0;

    do {
        cout << "Guess the number (1-100): ";
        cin >> guess;
        attempts++;

        if (guess < target) {
            cout << "Too low. Try again." << endl;
        } else if (guess > target) {
            cout << "Too high. Try again." << endl;
        } else {
            cout << "Congratulations! You guessed it in " << attempts << " attempts." << endl;
        }
    } while (guess != target);

    return 0;
}

