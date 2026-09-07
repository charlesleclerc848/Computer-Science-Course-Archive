#include <iostream>
using namespace std;

class Date {
public:
    int month;
    int day;
    int year;

    // Parameterized constructor
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    // Function to display the date
    void display() {
        cout << "Date: " << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    // Array of pointers to Date objects
    Date* dates[31];

    // Dynamically allocate Date objects for each day in March 2024
    for (int day = 0; day < 31; ++day) {
        dates[day] = new Date(3, day + 1, 2024);  // day + 1 to start from March 1
    }

    // Display all the dates
    for (int day = 0; day < 31; ++day) {
        dates[day]->display();
    }

    // Free the dynamically allocated memory
    for (int day = 0; day < 31; ++day) {
        delete dates[day];
    }

    return 0;
}

