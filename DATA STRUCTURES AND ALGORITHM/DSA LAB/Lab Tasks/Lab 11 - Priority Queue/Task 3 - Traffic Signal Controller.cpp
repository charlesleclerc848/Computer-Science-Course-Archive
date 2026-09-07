#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string vehicleType;
    int priority;  // Higher number means higher priority
    int waitTime;
    Node* next;

    Node(string vType, int pri) {
        vehicleType = vType;
        priority = pri;
        waitTime = 0;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;

    int getInitialPriority(string vehicleType) {
        if (vehicleType == "ambulance" || vehicleType == "firetruck" || vehicleType == "police")
            return 5;
        else if (vehicleType == "bus")
            return 3;
        else if (vehicleType == "truck")
            return 2;
        else
            return 1;  // car, bike, etc.
    }

public:
    PriorityQueue() {
        front = nullptr;
    }

    void admitVehicle(string type) {
        int pri = getInitialPriority(type);
        Node* newNode = new Node(type, pri);

        // Insert in sorted order based on priority (descending)
        if (!front || newNode->priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next && temp->next->priority >= newNode->priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Vehicle admitted: " << type << " with priority " << pri << endl;
    }

    void processNextVehicle() {
        if (!front) {
            cout << "No vehicles to process.\n";
            return;
        }

        cout << "Processing vehicle: " << front->vehicleType << " (priority " << front->priority << ")\n";
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void incrementWaitTimeAndBoostPriority() {
        Node* temp = front;
        while (temp) {
            temp->waitTime++;

            // If wait time exceeds threshold, increase priority (up to a max)
            if (temp->waitTime >= 3 && temp->priority < 5) {
                temp->priority++;
                cout << "Priority boosted for " << temp->vehicleType << " to " << temp->priority << endl;
                temp->waitTime = 0;
            }

            temp = temp->next;
        }

        // Re-sort the queue based on new priorities
        if (front) {
            Node* sorted = nullptr;

            while (front) {
                Node* curr = front;
                front = front->next;

                if (!sorted || curr->priority > sorted->priority) {
                    curr->next = sorted;
                    sorted = curr;
                } else {
                    Node* t = sorted;
                    while (t->next && t->next->priority >= curr->priority) {
                        t = t->next;
                    }
                    curr->next = t->next;
                    t->next = curr;
                }
            }

            front = sorted;
        }
    }

    void displayQueue() {
        if (!front) {
            cout << "No vehicles in queue.\n";
            return;
        }

        Node* temp = front;
        cout << "Current vehicle queue:\n";
        while (temp) {
            cout << temp->vehicleType << " (priority " << temp->priority << ", wait time " << temp->waitTime << ")\n";
            temp = temp->next;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.admitVehicle("car");
    pq.admitVehicle("ambulance");
    pq.admitVehicle("bus");
    pq.admitVehicle("bike");
    pq.admitVehicle("firetruck");

    pq.displayQueue();

    // Simulate time passing
    for (int i = 0; i < 5; i++) {
        cout << "\n--- Time tick: " << i + 1 << " ---\n";
        pq.incrementWaitTimeAndBoostPriority();
        pq.displayQueue();
        pq.processNextVehicle();
    }

    return 0;
}
