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

// Find minimum value (leftmost node)
int findMin(Node* root) {
    if (!root) 
		return -1; // Tree is empty
    if (!root->left) 
		return root->data;
    return findMin(root->left);
}

// Find maximum value (rightmost node)
int findMax(Node* root) {
    if (!root) 
		return -1; // Tree is empty
    if (!root->right) 
		return root->data;
    return findMax(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    int minVal = findMin(root);
    int maxVal = findMax(root);

    cout << "\nSmallest element in BST: " << minVal << endl;
    cout << "Largest element in BST: " << maxVal << endl;

    return 0;
}
