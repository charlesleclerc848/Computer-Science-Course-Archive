#include <iostream>
using namespace std;

class CircularQueueArray {
private:
    int* queue;
    int front, rear, currSize, capacity;

public:
    CircularQueueArray(int size) {
        capacity = size;
        queue = new int[capacity];
        currSize = 0;
        front = 0;
        rear = -1;
    }

    ~CircularQueueArray() {
        delete[] queue;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        currSize++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front = (front + 1) % capacity;
        currSize--;
    }
    
    int peek(){
    	if(isEmpty()){
    		cout << "Queue is empty!" << endl;
            return -1;
		}
		
		return queue[front];
	}
	
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) 
				break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    CircularQueueArray q(4);
	q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    q.dequeue();
    q.enqueue(5);
    q.enqueue(6); // Should show queue is full

    q.display();  // Should show 2,3,4,5

    return 0;
}
