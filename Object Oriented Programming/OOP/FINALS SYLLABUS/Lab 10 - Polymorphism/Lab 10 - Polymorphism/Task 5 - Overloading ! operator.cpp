#include <iostream>
using namespace std;

class Boolean {
private:
    bool value;

public:
    Boolean(bool v) : value(v) {}
    Boolean(){}

    // Overload the ! operator to invert the boolean value
    Boolean operator!() {
    	Boolean temp;
    	temp.value = !value;
        return temp;
    }

    void display() {
        cout << (value ? "true" : "false") << endl;
    }
};

int main() {
    Boolean b1(true);
    cout << "Original value: ";
    b1.display();

    Boolean b2 = !b1;
    cout << "Inverted value: ";
    b2.display();

    return 0;
}
