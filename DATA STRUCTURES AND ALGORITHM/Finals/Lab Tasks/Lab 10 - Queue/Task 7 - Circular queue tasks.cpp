#include <iostream>
#include <unordered_set>
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

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (front == rear) {
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

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

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

//    void displayMiddle() {
//        if (isEmpty()) 
//			return;
//        Node* slow = front;
//        Node* fast = front;
//        while (fast->next != front && fast->next->next != front) {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        cout << "Middle element: " << slow->data << endl;
//    }

	void displayMiddle() {
	    if (front == nullptr) return;
	
	    // Step 1: Count total nodes
	    int count = 1;
	    Node* temp = front;
	    while (temp->next != front) {
	        count++;
	        temp = temp->next;
	    }
	
	    // Step 2: Traverse to middle node
	    int mid = count / 2;
	    temp = front;
	    for (int i = 0; i < mid; i++) {
	        temp = temp->next;
	    }
	
	    cout << "Middle element: " << temp->data << endl;
	}

    void removeEven() {
        if (isEmpty()) return;
        int count = 0;
        Node* temp = front;
        do {
            count++;
            temp = temp->next;
        } while (temp != front);

        for (int i = 0; i < count; ++i) {
            int val = front->data;
            dequeue();
            if (val % 2 != 0) 
				enqueue(val);
        }
        cout << "Even elements removed.\n";
    }

    void averageOfKElems(int k) {
        if (isEmpty() || k <= 0) 
			return;
        Node* temp = front;
        int count = 0, sum = 0, batch = 1;
        cout << "Averages: ";
        do {
            sum += temp->data;
            count++;
            if (count == k) {
                cout << "[Group " << batch++ << "]: " << (sum / (float)k) << " ";
                count = 0;
                sum = 0;
            }
            temp = temp->next;
        } while (temp != front);
        if (count > 0) 
			cout << "[Last Group]: " << (sum / (float)count);
        cout << endl;
    }

    void mergeWithoutDuplicates(CircularQueue& other) {
	    // Step 1: Traverse the other queue
	    Node* temp = other.front;
	    if (!temp) return;  // If other queue is empty, nothing to merge
	
	    do {
	        // Step 2: Check if temp->data already exists in current queue
	        bool exists = false;
	        Node* check = front;
	        if (check) {
	            do {
	                if (check->data == temp->data) {
	                    exists = true;
	                    break;
	                }
	                check = check->next;
	            } while (check != front);
	        }
	
	        // Step 3: If not exists, enqueue the element
	        if (!exists) enqueue(temp->data);
	
	        temp = temp->next;
	    } while (temp != other.front);
	}


    void splitIntoTwo(CircularQueue& q1, CircularQueue& q2) {
        if (isEmpty()) 
			return;
        Node* temp = front;
        int count = 0;
        do {
            count++;
            temp = temp->next;
        } while (temp != front);

        temp = front;
        for (int i = 0; i < count / 2; i++) {
            q1.enqueue(temp->data);
            temp = temp->next;
        }
        for (int i = count / 2; i < count; i++) {
            q2.enqueue(temp->data);
            temp = temp->next;
        }
    }

    void customSkipFactor(int skip) {
        if (isEmpty() || skip <= 1) 
			return;
        Node* curr = front;
        while (curr && curr->next != curr) {
            for (int i = 1; i < skip - 1; ++i) {
                curr = curr->next;
            }
            cout << "Skipping: " << curr->next->data << endl;
            Node* delNode = curr->next;
            if (delNode == rear) 
				rear = curr;
            if (delNode == front) 
				front = front->next;
            curr->next = delNode->next;
            delete delNode;
            curr = curr->next;
            rear->next = front;
        }
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.displayMiddle();

    q.removeEven();
    q.display();

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.averageOfKElems(2);

    CircularQueue q1, q2;
    q.splitIntoTwo(q1, q2);
    cout << "Split Queue 1: "; q1.display();
    cout << "Split Queue 2: "; q2.display();

    CircularQueue a, b;
    a.enqueue(1); a.enqueue(2); a.enqueue(3);
    b.enqueue(3); b.enqueue(4); b.enqueue(5);
    a.mergeWithoutDuplicates(b);
    cout << "Merged Queue without duplicates: "; a.display();

    CircularQueue sk;
    sk.enqueue(1); sk.enqueue(2); sk.enqueue(3); sk.enqueue(4); sk.enqueue(5);
    sk.customSkipFactor(3);
    sk.display();

    return 0;
}
