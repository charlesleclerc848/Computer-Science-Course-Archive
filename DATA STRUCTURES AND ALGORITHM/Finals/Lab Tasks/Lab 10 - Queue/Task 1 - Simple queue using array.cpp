#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Enqueue: Insert element at the rear
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[++rear] = element;
        size++;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue: Remove element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        size--;
    }

    // Peek: Display the front element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display: Print all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Reverse the queue
    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        int start = front;
        int end = rear;
        while (start < end) {
            // Swap elements at start and end
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        cout << "Queue reversed!" << endl;
    }
};

// Example usage
int main() {
    Queue q(5); // Create a queue with capacity 5

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
