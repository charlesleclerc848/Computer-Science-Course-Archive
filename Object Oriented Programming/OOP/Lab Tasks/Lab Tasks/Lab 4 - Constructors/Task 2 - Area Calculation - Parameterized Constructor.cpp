// C++ program to calculate the area of a wall

#include <iostream>
using namespace std;

// declare a class
class Wall {
  private:
    double length;
    double height;

  public:
    // parameterized constructor to initialize variables
    Wall(double len, double hgt) {
      length = len;
      height = hgt;
    }

    double calculateArea() {
      return length * height;
    }
};

int main() {
  // create object and initialize data members
  Wall w1(10.5, 8.6);
  Wall w2(8.5, 6.3);

  cout << "Area of Wall 1: " << w1.calculateArea() << endl;
  cout << "Area of Wall 2: " << w2.calculateArea();

  return 0;
}
