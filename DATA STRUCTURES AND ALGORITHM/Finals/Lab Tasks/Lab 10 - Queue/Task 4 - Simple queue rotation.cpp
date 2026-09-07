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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue: Add element at rear
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue: Remove element from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Rotate the queue k times
    void rotate(int k) {
        if (isEmpty() || k == 0) 
			return;

        int length = 0;
        Node* temp = front;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
		if(k >= length)
			return;
        
		for (int i = 0; i < k; i++) {
            int val = front->data;
            dequeue();
            enqueue(val);
        }
        cout << "Queue rotated " << k << " times." << endl;
    }
};

// Example usage
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Original ";
    q.display();

    int k = 3;
    q.rotate(k);

    cout << "After " << k << " rotations ";
    q.display();

    return 0;
}
