#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    // Overload the unary - operator to negate the number
    Number operator-() {
        Number temp;
        temp.value = -value;
        return temp;
    }
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num1(10);
    cout << "Before negation \n";
    num1.display();

    Number num2 = -num1;
    cout << "After negation \n";
    num2.display();

    return 0;
}
