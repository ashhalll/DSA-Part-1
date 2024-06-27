#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        data=0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int n)
    {
        data=n;
        next=nullptr;
        prev=nullptr;
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

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList()
    {
        head=nullptr;
    }

    DoublyLinkedList(Node* n)
    {
        head=n;
    }

    void append(int data)
    {
        Node *newNode= new Node(data); 
        if (head==nullptr)
        {
            head=newNode;
        }

        else
        {
            Node* Current=head;
            while (Current->next != nullptr)
            {
                Current=Current->next;
            }
            Current->next=newNode;
            newNode->next=nullptr;
            newNode->prev=Current;
        }
    }

    void prepend(int data)
    {
        Node* newNode= new Node(data);
        if (head==nullptr)
        {
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void insertion(int pos, int data)
    {
        Node* newNode= new Node(data);
        if (pos==1)
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }

        else
        {
            int count=1;
            Node* current=head;
            while (count<pos-1)
            {
                current=current->next;
                count++;
            }
            newNode->next=current->next;
            current->next->prev=newNode;
            current->next=newNode;
            newNode->prev=current;
        }
    }

    void deletion(int pos)
    {
        Node* current=head;
        if (pos==1)
        {
            current->next->prev=nullptr;
            current->next=nullptr;
            head=current->next;
            delete current;
        }
        else
        {
            Node* prev=nullptr;
            int count=1;
            while (count<pos)
            {
                prev=current;
                current=current->next;
                count++;
            }
            current->prev=nullptr;
            prev->next=current->next;
            current->next=nullptr;
            delete current;        
        }
    }

    void display()
    {
        Node* current=head;
        while (current!=nullptr)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }


};

int main()
{
    DoublyLinkedList d1;
    d1.append(2);
    d1.append(4);
    d1.append(6);
    d1.display();

    d1.prepend(8);
    d1.prepend(5);
    d1.display();

    d1.insertion(5, 10);
    d1.display();

    d1.deletion(3);
    d1.display();
}