#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};


bool isBSTUtil(Node* node, int minVal, int maxVal) {
    if (node == nullptr) return true;
    if (node->data < minVal || node->data > maxVal)
        return false;
    return isBSTUtil(node->left, minVal, node->data - 1)
        && isBSTUtil(node->right, node->data + 1, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


Node* insertNode(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->data) root->left = insertNode(root->left, v);
    else if (v > root->data) root->right = insertNode(root->right, v);
    return root;
}

int main() {
    
    Node* root = nullptr;
    root = insertNode(root, 10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);   
    root->right->right = new Node(25);

    if (isBST(root)) cout << "Tree is a BST\n";
    else cout << "Tree is NOT a BST\n";

    return 0;
}
