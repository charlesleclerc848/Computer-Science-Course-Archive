#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Constructor that takes hours and minutes
    Time(int h, int m) {
        hours = h;
        minutes = m;
    }

    // Constructor that takes total minutes and converts it into hours and minutes
    Time(int totalMinutes) {
        hours = totalMinutes / 60;
        minutes = totalMinutes % 60;
    }

    // Function to display time in HH:MM format
    void display() {
        cout << "Time: " << hours << " hours and " << minutes << " minutes" << endl;
    }
};

int main() {
    Time t1(2, 45);      // Constructor with hours and minutes
    Time t2(130);        // Constructor with total minutes
    
    cout << "Time 1: ";
    t1.display();

    cout << "Time 2: ";
    t2.display();

    return 0;
}

