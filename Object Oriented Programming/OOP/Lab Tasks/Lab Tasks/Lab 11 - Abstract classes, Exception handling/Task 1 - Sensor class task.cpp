#include <iostream>
#include <string>
using namespace std;

// Abstract class Sensor
class Sensor {
protected:
    string sensorName;
    float currentReading;
public:
    Sensor(string name, float reading) : sensorName(name), currentReading(reading) {}

    virtual void analyzeData() = 0; // Pure virtual function
    virtual ~Sensor() {} // Virtual destructor
};

// Derived class: TemperatureSensor
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(string name, float reading) : Sensor(name, reading) {}

    void analyzeData() override {
        cout << "\nSensor: " << sensorName << " (Temperature)";
        cout << "\nCurrent Reading: " << currentReading << "°C";
        if (currentReading < 0 || currentReading > 100) {
            cout << "\nStatus: ALERT! Temperature out of range (0-100°C).\n";
        } else {
            cout << "\nStatus: Temperature is within safe range.\n";
        }
    }
};

// Derived class: PressureSensor
class PressureSensor : public Sensor {
public:
    PressureSensor(string name, float reading) : Sensor(name, reading) {}

    void analyzeData() override {
        cout << "\nSensor: " << sensorName << " (Pressure)";
        cout << "\nCurrent Reading: " << currentReading << " psi";
        if (currentReading < 10 || currentReading > 200) {
            cout << "\nStatus: ALERT! Pressure out of range (10-200 psi).\n";
        } else {
            cout << "\nStatus: Pressure is within safe range.\n";
        }
    }
};

int main() {
    // Array of Sensor pointers
    const int NUM_SENSORS = 4;
    Sensor* sensors[NUM_SENSORS];

    // Initialize sensors
    sensors[0] = new TemperatureSensor("TempSensor_1", 25.5);   // Safe range
    sensors[1] = new TemperatureSensor("TempSensor_2", 105.0);  // Out of range
    sensors[2] = new PressureSensor("PressureSensor_1", 50.0);  // Safe range
    sensors[3] = new PressureSensor("PressureSensor_2", 250.0); // Out of range

    // Analyze data from all sensors
    cout << "\n=== Sensor Data Analysis ===\n";
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i]->analyzeData();
    }

    // Free allocated memory
    for (int i = 0; i < NUM_SENSORS; i++) {
        delete sensors[i];
    }

    return 0;
}
