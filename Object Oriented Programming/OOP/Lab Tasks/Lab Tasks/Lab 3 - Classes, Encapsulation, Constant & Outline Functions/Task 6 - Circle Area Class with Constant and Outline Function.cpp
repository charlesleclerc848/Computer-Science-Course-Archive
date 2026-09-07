#include<iostream>
using namespace std;

class Circle {
private:
    const double PI = 3.14159;
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    double getArea() const;
};

double Circle::getArea() const {
    return PI * radius * radius;
}

int main() {
    Circle circle;
    circle.setRadius(5.0);  // Set the radius

    cout << "Area of the circle: " << circle.getArea() << endl;

    return 0;
}

