#include<iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(5.0, 3.0);  // Set length and width

    cout << "Area of the rectangle: " << rect.getArea() << endl;

    return 0;
}

