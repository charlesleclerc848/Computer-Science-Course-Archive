#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overloading the '-' operator
    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(5.5, 4.3);
    Complex c2(2.2, 3.1);

    Complex c3 = c1 - c2;

    cout << "First Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();
    cout << "Result after subtraction: ";
    c3.display();

    return 0;
}
