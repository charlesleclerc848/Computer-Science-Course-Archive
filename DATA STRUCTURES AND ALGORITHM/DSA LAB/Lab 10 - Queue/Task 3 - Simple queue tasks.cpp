#include <iostream>
#include <algorithm>  
using namespace std;

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

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void countEvenOdd() {
        int even = 0, odd = 0;
        Node* temp = front;
        while (temp) {
            if (temp->data % 2 == 0)
                even++;
            else
                odd++;
            temp = temp->next;
        }
        cout << "Even: " << even << ", Odd: " << odd << endl;
    }

    void sumAndAverage() {
        int sum = 0, count = 0;
        Node* temp = front;
        while (temp) {
            sum += temp->data;
            count++;
            temp = temp->next;
        }
        if (count > 0)
            cout << "Sum: " << sum << ", Average: " << (sum / (float)count) << endl;
        else
            cout << "Queue is empty!" << endl;
    }

    void findMaxMin() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int maxVal = front->data;
        int minVal = front->data;
        Node* temp = front;
        while (temp) {
            if (temp->data > maxVal)
                maxVal = temp->data;
            if (temp->data < minVal)
                minVal = temp->data;
            temp = temp->next;
        }
        cout << "Max: " << maxVal << ", Min: " << minVal << endl;
    }

    bool isPalindrome() {
        string str = "";
        Node* temp = front;
        while (temp) {
            str += to_string(temp->data);
            temp = temp->next;
        }
        string rev = str;
        reverse(rev.begin(), rev.end());
        return str == rev;
    }

    void moveZerosToRear() {
	    if (isEmpty()) return;
	
	    Queue tempQueue;
	    int zeroCount = 0;
	    Node* temp = front;
	
	    // Count zeros and enqueue non-zero elements
	    while (temp) {
	        if (temp->data == 0)
	            zeroCount++;
	        else
	            tempQueue.enqueue(temp->data);
	        temp = temp->next;
	    }
	
	    // Enqueue zeros at the end
	    while (zeroCount--)
	        tempQueue.enqueue(0);
	
	    // Clear the original queue
	    while (!isEmpty())
	        dequeue();
	
	    // Copy elements from tempQueue back
	    temp = tempQueue.front;
	    while (temp) {
	        enqueue(temp->data);
	        temp = temp->next;
	    }
	
	    cout << "Moved zeros to rear." << endl;
	}


	Queue mergeWith(Queue& other) {
	    Queue result;
	
	    // Add elements from current queue
	    Node* temp = this->front;
	    while (temp) {
	        result.enqueue(temp->data);
	        temp = temp->next;
	    }
	
	    // Add elements from other queue
	    temp = other.front;
	    while (temp) {
	        result.enqueue(temp->data);
	        temp = temp->next;
	    }
	
	    return result;
	}
	
	bool isEqualTo(Queue& other) {
	    Node* temp1 = this->front;
	    Node* temp2 = other.front;
	
	    while (temp1 && temp2) {
	        if (temp1->data != temp2->data)
	            return false;
	        temp1 = temp1->next;
	        temp2 = temp2->next;
	    }
	
	    return temp1 == nullptr && temp2 == nullptr;
	}

};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(0);
    q.enqueue(30);
    q.enqueue(0);
    q.enqueue(10);

    q.display();
    q.countEvenOdd();
    q.sumAndAverage();
    q.findMaxMin();
    cout << (q.isPalindrome() ? "Queue is Palindrome" : "Queue is Not Palindrome") << endl;

    q.moveZerosToRear();
    q.display();

    // Merge two queues
    Queue q1, q2;
    q1.enqueue(1); q1.enqueue(2);
    q2.enqueue(3); q2.enqueue(4);

    Queue merged = q1.mergeWith(q2);   
	merged.display();

    // Compare queues
    cout << (q1.isEqualTo(q2) ? "Queues are equal" : "Queues are not equal") << endl;

    return 0;
}
