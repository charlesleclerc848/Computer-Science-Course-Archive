#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Area of Shape" << endl;
    }
};

class Rectangle : public Shape {
private:
    int length, width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    void area() override {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

int main() {
    Shape* shapePtr;
    Rectangle rect(4, 5);
    Circle circ(3);

    shapePtr = &rect;
    shapePtr->area();

    shapePtr = &circ;
    shapePtr->area();

    return 0;
}
