#include <iostream>
using namespace std;

/* 	
	#define MAX 5 is a preprocessor directive in C++ that defines a macro named MAX with the value 5.
	#define is used to create constant values before the program is compiled.
	MAX is the name of the macro. A macro is a piece of code that is replaced by its value before compilation. Macros are defined using #define.
	No memory is allocated for MAX, unlike a variable.
	5 is the value assigned to MAX. 
*/
#define MAX 5 // Maximum size of the stack

class Stack {
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    Stack() {  // Constructor initializes stack as empty
		top = -1; 
	} 

    // Function to push an element onto the stack
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack." << endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! No elements to pop." << endl;
            return -1;
        }
        return arr[top--];
    }

    // Function to return the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Function to check if the stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Function to display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Display Stack\n7. Exit\n";
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
            cout << (s.isFull() ? "Stack is Full!" : "Stack is NOT Full!") << endl;
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
