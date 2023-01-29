#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList(){head=NULL;}
        LinkedList(int A[], int n);
        ~LinkedList();

        void Display();
        void Insert(int index, int x);
        void Delete(int index);
        void Search(int key);
        int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p=head;
    while(head)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::Display()
{
    Node *p=head;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void LinkedList::Insert(int index, int x)
{
    Node *t,*p=head;
    t = new Node;
    t->data = x;
    if(head==NULL)
    {
        t->next = NULL;
        head = t;
    }
    else
    {
        if(index==0)
        {
            t->next = head;
            head = t;
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                p = p->next;   
            }
            t->next = p->next;
            p->next = t;
        }
    }
}

void LinkedList::Delete(int index)
{
    Node *p=head, *q=head;
    if(index==0)
    {
        cout << "Deleted Element = " << p->data << endl;
        head = head->next;
        delete p;
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

void LinkedList::Search(int key)
{
    Node *p=head;
    int i=0;
    while(p)
    {
        if(p->data==key)
        {
            cout << "Key Found at index " << i << endl;
            return;
        }
        p=p->next;
        i++;
    }
    cout << "key not found!" << endl;
}

int LinkedList::Length()
{
    Node *p = head;
    int len=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int main()
{
    // int A[] = {1,2,3,4,5};
    // LinkedList L1(A,5);
    // L1.Display();
    // L1.Insert(6,6);
    // L1.Display();
    // cout << "The length of the linked list 1 is " << L1.Length() << endl;
    // L1.Delete(5);
    // L1.Display();
    // cout << "The length of the linked list 1 is " << L1.Length();
    LinkedList l1;
    l1.Insert(0,1);
    l1.Insert(1,2);
    l1.Insert(2,3);
    l1.Display();
    l1.Search(2);
    l1.Delete(1);
    l1.Display();
}