#include <iostream>
using namespace std;

class Shallow {
public:
    int* data;

    // Constructor
    Shallow(int d) {
        data = new int;
        *data = d;
    }

    // Shallow Copy Constructor (Default behavior)
    Shallow(Shallow& source) {
		data = source.data; 
        cout << "Shallow copy constructor - Copying pointer, not data." << endl;
    }

    // Destructor
    ~Shallow() {
        delete data;  // Problem: Both objects will try to delete the same memory
        cout << "Destructor freeing data." << endl;
    }

    void display() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    Shallow obj1(100);
    obj1.display();

    Shallow obj2 = obj1;  // Shallow copy
    obj2.display();       // Same memory is shared

    return 0;
}

