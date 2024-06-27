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

    void insert(Node*& root,int data)
    {
        Node *newNode=new Node(data);
        if (root==nullptr)
        {
            root=newNode;
        }
        else if (newNode->data>root->data)
        {
            insert(root->right,data);
        }
        else
        {
            insert(root->left,data);
        }
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

    bool searchinBST(Node* root, int key) {
    if (root == nullptr)
        return false; 

    if (root->data == key)
        return true; 

    if (key < root->data)
        return searchinBST(root->left, key); // Search in the left subtree
    else
        return searchinBST(root->right, key); // Search in the right subtree
    }

    Node* deleteinBST(Node* root,int key)
    {
        Node* current=root;
        if(current==nullptr)
        return 0;

        if(key < root->data) 
        {
            root->left = deleteinBST(root->left, key);
        } 
        else if (key > root->data) 
        {
            root->right = deleteinBST(root->right, key);
        } 
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteinBST(root->right, temp->data);
        }
        return root;
    }

    void deleteNode(int key) {
        root = deleteinBST(root,key);
    }
    Node* findMinValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

};

int main(){
    BST b1;
    b1.insert(b1.root,0);
    b1.insert(b1.root,1);
    b1.insert(b1.root,2);
    b1.insert(b1.root,3);
    b1.insert(b1.root,4);
    b1.insert(b1.root,5);
    b1.insert(b1.root,6);
    b1.print();

    int x;
    cout<<"\nEnter Value to search: "<<endl;
    cin>>x;
    bool ans;
    ans=b1.searchinBST(b1.root,x);
    if (ans==true)
    {
        cout<<"Value found!"<<endl;
    }
    else
    {
        cout<<"fail"<<endl;
    }

    int y;
    cout<<"\nEnter Value to delete: ";
    cin>>y;

    b1.deleteNode(y);

    cout<<"BST after deletion: ";
    b1.print();
}