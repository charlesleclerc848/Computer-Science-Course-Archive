#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    friend double calculateArea(const Rectangle& rect);
};

double calculateArea(const Rectangle& rect) {
    return rect.length * rect.width;
}

int main() {
    Rectangle rect(5.0, 3.5);
    cout << "The area of the rectangle is: " << calculateArea(rect) << endl;
    return 0;
}

