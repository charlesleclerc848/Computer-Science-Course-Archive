#include <iostream>
#include <string>
using namespace std;

// Abstract class DeliveryVehicle
class DeliveryVehicle {
protected:
    string vehicleID;
    float distanceTravelled;
public:
    DeliveryVehicle(string id, float distance) : vehicleID(id), distanceTravelled(distance) {}
    virtual float calculateFuelCost() = 0; // Pure virtual function
    void checkMaintenance() {
        if (distanceTravelled > 500) 
            cout << "Vehicle " << vehicleID << ": Maintenance Required\n";
    }
    virtual void displayInfo() = 0;
    virtual ~DeliveryVehicle() {}
};

// Truck class
class Truck : public DeliveryVehicle {
public:
    Truck(string id, float distance) : DeliveryVehicle(id, distance) {}
    float calculateFuelCost() override {
        return distanceTravelled / 5.0 * 1.5; // Assuming 1.5 is fuel price per liter
    }
    void displayInfo() override {
        cout << "Truck " << vehicleID << " | Distance: " << distanceTravelled 
             << " km | Fuel Cost: $" << calculateFuelCost() << endl;
        checkMaintenance();
    }
};

// Motorcycle class
class Motorcycle : public DeliveryVehicle {
public:
    Motorcycle(string id, float distance) : DeliveryVehicle(id, distance) {}
    float calculateFuelCost() override {
        return distanceTravelled / 15.0 * 1.5; // Assuming 1.5 is fuel price per liter
    }
    void displayInfo() override {
        cout << "Motorcycle " << vehicleID << " | Distance: " << distanceTravelled 
             << " km | Fuel Cost: $" << calculateFuelCost() << endl;
        checkMaintenance();
    }
};

int main() {
    const int NUM_VEHICLES = 4;
    DeliveryVehicle* vehicles[NUM_VEHICLES];

    // Initialize vehicles
    vehicles[0] = new Truck("T001", 600);
    vehicles[1] = new Motorcycle("M001", 200);
    vehicles[2] = new Truck("T002", 450);
    vehicles[3] = new Motorcycle("M002", 550);

    // Process vehicles
    cout << "=== Vehicle Information ===\n";
    for (int i = 0; i < NUM_VEHICLES; i++) {
        vehicles[i]->displayInfo();
    }

    // Free memory
    for (int i = 0; i < NUM_VEHICLES; i++) {
        delete vehicles[i];
    }
    return 0;
}
