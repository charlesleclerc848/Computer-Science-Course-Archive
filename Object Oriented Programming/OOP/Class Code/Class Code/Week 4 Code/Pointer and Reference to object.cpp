#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    Car(string b, int y) {
        brand = b;
        year = y;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Toyota", 2010);  // Normal object
    Car* ptr = &car1;          // Pointer to object
    Car &ref = car1;			// Reference to object

	// Accessing object members using normal object
	car1.display();

    // Accessing object members using pointer
    ptr->display();
    
    // Accessing object members using reference to an object
    ref.display();

    return 0;
}

