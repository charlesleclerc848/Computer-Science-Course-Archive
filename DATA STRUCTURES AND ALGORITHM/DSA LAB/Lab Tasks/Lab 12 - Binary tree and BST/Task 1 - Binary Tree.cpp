#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Recursive function to create the binary tree
Node* createTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) 
		return nullptr;

    Node* newNode = new Node();
    newNode->data = val;

    cout << "Enter left child of " << val << ":\n";
    newNode->left = createTree();

    cout << "Enter right child of " << val << ":\n";
    newNode->right = createTree();

    return newNode;
}

// Traversals
void preorder(Node* root) {
    if (root == nullptr) 
		return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) 
		return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) 
		return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Create the binary tree:\n";
    Node* root = createTree();

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}
