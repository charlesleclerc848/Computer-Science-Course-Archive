#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) {  // Constructor to initialize node
        data = value;
        next = NULL;
    }
};

// Linked List structure
struct LinkedList {
    Node* head;

    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) { // Insert at beginning
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of bounds!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete first node
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete last node
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {  // Only one node
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Delete a specific node by value
    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == key) {  // If head needs to be deleted
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Count the number of nodes
    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Search for a value
    bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Sort linked list (Ascending)
    void sortAscending() {
        if (!head) return;
        Node* temp = head;
        Node* nextNode;
        while (temp) {
            nextNode = temp->next;
            while (nextNode) {
                if (temp->data > nextNode->data) {
                    swap(temp->data, nextNode->data);
                }
                nextNode = nextNode->next;
            }
            temp = temp->next;
        }
    }

    // Sort linked list (Descending)
    void sortDescending() {
        if (!head) return;
        Node* temp = head;
        Node* nextNode;
        while (temp) {
            nextNode = temp->next;
            while (nextNode) {
                if (temp->data < nextNode->data) {
                    swap(temp->data, nextNode->data);
                }
                nextNode = nextNode->next;
            }
            temp = temp->next;
        }
    }

    // Swap two nodes
    void swapNodes(int x, int y) {
        if (x == y) return;

        Node *prevX = NULL, *currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        Node *prevY = NULL, *currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (!currX || !currY) return;

        if (prevX) prevX->next = currY;
        else head = currY;

        if (prevY) prevY->next = currX;
        else head = currX;

        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }

    // Reverse linked list
    void reverseList() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;
        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    // Remove duplicate nodes
    void deleteDuplicates() {
        Node* temp = head;
        while (temp) {
            Node* checkedNode = temp->next;
            Node* prev = temp;
            while (checkedNode) {
                if (temp->data == checkedNode->data) {
                    Node* duplicateNode = checkedNode;
                    prev->next = checkedNode->next;
                    checkedNode = checkedNode->next;
                    delete duplicateNode;
                } else {
                    prev = checkedNode;
                    checkedNode = checkedNode->next;
                }
            }
            temp = temp->next;
        }
    }

    // Move head to tail
	void moveHeadToTail() {
	    if (head == NULL || head->next == NULL) {
	        return; // No change needed for empty or single-node list
	    }
	
	    Node* temp = head;
	    head = head->next; // Move head to next node
	    temp->next = NULL; // Detach old head
	
	    Node* current = head;
	    while (current->next != NULL) {
	        current = current->next; // Traverse to last node
	    }
	    current->next = temp; // Attach old head at the end
	}

    // Move tail to head
    void moveTailToHead() {
        if (!head || !head->next) return;
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        temp->next = head;
        head = temp;
    }

    // Display linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(10);

    cout << "\nLinked List: ";
    list.display();

    cout << "\nSorting list in ascending order...\n";
    list.sortAscending();
    list.display();

    cout << "\nSorting list in descending order...\n";
    list.sortDescending();
    list.display();

    cout << "\nSwapping nodes 10 and 30...\n";
    list.swapNodes(10, 30);
    list.display();

    cout << "\nReversing the linked list...\n";
    list.reverseList();
    list.display();

    cout << "\nDeleting duplicate nodes...\n";
    list.deleteDuplicates();
    list.display();

    cout << "\nMoving head to tail...\n";
    list.moveHeadToTail();
    list.display();

    cout << "\nMoving tail to head...\n";
    list.moveTailToHead();
    list.display();

    cout << "\nDeleting first node...\n";
    list.deleteFromBeginning();
    list.display();

    cout << "\nDeleting last node...\n";
    list.deleteFromEnd();
    list.display();

    cout << "\nDeleting node with value 30...\n";
    list.deleteNode(30);
    list.display();

    cout << "\nTotal nodes: " << list.countNodes() << endl;

    cout << "\nSearching for 10: ";
    if (list.search(10)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
