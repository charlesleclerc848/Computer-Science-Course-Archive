#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
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

    // Insert at specific position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) {
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
        if (head->next == NULL) {
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

        if (head->data == key) {
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

    // Swap two nodes
    void swapNodes(int x, int y) {
        if (x == y) return;

        Node* prevX = NULL, * currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        Node* prevY = NULL, * currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (!currX || !currY) {
            cout << "One or both elements not found!\n";
            return;
        }

        if (prevX) prevX->next = currY;
        else head = currY;

        if (prevY) prevY->next = currX;
        else head = currX;

        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }

    // Sort linked list (Ascending)
    void sortAscending() {
        Node* temp1 = head;
        while (temp1) {
            Node* temp2 = temp1->next;
            while (temp2) {
                if (temp1->data > temp2->data) {
                    swap(temp1->data, temp2->data);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    // Sort linked list (Descending)
    void sortDescending() {
        Node* temp1 = head;
        while (temp1) {
            Node* temp2 = temp1->next;
            while (temp2) {
                if (temp1->data < temp2->data) {
                    swap(temp1->data, temp2->data);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    // Reverse the linked list
    void reverseList() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Delete duplicates
    void deleteDuplicates() {
        Node* current = head;
        while (current != NULL && current->next != NULL) {
            Node* temp = current;
            while (temp->next != NULL) {
                if (current->data == temp->next->data) {
                    Node* duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete duplicate;
                } else {
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }

    // Move head to tail & tail to head
    void moveHeadToTail() {
        if (head == NULL || head->next == NULL) return;  // Empty or single node list

	    Node* temp = head;
	    head = head->next;  // Move head to next node
	
	    Node* current = head;
	    while (current->next != NULL) {
	        current = current->next;
	    }
	    
	    current->next = temp;  // Append old head to last
	    temp->next = NULL;  // Set old head's next to NULL
    }

    void moveTailToHead() {
        if (head == NULL || head->next == NULL) return;  // Empty or single node list

	    Node* secondLast = NULL;
	    Node* last = head;
	
	    while (last->next != NULL) {
	        secondLast = last;
	        last = last->next;
	    }
	
	    secondLast->next = NULL;  // Remove last node from current position
	    last->next = head;  // Point last node to old head
	    head = last;  // Update head to new first node
    }

    // Display linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
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
    
    cout << "Linked List: ";
    list.display();
    
    cout << "\nSorting in Ascending Order...\n";
    list.sortAscending();
    list.display();

    cout << "\nSorting in Descending Order...\n";
    list.sortDescending();
    list.display();
    
    cout << "\nSwapping 10 and 30...\n";
    list.swapNodes(10, 30);
    list.display();

    cout << "\nReversing the List...\n";
    list.reverseList();
    list.display();

    cout << "\nDeleting Duplicates...\n";
    list.deleteDuplicates();
    list.display();

    cout << "\nMoving Head to Tail...\n";
    list.moveHeadToTail();
    list.display();

    cout << "\nMoving Tail to Head...\n";
    list.moveTailToHead();
    list.display();

    cout << "\nInserting 25 at position 3...\n";
    list.insertAtPosition(25, 3);
    list.display();

    cout << "\nDeleting first node...\n";
    list.deleteFromBeginning();
    list.display();

    cout << "\nDeleting last node...\n";
    list.deleteFromEnd();
    list.display();

    cout << "\nDeleting node with value 25...\n";
    list.deleteNode(25);
    list.display();
	
    cout << "\nSearching for 10: ";
    if(list.search(10)) {
        cout << "Found";
    } else {
        cout << "Not Found";
    }

    cout << "\nTotal nodes in the list: " << list.countNodes() << endl;

    return 0;
}
