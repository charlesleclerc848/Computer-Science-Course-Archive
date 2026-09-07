#include <iostream>
using namespace std;

class Engine {
public:
    string model;

    Engine(string model) : model(model) {
        cout << "Engine " << model << " created." << endl;
    }
    ~Engine() {
        cout << "Engine " << model << " destroyed." << endl;
    }
};

class Car {
public:
    string brand;
    Engine engine; // Composition: Car owns Engine

    Car(string brand, string engineModel) : brand(brand), engine(engineModel) {
        cout << brand << " car created with engine model " << engine.model << "." << endl;
    }
    ~Car() {
        cout << brand << " car destroyed." << endl;
    }

    void start() {
        cout << brand << " car is starting with engine model " << engine.model << "." << endl;
    }
};

int main() {
    Car car("Toyota", "V8");
    car.start();

    return 0;
}

