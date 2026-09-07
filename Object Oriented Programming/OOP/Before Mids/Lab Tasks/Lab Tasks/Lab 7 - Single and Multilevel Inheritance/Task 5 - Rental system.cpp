#include <iostream>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string model;
    double baseRate;

public:
    // Constructor for Vehicle class
    Vehicle(int id, string m, double rate) : vehicleID(id), model(m), baseRate(rate) {}

    void displayVehicle() {
        cout << "Vehicle ID: " << vehicleID << ", Model: " << model << ", Base Rate: $" << baseRate << endl;
    }
};

class Car : public Vehicle {
protected:
    string carType;  // e.g., SUV, sedan
    int seatingCapacity;

public:
    // Constructor for Car class
    Car(int id, string m, double rate, string type, int capacity) 
        : Vehicle(id, m, rate), carType(type), seatingCapacity(capacity) {}

    void displayCar() {
        displayVehicle();
        cout << "Car Type: " << carType << ", Seating Capacity: " << seatingCapacity << endl;
    }
};

class LuxuryCar : public Car {
    double luxuryTax;
    bool chauffeurAvailability;

public:
    // Constructor for LuxuryCar class
    LuxuryCar(int id, string m, double rate, string type, int capacity, double tax, bool chauffeur) 
        : Car(id, m, rate, type, capacity), luxuryTax(tax), chauffeurAvailability(chauffeur) {}

    // Method to calculate total rental cost
    double calculateTotalRentalCost() {
        double chauffeurCharge = chauffeurAvailability ? 100.0 : 0.0;
        return baseRate + luxuryTax + chauffeurCharge;
    }

    void displayLuxuryCar() {
        displayCar();
        cout << "Luxury Tax: $" << luxuryTax 
             << ", Chauffeur Available: " << (chauffeurAvailability ? "Yes" : "No") 
             << ", Total Rental Cost: $" << calculateTotalRentalCost() << endl;
    }
};

// Main function to demonstrate the classes
int main() {
    LuxuryCar luxCar(101, "BMW 7 Series", 300.0, "Sedan", 5, 50.0, true);

    cout << "Luxury Car Details:" << endl;
    luxCar.displayLuxuryCar();

    return 0;
}

