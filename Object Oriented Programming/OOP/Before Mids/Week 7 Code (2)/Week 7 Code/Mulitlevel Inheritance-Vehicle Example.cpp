#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string fuelType; // Protected attribute, accessible in derived classes
public:
    void setFuelType(string type) {
        fuelType = type;
    }
};

// Derived class from Vehicle
class Car : public Vehicle {
protected:
    string brand;
public:
    void setBrand(string b) {
        brand = b;
    }
};

// Derived class from Car
class ElectricCar : public Car {
public:
    void showDetails() {
//        fuelType = "Electric"; // Accessing protected attribute from Vehicle
        cout << "Brand: " << brand << ", Fuel Type: " << fuelType << endl;
    }
};

int main() {
    ElectricCar tesla;
    tesla.setFuelType("abc");
    tesla.setBrand("Tesla"); // Set brand in Car
    tesla.showDetails();      // Display brand and fuel type
    return 0;
}

