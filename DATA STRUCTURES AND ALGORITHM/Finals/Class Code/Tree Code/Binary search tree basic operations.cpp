#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

// Inorder traversal: left -> root -> right
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Insert a value into BST
void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value); // Base case: create new node
        return;
    }
    if (value == root->data) {
        cout << "Duplicate value ignored: " << value << endl; // Ignore duplicates
    }
    else if (value < root->data) {
        insert(root->left, value); // Go to left subtree
    }
    else {
        insert(root->right, value); // Go to right subtree
    }
}

// Find the minimum value node in a subtree (used for in-order successor)
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) // Base case: if tree is empty.
		return root;

    if (key < root->data) {
        // Go left if key is smaller
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        // Go right if key is larger
        root->right = deleteNode(root->right, key);
    } 
    else {
    	// Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Found the node to delete
        if (root->left == nullptr) {
            // One child or no child (right child case)
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            // One child (left child case)
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Two children: Get the in-order successor
        TreeNode* temp = findMin(root->right);
        root->data = temp->data; // Place the inorder successor in position of the node to be deleted
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

int main() {
    int values[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
	int arraySize = sizeof(values)/sizeof(values[0]);
    TreeNode* root = nullptr;

    // Insert all values
    for (int i = 0; i<arraySize; ++i) {
        insert(root, values[i]);
    }

    cout << "Inorder traversal of the BST:\n";
    inorder(root);
    cout << endl;

    int delVal;
    cout << "\nEnter a value to delete: ";
    cin >> delVal;

    root = deleteNode(root, delVal); // Perform deletion

    cout << "\nInorder traversal after deletion:\n";
    inorder(root);
    cout << endl;

    return 0;
}
