#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Recursive tree creation
Node* createTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) 
		return nullptr;

    Node* node = new Node();
    node->data = val;

    cout << "Enter left child of " << val << ":\n";
    node->left = createTree();

    cout << "Enter right child of " << val << ":\n";
    node->right = createTree();

    return node;
}

// Count total nodes
int countTotalNodes(Node* root) {
    if (!root) 
		return 0;
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if (!root) 
		return 0;
    if (!root->left && !root->right) 
		return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    cout << "Create the binary tree:\n";
    Node* root = createTree();

    int totalNodes = countTotalNodes(root);
    int leafNodes = countLeafNodes(root);

    cout << "\nTotal number of nodes: " << totalNodes << endl;
    cout << "Number of leaf nodes: " << leafNodes << endl;

    return 0;
}
