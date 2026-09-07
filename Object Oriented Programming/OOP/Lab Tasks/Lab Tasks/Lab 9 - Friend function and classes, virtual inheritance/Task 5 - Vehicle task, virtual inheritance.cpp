#include <iostream>
using namespace std;

class Vehicle {
protected:
    string make, model;

public:
    Vehicle(string mk = "", string mdl = "") : make(mk), model(mdl) {}

    void showDetails() {
        cout << "Make: " << make << ", Model: " << model << endl;
    }
};

class Car : virtual public Vehicle {
protected:
    int numDoors;

public:
    Car(string mk, string mdl, int doors) : Vehicle(mk, mdl), numDoors(doors) {}

    void showDetails() {
        cout << "Car Details: ";
        Vehicle::showDetails();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class Truck : virtual public Vehicle {
protected:
    int loadCapacity;

public:
    Truck(string mk, string mdl, int capacity) : Vehicle(mk, mdl), loadCapacity(capacity) {}

    void showDetails() {
        cout << "Truck Details: ";
        Vehicle::showDetails();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

class PickupTruck : public Car, public Truck {
public:
    PickupTruck(string mk, string mdl, int doors, int capacity)
        : Vehicle(mk, mdl), Car(mk, mdl, doors), Truck(mk, mdl, capacity) {}

    void showDetails() {
        cout << "Pickup Truck Details:" << endl;
        Vehicle::showDetails();
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() {
    PickupTruck pickup("Toyota", "Hilux", 4, 1);
    pickup.showDetails();

    return 0;
}

