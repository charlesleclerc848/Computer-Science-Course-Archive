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

    void display() {
        cout << "Engine Model: " << model << endl;
    }
};

class Car {
public:
    string brand;
    Engine* engine; // Pointer to Engine for dynamic memory allocation

    Car(string brand, string engineModel) : brand(brand) {
        engine = new Engine(engineModel); // Dynamically allocate Engine
        cout << brand << " car created with engine model " << engine->model << "." << endl;
    }

    ~Car() {
        delete engine; // Free the dynamically allocated Engine
        cout << brand << " car destroyed." << endl;
    }

    void start() {
        cout << brand << " car is starting with engine model " << engine->model << "." << endl;
        engine->display();
    }
};

int main() {
    Car car("Toyota", "V8");
    car.start();

    return 0;
}

