#include <iostream>
using namespace std;

// Node class for Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue: Insert element at the rear
    void enqueue(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue: Remove element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // If the queue becomes empty
            rear = nullptr;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
        size--;
    }

    // Peek: Display the front element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Display: Print all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Reverse the queue
    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* prev = nullptr;
        Node* current = front;
        Node* nextNode = nullptr;
        rear = front;  // After reverse, front will be rear

        while (current != nullptr) {
            nextNode = current->next;  // Store next node
            current->next = prev;      // Reverse current node's pointer
            prev = current;            // Move prev and current one step forward
            current = nextNode;
        }
        front = prev; // Update front to the new first node
        cout << "Queue reversed!" << endl;
    }
};

// Example usage
int main() {
    Queue q; // Create a queue

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display(); // Should display: 10 20 30 40 50

    q.reverse(); // Reverse the queue
    q.display(); // Should display: 50 40 30 20 10

    q.dequeue(); 
    q.display(); // Should display: 40 30 20 10

    q.peek(); // Should display: Front element: 40

    return 0;
}
