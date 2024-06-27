#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node()
    {
        data=0;
        left=nullptr;
        right=nullptr;
    }

    Node(int d)
    {
        data=d;
        left=nullptr;
        right=nullptr;
    }
};

class BST{
    public:
    Node* root=nullptr;

    Node* insert(Node*& root,int data)
    {
        Node *newNode=new Node(data);
        if (root==nullptr)
        {
            return root=newNode;
        }
        else if (newNode->data>root->data)
        {
            return insert(root->right,data);
        }
        else
        {
            return insert(root->left,data);
        }
        return root;
    }

    void preOrderTrav(Node* root)
    {
        if (root==nullptr)
        {
            return;
        }
        preOrderTrav(root->left);
        cout<<root->data<<" ";
        preOrderTrav(root->right);
    }

    void print()
    {
        preOrderTrav(root);
    }

    bool isBST(Node* root) 
    {
        return isBSTUtil(root, nullptr, nullptr);
    }

    bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
        if (root == nullptr) {
            return true; 
        }

        if ((minNode != nullptr && root->data <= minNode->data) ||
            (maxNode != nullptr && root->data >= maxNode->data)) {
            return false; // Node's data violates BST property.
        }

        // Recursively check left and right subtrees with updated bounds.
        return isBSTUtil(root->left, minNode, root) &&
               isBSTUtil(root->right, root, maxNode);
    }
};


int main(){
    BST t1;
    Node* root=nullptr;
    root=t1.insert(t1.root, 5);
    t1.insert(root, 2);
    t1.insert(root, 4);
    t1.insert(root, 1);
    t1.insert(root, 3);

    t1.print();
    bool ans;
    ans=t1.isBST(t1.root);
    if (ans==true)
    {
        cout<<"\nissa bst"<<endl;
    }
    else
    {
        cout<<"\nnopeee"<<endl;
    }
}