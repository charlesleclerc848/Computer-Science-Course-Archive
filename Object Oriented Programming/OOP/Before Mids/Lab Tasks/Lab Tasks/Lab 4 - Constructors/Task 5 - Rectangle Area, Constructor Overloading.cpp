#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    // Default constructor
    Rectangle() {
        length = 1;
        width = 1;
    }

    // Parameterized constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    // Constructor for square (same length and width)
    Rectangle(int side) {
        length = side;
        width = side;
    }

    // Function to display the dimensions of the rectangle
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    Rectangle rect1;          // Default constructor
    Rectangle rect2(5, 10);   // Parameterized constructor
    Rectangle square(4);      // Constructor for square

    cout << "Rectangle 1: ";
    rect1.display();

    cout << "Rectangle 2: ";
    rect2.display();

    cout << "Square: ";
    square.display();

    return 0;
}

