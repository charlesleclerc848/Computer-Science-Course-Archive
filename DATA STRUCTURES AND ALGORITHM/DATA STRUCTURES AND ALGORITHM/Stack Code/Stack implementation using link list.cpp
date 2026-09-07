#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) { // Constructor
        data = value;
        next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() { // Constructor initializes stack as empty
		top = nullptr; 
	} 

    // Push operation (Insert element at the top)
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = top; // Link the new node to the current top
        top = newNode; // Update top to the new node
        cout << value << " pushed into stack." << endl;
    }

    // Pop operation (Remove and return the top element)
    int pop() {
        if (top == nullptr) { // Check for underflow
            cout << "Stack Underflow! No elements to pop." << endl;
            return -1;
        }
        int poppedValue = top->data; // Store the top element
        Node* temp = top; // Store the node to be deleted
        top = top->next; // Move top to the next node
        delete temp; // Free memory
        return poppedValue;
    }

    // Peek operation (Return top element without removing it)
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == nullptr);
    }

    // Display stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Display Stack\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            value = s.pop();
            if (value != -1)
                cout << "Popped element: " << value << endl;
            break;
        case 3:
            value = s.peek();
            if (value != -1)
                cout << "Top element: " << value << endl;
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is Empty!" : "Stack is NOT Empty!") << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
