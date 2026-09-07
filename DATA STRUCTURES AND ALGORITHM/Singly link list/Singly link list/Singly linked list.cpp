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

// Insert at beginning
void insertAtBeginning(Node*& headPtr, int value) {
    Node* newNode = new Node(value);
    newNode->next = headPtr;
    headPtr = newNode;
}

// Insert at end
void insertAtEnd(Node*& headPtr, int value) {
    Node* newNode = new Node(value);
    if (headPtr == NULL) {
        headPtr = newNode;
        return;
    }
    Node* temp = headPtr;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
void insertAtPosition(Node*& headPtr, int value, int position) {
    Node* newNode = new Node(value);

    if (position == 1) {
        newNode->next = headPtr;
        headPtr = newNode;
        return;
    }

    Node* temp = headPtr;
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
void deleteFromBeginning(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = headPtr;
    headPtr = headPtr->next;
    delete temp;
}

// Delete last node
void deleteFromEnd(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (headPtr->next == NULL) { 
        delete headPtr;
        headPtr = NULL;
        return;
    }
    Node* temp = headPtr;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Delete a specific node by value
void deleteNode(Node*& headPtr, int key) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (headPtr->data == key) {
        Node* temp = headPtr;
        headPtr = headPtr->next;
        delete temp;
        return;
    }
    Node* temp = headPtr;
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

// Search for a value
bool search(Node* headPtr, int key) {
    Node* temp = headPtr;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Count the number of nodes in the list
int countNodes(Node* headPtr) {
    int count = 0;
    Node* temp = headPtr;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Sort linked list (Ascending order)
void sortAscending(Node*& headPtr) {
    Node* temp = headPtr;
    Node* nextNode;
    int swap;
    while (temp != NULL) {
        nextNode = temp->next;
        while (nextNode != NULL) {
            if (temp->data > nextNode->data) {
                swap = temp->data;
                temp->data = nextNode->data;
                nextNode->data = swap;
            }
            nextNode = nextNode->next;
        }
        temp = temp->next;
    }
}

// Sort linked list (Descending order)
void sortDescending(Node*& headPtr) {
    Node* temp = headPtr;
    Node* nextNode;
    int swap;
    while (temp != NULL) {
        nextNode = temp->next;
        while (nextNode != NULL) {
            if (temp->data < nextNode->data) {
                swap = temp->data;
                temp->data = nextNode->data;
                nextNode->data = swap;
            }
            nextNode = nextNode->next;
        }
        temp = temp->next;
    }
}

// Remove duplicate nodes
void deleteDuplicates(Node*& headPtr) {
    Node* temp = headPtr;
    while (temp != NULL) {
        Node* checkedNode = temp->next;
        Node* prev = temp;
        while (checkedNode != NULL) {
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

// Move Head to Tail
void moveHeadToTail(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == NULL) return;

    Node* temp = headPtr;
    headPtr = headPtr->next;

    Node* current = headPtr;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = temp;
    temp->next = NULL;
}

// Move Tail to Head
void moveTailToHead(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == NULL) return;

    Node* secondLast = NULL;
    Node* last = headPtr;

    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;
    last->next = headPtr;
    headPtr = last;
}

// Reverse linked list
void reverseList(Node*& headPtr) {
    Node* prev = NULL;
    Node* current = headPtr;
    Node* nextNode = headPtr;
    while (nextNode != NULL) {
        nextNode = nextNode->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    headPtr = prev;
}

// Swap two nodes
void swapNodes(Node*& headPtr, int x, int y) {
    if (x == y) return;

    Node *prevX = NULL, *currX = headPtr;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = NULL, *currY = headPtr;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) return;

    if (prevX) prevX->next = currY;
    else headPtr = currY;

    if (prevY) prevY->next = currX;
    else headPtr = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}


// Display linked list
void display(Node* headPtr) {
    Node* temp = headPtr;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* headPtr = NULL;

    insertAtBeginning(headPtr, 10);
    insertAtBeginning(headPtr, 20);
    insertAtEnd(headPtr, 30);
    insertAtEnd(headPtr, 40);
    insertAtEnd(headPtr, 10);

    cout << "Linked List: ";
    display(headPtr);

    cout << "\nMoving Head to Tail...\n";
    moveHeadToTail(headPtr);
    display(headPtr);

    cout << "\nMoving Tail to Head...\n";
    moveTailToHead(headPtr);
    display(headPtr);

    cout << "\nSorting in Ascending Order...\n";
    sortAscending(headPtr);
    display(headPtr);

    cout << "\nSorting in Descending Order...\n";
    sortDescending(headPtr);
    display(headPtr);

    cout << "\nReversing Linked List...\n";
    reverseList(headPtr);
    display(headPtr);
    
    cout << "\nSwapping 10 and 30...\n";
	swapNodes(headPtr, 10, 30);
	display(headPtr);

    cout << "\nDeleting duplicate values...\n";
    deleteDuplicates(headPtr);
    display(headPtr);

    cout << "\nTotal nodes: " << countNodes(headPtr) << endl;

    cout << "\nSearching for 10: ";
    if (search(headPtr, 10)) {
        cout << "Found";
    } else {
        cout << "Not Found";
    }

    return 0;
}
