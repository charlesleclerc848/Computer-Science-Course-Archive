#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to build the tree recursively
Node* insertNode() {
    int value;
    cout << "Enter node value (-1 to skip): ";
    cin >> value;
    
    if (value == -1) 
		return nullptr;

    Node* newNode = new Node(value);
    
    cout << "Enter left child of " << value << endl;
    newNode->left = insertNode();
    
    cout << "Enter right child of " << value << endl;
    newNode->right = insertNode();

    return newNode;
}

// Inorder Traversal: Left ? Root ? Right
void inorder(Node* root) {
    if (root == nullptr) 
		return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal: Root ? Left ? Right
void preorder(Node* root) {
    if (root == nullptr) 
		return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal: Left ? Right ? Root
void postorder(Node* root) {
    if (root == nullptr) 
		return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Count total nodes
int countNodes(Node* root) {
    if (root == nullptr) 
		return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if (root == nullptr) 
		return 0;
    if (root->left == nullptr && root->right == nullptr) 
		return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Calculate height
int treeHeight(Node* root) {
    if (root == nullptr) 
		return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Search a value
bool search(Node* root, int key) {
    if (root == nullptr) 
		return false;
    if (root->data == key) 
		return true;
    return search(root->left, key) || search(root->right, key);
}

// Mirror the tree
void mirror(Node* root) {
    if (root == nullptr) 
		return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Delete the tree
void deleteTree(Node* root) {
    if (root == nullptr) 
		return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Sum of all nodes
int sumNodes(Node* root) {
    if (root == nullptr) 
		return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Print all leaf nodes
void printLeafNodes(Node* root) {
    if (root == nullptr) 
		return;
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Helper function to delete the deepest node
void deleteDeepest(Node* root, Node* delNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
		
		// Check left child
        if (temp->left) {
            if (temp->left == delNode) {
                delete temp->left;
                temp->left = nullptr;
                return;
            } else {
                q.push(temp->left);
            }
        }
		
		// Check right child
        if (temp->right) {
            if (temp->right == delNode) {
                delete temp->right;
                temp->right = nullptr;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

// Function to delete a node with given value (not BST logic)
Node* deleteNode(Node* root, int key) {
//	    1
//    /   \
//   2     3
//  / \
// 4   5
// Now we want to delete node with value 2.

    if (root == nullptr) 
		return nullptr;

	// If root is the only node and matches the key
    if (root->left == nullptr && root->right == nullptr) {
        if (root->data == key) {
        	cout << "Node " << key << " has been deleted." << endl;
            delete root;
            return nullptr;
        } else {
        	cout<<"Node not found with value "<<key<<endl;
            return root;
        }
    }

    queue<Node*> q; // Queue is used for level order traversal (BFS)
    q.push(root); // pushes Node 1 -> Queue = [1]

    Node* keyNode = nullptr; // We initialize keyNode to store the node that needs to be deleted
    Node* temp = nullptr; // A pointer to track the current node during traversal

	// Level-order traversal to find the node to delete and the deepest node
    while (!q.empty()) { // Start BFS traversal
        temp = q.front(); // Node 1
        q.pop(); // Queue = []

        if (temp->data == key) // temp->data == 2? ❌
            keyNode = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
        // Queue = [2, 3]
    }

	// If key node is found, replace it with the deepest node and delete the deepest node
    if (keyNode != nullptr) {
    	cout << "Node " << key << " has been deleted." << endl;
        keyNode->data = temp->data;
        deleteDeepest(root, temp); // Now we delete the deepest node (5) from the tree        
    }
    else
    {
    	cout<<"Node not found with value "<<key<<endl;
	}

    return root;
}




int main() {
	cout << "Build your binary tree" << endl;
    Node* root = insertNode();
    
    int choice;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Inorder Traversal" << endl;
        cout << "2. Preorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Count Total Nodes" << endl;
        cout << "5. Count Leaf Nodes" << endl;
        cout << "6. Height of Tree" << endl;
        cout << "7. Search for a Value" << endl;
        cout << "8. Mirror the Tree" << endl;
        cout << "9. Delete the Tree" << endl;
        cout << "10. Sum of All Nodes" << endl;
        cout << "11. Print All Leaf Nodes" << endl;
        cout << "12. Delete a Node" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int val;
        switch (choice) {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Total Nodes: " << countNodes(root) << endl;
                break;
            case 5:
                cout << "Leaf Nodes: " << countLeafNodes(root) << endl;
                break;
            case 6:
                cout << "Height of Tree: " << treeHeight(root) << endl;
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                if (search(root, val))
                    cout << val << " is present in the tree." << endl;
                else
                    cout << val << " is NOT present in the tree." << endl;
                break;
            case 8:
                mirror(root);
                cout << "Tree mirrored successfully." << endl;
                break;
            case 9:
                deleteTree(root);
                root = nullptr;
                cout << "Tree deleted successfully." << endl;
                break;
            case 10:
                cout << "Sum of all node values: " << sumNodes(root) << endl;
                break;
            case 11:
                cout << "Leaf Nodes: ";
                printLeafNodes(root);
                cout << endl;
                break;
            case 12:
			    cout << "Enter value to delete: ";
			    cin >> val;
			    root = deleteNode(root, val);
			    break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
