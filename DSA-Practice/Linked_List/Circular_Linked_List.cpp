#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class CircularLinkedList
{
    private:
        Node *head;
    public:
        CircularLinkedList(){head=NULL;}
        ~CircularLinkedList();

        void Display();
        void Insert(int x);
        void Delete(int index);
        void Search(int key);
};

CircularLinkedList::~CircularLinkedList()
{
    Node *p=head;
    while(head)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void CircularLinkedList::Display()
{
    Node *p=head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    }while(p!=head);
    cout << endl;
}

void CircularLinkedList::Insert(int x)
{
    Node *t;
    t = new Node;
    t->data = x;
    if(head==NULL)
    {
        head=t;
        t->next = head;
    }
    else
    {
        Node *p=head;
        while(p->next!=head)
            p=p->next;
        p->next = t;
        t->next = head;
    }
}

void CircularLinkedList::Delete(int index)
{
    Node *p=head, *q=head;
    if(index==0)
    {
        do{
            q=q->next;
        }while(q->next!=head);
        cout << "Deleted Element = " << p->data << endl;
        head = head->next;
        delete p;
        q->next = head;
    }
    else
    {
        for(int i=0;i<index;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        cout << "Deleted Element = " << p->data << endl;
        delete p;
    }
}

void CircularLinkedList::Search(int key)
{
    Node *p=head;
    int i=0;
    do
    {
        if(p->data==key)
        {
            cout << "Key Found at index " << i << endl;
            return;
        }
        p=p->next;
        i++;
    }while(p!=head);
    cout << "key not found!" << endl;
}

int main()
{
    CircularLinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Display();
    l1.Search(2);
    l1.Delete(0);
    l1.Display();
}