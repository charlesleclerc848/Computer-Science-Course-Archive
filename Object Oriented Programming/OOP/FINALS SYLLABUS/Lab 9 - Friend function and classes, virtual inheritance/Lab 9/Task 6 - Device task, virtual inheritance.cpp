#include <iostream>
using namespace std;

class Device {
protected:
    string brand, model;

public:
    Device(string b = "", string m = "") : brand(b), model(m) {}

    void powerOn() {
        cout << "Powering on " << brand << " " << model << " device." << endl;
    }
};

class Smartphone : virtual public Device {
protected:
    int batteryLife;

public:
    Smartphone(string b, string m, int battery) : Device(b, m), batteryLife(battery) {}

    void powerOn() {
        cout << "Smartphone is powering on. Battery life: " << batteryLife << " hours." << endl;
    }
};

class Laptop : virtual public Device {
protected:
    bool hasTouchscreen;

public:
    Laptop(string b, string m, bool touchscreen) : Device(b, m), hasTouchscreen(touchscreen) {}

    void powerOn() {
        cout << "Laptop is powering on. Touchscreen: " << (hasTouchscreen ? "Yes" : "No") << endl;
    }
};

class HybridDevice : public Smartphone, public Laptop {
public:
    HybridDevice(string b, string m, int battery, bool touchscreen)
        : Device(b, m), Smartphone(b, m, battery), Laptop(b, m, touchscreen) {}

    void powerOn() {
        cout << "Hybrid Device Information:" << endl;
        Device::powerOn();
        cout << "Battery Life: " << batteryLife << " hours." << endl;
        cout << "Touchscreen: " << (hasTouchscreen ? "Yes" : "No") << endl;
    }
};

int main() {
    HybridDevice hybrid("Apple", "iPad Pro", 10, true);
    hybrid.powerOn();

    return 0;
}

