#include <iostream>
using namespace std;

// Node class to hold data and priority
class Node {
public:
    int data, priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front; // Points to the front node (smallest priority)

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Insert a new node into the queue in sorted order by priority
    void insert(int val, int prio) {
        Node* newNode = new Node(val, prio);

        // If queue is empty or new node has lower priority than front
        if (!front || prio < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Find the correct position for the new node
            Node* temp = front;
            while (temp->next && temp->next->priority <= prio)
                temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete the front node (min priority)
    void deleteMin() {
        if (!front) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Deleted: " << front->data << " (Priority " << front->priority << ")\n";
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Display all nodes with priorities
    void display() {
        Node* temp = front;
        cout << "Queue:\n";
        while (temp) {
            cout << temp->data << " (Priority " << temp->priority << ")\n";
            temp = temp->next;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 3);  // Data 10, priority 3
    pq.insert(5, 1);   // Data 5, priority 1
    pq.insert(20, 2);  // Data 20, priority 2
    pq.display();      // Show the queue
    pq.deleteMin();    // Delete the item with the smallest priority
    pq.display();      // Show the queue again
    return 0;
}
