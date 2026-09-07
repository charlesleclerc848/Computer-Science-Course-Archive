#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds, totalSeconds;

    cout << "Enter time in hours, minutes, and seconds:" << endl;
    cout << "Hours: ";
    cin >> hours;
    cout << "Minutes: ";
    cin >> minutes;
    cout << "Seconds: ";
    cin >> seconds;

    // Calculate the total time in seconds
    totalSeconds = hours * 3600 + minutes * 60 + seconds;

    // Output the result
    cout << "The equivalent time in seconds is: " << totalSeconds << " seconds" << endl;

    return 0;
}

