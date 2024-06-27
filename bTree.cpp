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

class BinaryTree{
    public:
    Node* root=nullptr;

    Node* insert(Node* root)
    {
        int data;
        cout<<"Enter Data: ";
        cin>>data;
        //root
        root=new Node(data);

        if (data==-1)
        {
            return NULL;
        }

        cout<<"Enter Data for left of "<<data<<endl;
        root->left=insert(root->left);
        cout<<"Enter Data for Right of "<<data<<endl;
        root->right=insert(root->right);
    }

    int preOrdertrav(Node* root)
    {
        if (root==nullptr)
        {
            return -1;
        }

        preOrdertrav(root->left);
        cout<<root->data<<" ";
        preOrdertrav(root->right);
    }

    int checkLeafs(Node* root)
    {
        int count=0;
        count=preOrdertrav(root);
        cout<<"Leaf Nodes: "<<count<<endl;
    }

    void recursiveTrav(Node* root)
    {
        if (root==nullptr)
        {
            return;
        }

        cout<<root->data<<" ";
        if (root->left!=nullptr && root->right!=nullptr)
        {
            cout<<root->left->data<<" ";
            cout<<root->right->data<<" ";
        }

        recursiveTrav(root->left);
        recursiveTrav(root->right);
    }

};

int main(){
    BinaryTree b1;
    Node* root=nullptr;
    root=b1.insert(b1.root);
    b1.preOrdertrav(root);
    cout<<"\n\n";
    b1.recursiveTrav(b1.root);
}