#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    int getHeight(Node* node) 
    {
        if (node == nullptr) return 0;
        
        return node->height;
    }

    int getBalanceFactor(Node* node) 
    {
        if (node == nullptr) return 0;
        
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) 
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            // Duplicate values are not allowed in this example
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Perform rotations if needed to balance the tree
        if (balance > 1) {
            if (value < node->left->data) {
                // Left-Left case, perform a right rotation
                return rightRotate(node);
            } else {
                // Left-Right case, perform left-right rotation
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (balance < -1) {
            if (value > node->right->data) {
                // Right-Right case, perform a left rotation
                return leftRotate(node);
            } else {
                // Right-Left case, perform right-left rotation
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);

    cout << "Inorder traversal of the AVL tree: ";
    avl.inorder();

    return 0;
}
