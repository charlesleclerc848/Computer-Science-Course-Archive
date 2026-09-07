#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue: Insert at rear
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue: Remove from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (front == rear) { // Single element
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        cout << "Dequeued successfully." << endl;
    }

    // Peek: Display front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Reverse the circular queue
    void reverse() {
        if (isEmpty() || front == rear) {
            cout << "Queue reversed." << endl;
            return;
        }

        Node *prev = rear, *curr = front, *next = nullptr;
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != front);

        // Swap front and rear
        Node* temp = front;
        front = rear;
        rear = temp;

        cout << "Queue reversed." << endl;
    }
};

// Example usage
int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();

    cq.peek();

    cq.dequeue();
    cq.display();

    cq.reverse();
    cq.display();

    return 0;
}
