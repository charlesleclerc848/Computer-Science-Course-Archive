#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the queue

class PriorityQueue {
private:
    int data[MAX];      // Stores the data elements
    int priority[MAX];  // Stores the corresponding priorities
    int size;           // Current number of elements in the queue

public:
    PriorityQueue() {
        size = 0; // Initialize size to 0
    }

    // Insert a value with its priority into the queue
    void insert(int val, int prio) {
        if (size == MAX) {
            cout << "Queue is full!\n";
            return;
        }
        data[size] = val;         // Store the value
        priority[size] = prio;    // Store its priority
        size++;                   // Increase queue size
    }

    // Delete the element with the highest priority (smallest value for min queue)
    void deleteMin() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        // Find index of the minimum priority
        int minIdx = 0;
        for (int i = 1; i < size; i++) {
            if (priority[i] < priority[minIdx]) {
                minIdx = i;
            }
        }

        cout << "Deleted: " << data[minIdx] << " (Priority " << priority[minIdx] << ")\n";

        // Shift all elements after minIdx one step left to fill the gap
        for (int i = minIdx; i < size - 1; i++) {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }
        size--; // Decrease queue size
    }

    // Display all elements in the queue with their priorities
    void display() {
        cout << "Queue:\n";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " (Priority " << priority[i] << ")\n";
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
