#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at beginning
void insertAtBeginning(Node*& headPtr, int value) {
    Node* newNode = new Node(value);
    if (headPtr == NULL) {
        newNode->next = newNode;
        headPtr = newNode;
        return;
    }
    Node* temp = headPtr;
    while (temp->next != headPtr)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = headPtr;
    headPtr = newNode;
}

// Insert at end
void insertAtEnd(Node*& headPtr, int value) {
    if (headPtr == NULL) {
        insertAtBeginning(headPtr, value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = headPtr;
    while (temp->next != headPtr)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = headPtr;
}

// Insert before a specific position
void insertBeforePosition(Node*& headPtr, int value, int position) {
    if (position <= 1 || headPtr == NULL) {
        insertAtBeginning(headPtr, value);
        return;
    }
    Node* temp = headPtr;
    for (int i = 1; i < position - 1 && temp->next != headPtr; i++) {
        temp = temp->next;
    }
    if (temp->next == headPtr) {
        cout << "Position out of bounds!\n";
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert after a specific position
void insertAfterPosition(Node*& headPtr, int value, int position) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = headPtr;
    for (int i = 1; i < position && temp->next != headPtr; i++) {
        temp = temp->next;
    }
    if (temp->next == headPtr) {
        cout << "Position out of bounds!\n";
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteFirst(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (headPtr->next == headPtr) { 
        delete headPtr;
        headPtr = NULL;
        return;
    }
    Node* temp = headPtr;
    Node* last = headPtr;
    while (last->next != headPtr)
        last = last->next;
    headPtr = headPtr->next;
    last->next = headPtr;
    delete temp;
}

// Delete last node
void deleteLast(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (headPtr->next == headPtr) {
        delete headPtr;
        headPtr = NULL;
        return;
    }
    Node* temp = headPtr;
    while (temp->next->next != headPtr)
        temp = temp->next;
    delete temp->next;
    temp->next = headPtr;
}

// Delete at specific position
void deleteAtPosition(Node*& headPtr, int position) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (position <= 1) {
        deleteFirst(headPtr);
        return;
    }
    Node* temp = headPtr;
    for (int i = 1; i < position - 1 && temp->next != headPtr; i++) {
        temp = temp->next;
    }
    if (temp->next == headPtr) {
        cout << "Position out of bounds!\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Count number of nodes (Same as circular doubly link list)
int countNodes(Node* headPtr) {
    if (headPtr == NULL)
        return 0;
    int count = 0;
    Node* temp = headPtr;
    do {
        count++;
        temp = temp->next;
    } while (temp != headPtr);
    return count;
}

// Search for a value in the list (Same as circular doubly link list)
bool searchValue(Node* headPtr, int value) {
    if (headPtr == NULL)
        return false;
        
    Node* temp = headPtr;
    do {
        if (temp->data == value)
            return true;
        temp = temp->next;
    } while (temp != headPtr);
    return false;
}

// Move Head to Tail
void moveHeadToTail(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == headPtr) 
        return;
    headPtr = headPtr->next;
}

// Move Tail to Head
void moveTailToHead(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == headPtr) 
        return;
    Node* temp = headPtr;
    while (temp->next->next != headPtr)
        temp = temp->next;
    headPtr = temp->next;
}

// Sort in ascending order
void sortAscending(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == headPtr) 
        return;
    Node* temp = headPtr;
    Node* nextNode;
    int swap;
    do {
        nextNode = temp->next;
        while (nextNode != headPtr) {
            if (temp->data > nextNode->data) {
                swap = temp->data;
                temp->data = nextNode->data;
                nextNode->data = swap;
            }
            nextNode = nextNode->next;
        }
        temp = temp->next;
    } while (temp->next != headPtr);
}

// Sort in descending order
void sortDescending(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == headPtr) 
        return;
    Node* temp = headPtr;
    Node* nextNode;
    int swap;
    do {
        nextNode = temp->next;
        while (nextNode != headPtr) {
            if (temp->data < nextNode->data) {
                swap = temp->data;
                temp->data = nextNode->data;
                nextNode->data = swap;
            }
            nextNode = nextNode->next;
        }
        temp = temp->next;
    } while (temp->next != headPtr);
}

// Delete duplicate values
void deleteDuplicates(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == headPtr) 
        return;
    Node* temp = headPtr;
    do {
        Node* check = temp;
        while (check->next != headPtr) {
            if (temp->data == check->next->data) {
                Node* toDelete = check->next;
                check->next = check->next->next;
                delete toDelete;
            } else {
                check = check->next;
            }
        }
        temp = temp->next;
    } while (temp->next != headPtr);
}

// Display list in forward direction (Same as circular doubly link list)
void display(Node* headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = headPtr;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != headPtr);
    cout << "(HEAD)\n";
}

int main() {
    Node* headPtr = NULL;

    insertAtBeginning(headPtr, 10);
    insertAtEnd(headPtr, 20);
    insertAtEnd(headPtr, 10);
    insertAtEnd(headPtr, 30);

    display(headPtr);
    
    cout << "\nSorting Ascending...\n";
    sortAscending(headPtr);
    display(headPtr);

    cout << "\nDeleting Duplicates...\n";
    deleteDuplicates(headPtr);
    display(headPtr);

    return 0;
}
