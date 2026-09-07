#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build binary tree recursively
Node* createTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return nullptr;

    Node* node = new Node(val);
    cout << "Enter left child of " << val << ":\n";
    node->left = createTree();

    cout << "Enter right child of " << val << ":\n";
    node->right = createTree();

    return node;
}

// Function to count nodes with exactly one child
int countOneChildNodes(Node* root) {
    if (!root) return 0;

    int count = 0;
    if ((root->left && !root->right) || (!root->left && root->right))
        count = 1;

    return count + countOneChildNodes(root->left) + countOneChildNodes(root->right);
}

int main() {
    cout << "Create the binary tree:\n";
    Node* root = createTree();

    int oneChildCount = countOneChildNodes(root);
    cout << "\nNumber of nodes with exactly one child: " << oneChildCount << endl;

    return 0;
}
