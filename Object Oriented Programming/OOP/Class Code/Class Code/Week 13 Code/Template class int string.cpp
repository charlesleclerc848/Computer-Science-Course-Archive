#include <iostream>
using namespace std;

template <typename T>
class Container {
    T value; // Single data member of type T

public:
    Container(T val) : value(val) {}
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Container<int> intContainer(100);
    Container<string> stringContainer("Hello, Templates");

    intContainer.display();
    stringContainer.display();

    return 0;
}
