#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) { // Constructor to initialize node
        data = value;
        next = prev = NULL;
    }
};

// Insert at beginning
void insertAtBeginning(Node*& headPtr, int value) {
    Node* newNode = new Node(value);
    if (headPtr != NULL) {
        newNode->next = headPtr;
        headPtr->prev = newNode;
    }
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
    newNode->prev = temp;
}

// Insert before a specific position
void insertBeforePosition(Node*& headPtr, int value, int position) {
    Node* newNode = new Node(value);

    if (position <= 1 || headPtr == NULL) {  // Insert at the beginning
        newNode->next = headPtr;
        if (headPtr != NULL) // Prevents accessing NULL->prev when the list is empty.
            headPtr->prev = newNode;
        headPtr = newNode;
        return;
    }

    Node* temp = headPtr;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) 
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Insert after a specific position
void insertAfterPosition(Node*& headPtr, int value, int position) {
    Node* newNode = new Node(value);

    Node* temp = headPtr;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) 
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Insert a new node after the first even value in the list
void insertAfterEven(Node*& headPtr, int value) {
    Node* temp = headPtr;

    // Traverse the list to find the first even value
    while (temp != NULL && temp->data % 2 != 0) {
        temp = temp->next;
    }

    // If no even value is found
    if (temp == NULL) {
        cout << "No even value found in the list!\n";
        return;
    }

    // Create a new node
    Node* newNode = new Node(value);

    // Adjust pointers to insert the new node after the even node
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(Node*& headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = headPtr;
    headPtr = headPtr->next;
    if (headPtr != NULL)
        headPtr->prev = NULL;
    delete temp;
}

// Delete from end
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
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

// Delete a specific node by value
void deleteNode(Node*& headPtr, int key) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = headPtr;

    // If the node to be deleted is the head
    if (headPtr->data == key) {
        headPtr = headPtr->next;
        if (headPtr != NULL) 
            headPtr->prev = NULL;
        delete temp;
        return;
    }

    // Traverse to find the node
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        cout << "Node not found!\n";
        return;
    }

    // If node is found, update links
    if (temp->next != NULL) 
        temp->next->prev = temp->prev;
    
    if (temp->prev != NULL) 
        temp->prev->next = temp->next;

    delete temp;
}


// Search for a value (Same as singly link list)
bool search(Node* headPtr, int key) {
    Node* temp = headPtr;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Count number of nodes (Same as singly link list)
int countNodes(Node* headPtr) {
    int count = 0;
    Node* temp = headPtr;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Sorting in ascending order (Same as singly link list)
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

// Sorting in descending order (Same as singly link list)
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

// Move Head to Tail
void moveHeadToTail(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == NULL) return;

    Node* temp = headPtr;
    headPtr = headPtr->next;
    headPtr->prev = NULL;

    Node* last = headPtr;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
}

// Move Tail to Head
void moveTailToHead(Node*& headPtr) {
    if (headPtr == NULL || headPtr->next == NULL) return;

    Node* last = headPtr;
    while (last->next != NULL) {
        last = last->next;
    }

    last->prev->next = NULL;
    last->next = headPtr;
    headPtr->prev = last;
    headPtr = last;
    headPtr->prev = NULL;
}

// Delete duplicate values
void deleteDuplicates(Node*& headPtr) {
    Node* temp = headPtr;
    while (temp != NULL) {
        Node* checkedNode = temp->next;
        while (checkedNode != NULL) {
            if (temp->data == checkedNode->data) {
                Node* duplicateNode = checkedNode;
                checkedNode->prev->next = checkedNode->next;
                if (checkedNode->next != NULL)
                    checkedNode->next->prev = checkedNode->prev;
                checkedNode = checkedNode->next;
                delete duplicateNode;
            } else {
                checkedNode = checkedNode->next;
            }
        }
        temp = temp->next;
    }
}

// Reverse doubly linked list
void reverseList(Node*& headPtr) {
    Node* temp = NULL;
    Node* current = headPtr;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        headPtr = temp->prev;
}

// Swap two nodes
void swapNodes(Node*& headPtr, int x, int y) {
    if (x == y) return;

    Node *currX = headPtr, *currY = headPtr;
    while (currX && currX->data != x) 
		currX = currX->next;
    while (currY && currY->data != y) 
		currY = currY->next;

    if (!currX || !currY) 
		return;

    if (currX->prev) 
		currX->prev->next = currY;
    else 
		headPtr = currY;

    if (currY->prev) 
		currY->prev->next = currX;
    else 
		headPtr = currX;

    swap(currX->prev, currY->prev);
    swap(currX->next, currY->next);

    if (currX->next) 
		currX->next->prev = currX;
    if (currY->next) 
		currY->next->prev = currY;
}

// Print list in backward direction
void printBackward(Node* headPtr) {
    if (headPtr == NULL) {
        cout << "List is empty!\n";
        return;
    }

    // Move to the last node
    Node* temp = headPtr;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print in reverse order
    cout << "\nBackward: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// Display doubly linked list (Same as singly link list)
void display(Node* headPtr) {
    Node* temp = headPtr;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
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
    
    cout << "Inserting 15 before position 3...\n";
    insertBeforePosition(headPtr, 15, 3);
    display(headPtr);
    
    cout << "\nInserting 25 after position 3...\n";
    insertAfterPosition(headPtr, 25, 3);
    display(headPtr);

    cout << "\nDoubly Linked List: ";
    display(headPtr);
    
    // Insert after the first even value found
    cout << "\nInserting 99 after first even value ...\n";
    insertAfterEven(headPtr, 99);
    display(headPtr);
    
    // Print list in backward direction
    printBackward(headPtr);

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
    
    cout << "\nDeleting node with value 20...\n";
    deleteNode(headPtr, 20);
    display(headPtr);

    cout << "\nReversing Doubly Linked List...\n";
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
    cout << (search(headPtr, 10) ? "Found" : "Not Found") << endl;

    return 0;
}
