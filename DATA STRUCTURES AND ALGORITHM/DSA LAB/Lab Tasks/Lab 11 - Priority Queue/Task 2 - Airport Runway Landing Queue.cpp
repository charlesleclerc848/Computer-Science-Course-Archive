#include <iostream>
#include <string>
using namespace std;

// Node class to represent an airplane
class Node {
public:
    string flightNumber;
    int fuelLevel;
    string destination;
    Node* next;

    Node(string flightNum, int fuel, string dest) {
        flightNumber = flightNum;
        fuelLevel = fuel;
        destination = dest;
        next = nullptr;
    }
};

// Priority Queue class for Air Traffic Control
class AirTrafficControl {
private:
    Node* front;

public:
    AirTrafficControl() {
        front = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add a new airplane to the queue
    void addAirplane(string flightNum, int fuel, string dest) {
        Node* newNode = new Node(flightNum, fuel, dest);

        if (isEmpty() || fuel < front->fuelLevel ||
           (fuel == front->fuelLevel && dest < front->destination)) {
            // Insert at front
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr &&
                  (current->next->fuelLevel < fuel ||
                  (current->next->fuelLevel == fuel && current->next->destination <= dest))) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Airplane " << flightNum << " added to queue.\n";
    }

    // View queue
    void viewQueue() {
        if (isEmpty()) {
            cout << "No airplanes in landing queue.\n";
            return;
        }

        Node* temp = front;
        cout << "Landing Queue:\n";
        while (temp != nullptr) {
            cout << "Flight: " << temp->flightNumber
                 << " | Fuel: " << temp->fuelLevel
                 << " | Destination: " << temp->destination << endl;
            temp = temp->next;
        }
    }

    // Land (remove) the highest priority airplane
    void landAirplane() {
        if (isEmpty()) {
            cout << "No airplanes to land.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << "Flight " << temp->flightNumber << " is landing (Fuel: " << temp->fuelLevel << ").\n";
        delete temp;
    }

    // Search airplane by flight number
    void searchFlight(string flightNum) {
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->flightNumber == flightNum) {
                cout << "Found: Flight " << temp->flightNumber
                     << " | Fuel: " << temp->fuelLevel
                     << " | Destination: " << temp->destination << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Flight " << flightNum << " not found.\n";
    }
};

// Main function to test the system
int main() {
    AirTrafficControl atc;

    atc.addAirplane("AI101", 50, "Delhi");
    atc.addAirplane("BA202", 30, "London");
    atc.addAirplane("QR303", 30, "AbuDhabi");
    atc.addAirplane("UA404", 20, "NewYork");
    atc.addAirplane("AF505", 45, "Paris");

    atc.viewQueue();
    cout << endl;

    atc.landAirplane();
    atc.landAirplane();

    cout << "\nAfter Landing 2 planes:\n";
    atc.viewQueue();

    cout << "\nSearching for BA202:\n";
    atc.searchFlight("BA202");

    return 0;
}
