#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    // Overloading the '==' operator
    bool operator==(const Point &other) const {
        return (x == other.x && y == other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(2, 3);
    Point p2(2, 3);
    Point p3(4, 5);

    if (p1 == p2)
        cout << "p1 and p2 are equal." << endl;
    else
        cout << "p1 and p2 are not equal." << endl;

    if (p1 == p3)
        cout << "p1 and p3 are equal." << endl;
    else
        cout << "p1 and p3 are not equal." << endl;

    return 0;
}
