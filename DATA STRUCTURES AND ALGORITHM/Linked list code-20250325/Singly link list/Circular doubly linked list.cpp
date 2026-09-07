#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

// Insert at beginning
void insertAtBeginning(Node*& headPtr, int value) {
	
	
	
    Node* newNode = new Node(value);
    if (headPtr == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        headPtr = newNode;
        return;
    }
    newNode->next = headPtr;
    newNode->prev = headPtr->prev;
    headPtr->prev->next = newNode;
    headPtr->prev = newNode;
    headPtr = newNode;
}

// Insert at end
void insertAtEnd(Node*& headPtr, int value) {
    Node* newNode = new Node(value);
    if (headPtr == NULL) {
    	insertAtBeginning(headPtr, value);
//        newNode->next = newNode;
//        newNode->prev = newNode;
//        headPtr = newNode;
        return;
    }
    newNode->next = headPtr;
    newNode->prev = headPtr->prev;
    headPtr->prev->next = newNode;
    headPtr->prev = newNode;
}

// Insert before a specific position
void insertBeforePosition(Node*& headPtr, int value, int position) {
    if (position <= 1 || headPtr == NULL) { // Insert at beginning if user enters invalid position which is less than 1
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
    newNode->prev = temp;
    temp->next->prev = newNode;
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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete first node
void deleteFirst(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (headPtr->next == headPtr) { // Only one node
        delete headPtr;
        headPtr = NULL;
        return;
    }
    Node* temp = headPtr;
    headPtr->prev->next = headPtr->next;
    headPtr->next->prev = headPtr->prev;
    headPtr = headPtr->next;
    delete temp;
}

// Delete last node
void deleteLast(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (headPtr->next == headPtr) { // Only one node
        delete headPtr;
        headPtr = NULL;
        return;
    }
    Node* temp = headPtr->prev;
    temp->prev->next = headPtr;
    headPtr->prev = temp->prev;
    delete temp;
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
    for (int i = 1; i < position && temp->next != headPtr; i++) {
        temp = temp->next;
    }

    if (temp->next == headPtr) {
        cout << "Position out of bounds!\n";
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// Count number of nodes
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

// Search for a value in the list
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
    headPtr = headPtr->prev;
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
        Node* check = temp->next;
        while (check != headPtr) {
            if (temp->data == check->data) {
                check->prev->next = check->next;
                check->next->prev = check->prev;
                Node* toDelete = check;
                check = check->next;
                delete toDelete;
            } else {
                check = check->next;
            }
        }
        temp = temp->next;
    } while (temp->next != headPtr);
}

// Display list in forward direction
void display(Node* headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = headPtr;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != headPtr);
    cout << "(HEAD)\n";
}

int main() {
    Node* headPtr = NULL;

    insertAtBeginning(headPtr, 10);
    insertAtBeginning(headPtr, 20);
    insertAtEnd(headPtr, 30);
    insertAtEnd(headPtr, 40);
    insertAtEnd(headPtr, 40);
    insertAtEnd(headPtr, 10);

    cout << "Inserting 15 before position 3...\n";
    insertBeforePosition(headPtr, 15, 3);
    display(headPtr);

    cout << "\nInserting 25 after position 3...\n";
    insertAfterPosition(headPtr, 25, 3);
    display(headPtr);
    
    cout << "\nDeleting First Node...\n";
    deleteFirst(headPtr);
    display(headPtr);

    cout << "\nDeleting Last Node...\n";
    deleteLast(headPtr);
    display(headPtr);

    cout << "\nDeleting Node at Position 2...\n";
    deleteAtPosition(headPtr, 2);
    display(headPtr);

    cout << "\nTotal Nodes: " << countNodes(headPtr) << endl;

    int searchVal = 30;
    cout << "\nSearching for value " << searchVal << ": ";
    if (searchValue(headPtr, searchVal))
        cout << "Found\n";
    else
        cout << "Not Found\n";

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

    cout << "\nDeleting duplicate values...\n";
    deleteDuplicates(headPtr);
    display(headPtr);

    return 0;
}
