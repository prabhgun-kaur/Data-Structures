#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
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


Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}


Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur != nullptr) {
        if (cur->data == key) return cur;
        else if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}


Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->right != nullptr) {
        cur = cur->right;
    }
    return cur;
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}


Node* inorderSuccessor(Node* root, int key) {

    Node* target = searchIterative(root, key);
    if (target == nullptr) return nullptr;

    
    if (target->right != nullptr) {
        return findMin(target->right);
    }

    
    Node* succ = nullptr;
    Node* ancestor = root;
    while (ancestor != nullptr) {
        if (key < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else if (key > ancestor->data) {
            ancestor = ancestor->right;
        } else {
            break;
        }
    }
    return succ;
}


Node* inorderPredecessor(Node* root, int key) {
    
    Node* target = searchIterative(root, key);
    if (target == nullptr) return nullptr;


    if (target->left != nullptr) {
        return findMax(target->left);
    }

     Node* pred = nullptr;
    Node* ancestor = root;
    while (ancestor != nullptr) {
        if (key > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else if (key < ancestor->data) {
            ancestor = ancestor->left;
        } else {
            break;
        }
    }
    return pred;
}


void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    for (int v : arr) {
        root = insertNode(root, v);
    }

    cout << "BST (in-order): ";
    inorderPrint(root);
    cout << "\n";

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    Node* r1 = searchRecursive(root, key);
    Node* r2 = searchIterative(root, key);
    cout << "Recursive search: " << (r1 ? "Found" : "Not found") << "\n";
    cout << "Iterative search: " << (r2 ? "Found" : "Not found") << "\n";

    Node* mn = findMin(root);
    Node* mx = findMax(root);
    if (mn) cout << "Minimum element: " << mn->data << "\n";
    if (mx) cout << "Maximum element: " << mx->data << "\n";

    Node* succ = inorderSuccessor(root, key);
    if (succ) cout << "In-order Successor of " << key << " is " << succ->data << "\n";
    else cout << "In-order Successor does not exist for " << key << "\n";

    Node* pred = inorderPredecessor(root, key);
    if (pred) cout << "In-order Predecessor of " << key << " is " << pred->data << "\n";
    else cout << "In-order Predecessor does not exist for " << key << "\n";

    return 0;
}
