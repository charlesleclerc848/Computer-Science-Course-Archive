#include <iostream>
#include <string>
using namespace std;

// Node structure for each patient
class Node {
public:
    string name;
    int id;
    int criticality;
    Node* next;

    Node(string name, int id, int criticality) {
        this->name = name;
        this->id = id;
        this->criticality = criticality;
        this->next = nullptr;
    }
};

// Priority Queue class for Emergency Room
class ERPriorityQueue {
private:
    Node* front;

public:
    ERPriorityQueue() {
        front = nullptr;
    }

    // Admit a new patient based on criticality (higher criticality -> higher priority)
    void admitPatient(string name, int id, int criticality) {
        Node* newNode = new Node(name, id, criticality);

        // Insert at the front if queue is empty or new patient has higher priority
        if (!front || criticality > front->criticality) {
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse to find correct position
            Node* current = front;
            while (current->next && current->next->criticality >= criticality) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Admitted: " << name << " (ID: " << id << ", Criticality: " << criticality << ")\n";
    }

    // Treat (remove) the highest priority patient
    void treatPatient() {
        if (!front) {
            cout << "No patients to treat.\n";
            return;
        }

        Node* temp = front;
        cout << "Treating patient: " << temp->name << " (ID: " << temp->id << ", Criticality: " << temp->criticality << ")\n";
        front = front->next;
        delete temp;
    }

    // View all patients in the queue
    void viewQueue() {
        if (!front) {
            cout << "No patients in queue.\n";
            return;
        }

        Node* temp = front;
        cout << "\nCurrent Patient Queue:\n";
        while (temp) {
            cout << "Name: " << temp->name << ", ID: " << temp->id << ", Criticality: " << temp->criticality << "\n";
            temp = temp->next;
        }
        cout << endl;
    }

    // Search patient by ID
    void searchPatient(int id) {
        Node* temp = front;
        while (temp) {
            if (temp->id == id) {
                cout << "Found patient: " << temp->name << " (ID: " << temp->id << ", Criticality: " << temp->criticality << ")\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient with ID " << id << " not found.\n";
    }
};

// Demo
int main() {
    ERPriorityQueue er;

    er.admitPatient("Alice", 101, 3);
    er.admitPatient("Bob", 102, 5);
    er.admitPatient("Charlie", 103, 4);
    er.admitPatient("Diana", 104, 5);  // Same criticality as Bob

    er.viewQueue();

    er.treatPatient();
    er.treatPatient();

    er.searchPatient(103);
    er.searchPatient(999); // Not found

    er.viewQueue();

    return 0;
}
