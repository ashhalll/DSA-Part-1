#include <iostream>
#include <iterator>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node()
    {
        data=0;
        next = nullptr;
    }

    Node(int n)
    {
        data=n;
        next=nullptr;
    }

    ~Node()
    {
        int value=this->data;
        if (next!=nullptr)
        {
            delete next;
            next=nullptr;
        }
    }
};

class CircularLinkedList{
    public:
    Node *tail;

    CircularLinkedList()
    {
        tail=nullptr;
    }

    CircularLinkedList(Node* d)
    {
        tail=d;
    }

    void append(int d)
{
    Node* newNode = new Node(d);
    if (tail == nullptr)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}


    void display()
    {
        Node* current=tail->next;
        do
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        while (current!=tail->next);
        cout<<endl;
    }
};

int main()
{
    CircularLinkedList l1;
    l1.append(2);
    l1.append(4);
    l1.display();

    l1.append(8);
    l1.display();
}