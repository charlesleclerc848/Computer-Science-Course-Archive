#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert into BST
Node* insert(Node* root, int key) {
    if (!root) 
		return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// In-order traversal with range filtering
void printRange(Node* root, int lowerBound, int upperBound) {
    if (!root) 
		return;

    if (lowerBound < root->data)
        printRange(root->left, lowerBound, upperBound);

    if (root->data >= lowerBound && root->data <= upperBound)
        cout << root->data << " ";

    if (upperBound > root->data)
        printRange(root->right, lowerBound, upperBound);
}

int main() {
    Node* root = nullptr;
    int n, val, lowerBound, upperBound;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter lower and upper bounds: ";
    cin >> lowerBound >> upperBound;

    cout << "Nodes in the range [" << lowerBound << ", " << upperBound << "]: ";
    printRange(root, lowerBound, upperBound);
    cout << endl;

    return 0;
}
