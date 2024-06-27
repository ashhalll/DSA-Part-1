#include <iostream>
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
};

class SinglyLinkedlist{
    public:
    Node *head;

    SinglyLinkedlist()
    {
        head=nullptr;
    }

    SinglyLinkedlist(Node *val)
    {
        head=val;
    }
    
    void append(int x)
    {
        Node *newNode = new Node (x);
        if (head==nullptr)
        {
            head=newNode;
        }
        else
        {
            Node *current=head;
            while (current->next!=nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertMid(int position, int data)
    {
        Node* newNode=new Node(data);
        Node* current=head;
        int count=1;
        while(count<position-1)
        {
            current=current->next;
            count++;
        }
        newNode->next=current->next;
        current->next=newNode;
    }

    void prepend(int x)
    {
        Node *newNode= new Node(x);
        newNode->next=head;
        head=newNode;
    }

    bool search(int key)
    {
        Node *current=head;
        while (current!=nullptr)
        {
            if (current->data==key)
            {
                return true;
            }
            current=current->next;
        }
        return false;
    }

    void display()
    {
        Node *current=head;
        while (current!=nullptr)
        {
            cout<<current->data<<"->";
            current=current->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    SinglyLinkedlist l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.display();

    l1.prepend(5);
    l1.display();

    // cout<<l1.search(7);

    l1.insertMid(4,9);
    l1.display();
}