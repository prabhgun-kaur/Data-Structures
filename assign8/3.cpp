#include <iostream>
#include <algorithm> 
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};


Node* insertNode(Node* root, int v) {
    if (root == nullptr) {
        return new Node(v);
    }
    if (v < root->data) {
        root->left = insertNode(root->left, v);
    } else if (v > root->data) {
        root->right = insertNode(root->right, v);
    }
    
    return root;
}

Node* findMinNode(Node* root) {
    if (!root) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
      
        if (root->left == nullptr) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == nullptr) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }

        
        Node* succ = findMinNode(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}


int maxDepth(Node* root) {
    if (!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

int minDepth(Node* root) {
    if (!root) return 0;
    
    if (root->left == nullptr && root->right != nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr && root->left != nullptr)
        return 1 + minDepth(root->left);
    
    return 1 + min(minDepth(root->left), minDepth(root->right));
}


void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        root = insertNode(root, v);
    }

    cout << "BST in-order: ";
    inorderPrint(root);
    cout << "\n";

    cout << "Max depth = " << maxDepth(root) << "\n";
    cout << "Min depth = " << minDepth(root) << "\n";

    int del;
    cout << "Enter element to delete: ";
    cin >> del;
    root = deleteNode(root, del);

    cout << "After deletion, BST in-order: ";
    inorderPrint(root);
    cout << "\n";
    cout << "Max depth = " << maxDepth(root) << "\n";
    cout << "Min depth = " << minDepth(root) << "\n";

    return 0;
}
