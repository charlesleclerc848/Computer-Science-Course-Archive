#include <iostream>
using namespace std;

class Deep {
public:
    int* data;  // Pointer to an integer

    // Constructor
    Deep(int value) {
        data = new int;  // Allocate memory
        *data = value;   // Assign value
    }

    // Deep Copy Constructor
    Deep(const Deep& source) {
        data = new int;  // Allocate new memory
        *data = *(source.data);  // Copy the actual value
        cout << "Deep Copy: New memory allocated, and value copied." << endl;
    }

    // Destructor
    ~Deep() {
        delete data;  // Memory is safely freed
        cout << "Destructor called, memory freed." << endl;
    }

    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    Deep obj1(100);  // Create first object
    Deep obj2 = obj1;  // Deep copy

    obj1.display();  // Displays 100
    obj2.display();  // Displays 100 (but uses separate memory)

    // No issues when destructors are called, as each object has its own memory
    return 0;
}

