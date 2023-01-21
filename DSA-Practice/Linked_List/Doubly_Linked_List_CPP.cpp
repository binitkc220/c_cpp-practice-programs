#include<iostream>
using namespace std;
class Node
{
    public:
        Node *prev;
        int data;
        Node *next;
};
class DoubleLL
{
    private:
        Node *head;
    public:
        DoubleLL(){head=NULL;}
        int getLength();
        void Insert(int index, int data);
        int Delete(int index);
        void Search(int key);
        void Display();
        void displayReverse();
};

int DoubleLL::getLength()
{
    Node *p=head;
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

void DoubleLL::Insert(int index, int data)
{
    Node *t;
    t = new Node;
    t->data = data;
    if(index>getLength())
    {
        cout << "Element cannot be inserted in given position!" << endl;
        return;
    }
    if(head==NULL && index==0)  //Initialize first Node
    {
        t->next = NULL;
        t->prev = NULL;
        head = t;
    }
    else
    {
        if(index==0)    //Insert at beginning
        {
            t->prev = NULL;
            t->next = head;
            head->prev = t;
            head = t;
        }           //Insert at any position
        else
        {
            Node *p=head;
            for(int i=0;i<index-1;i++)
                p=p->next;
            t->next = p->next;
            t->prev = p;
            if(p->next!=NULL)  //Inserting is not at end
                p->next->prev = t;
            p->next = t;
        }
    }
}

int DoubleLL::Delete(int index)
{
    Node *t;
    int x=-1;
    if(head==NULL || index>=getLength())
    {
        cout << "No element to delete!" << endl;
        return 0;
    }
    if(index==0)   //Delete front node
    {
        x=head->data;
        t=head;
        head=head->next;
        head->prev = NULL;
        delete t;
    }
    else
    {
        t=head;
        for(int i=0;i<index;i++)
            t=t->next;
        x=t->data;
        t->prev->next = t->next;
        if(t->next!=NULL)    //If deleting node is not at end
            t->next->prev = t->prev;
        delete t;
    }
    return x;
}

void DoubleLL:: Search(int key)
{
    Node *p=head;
    for(int i=0;p;i++)
    {
        if(p->data == key)
        {
            cout << "Key found at index " << i << endl;
            return;
        }
        p=p->next;
    }
    cout << "Key not found!" << endl;
}

void DoubleLL:: Display()
{
    Node *p=head;
    while(p)
    {
        cout << p->data << "\t";
        p=p->next;
    }
    cout << endl;
}

void DoubleLL::displayReverse()
{
    Node *p=head;
    while(p->next!=NULL)
        p=p->next;
    while(p)
    {
        cout << p->data << "\t";
        p=p->prev;
    }
    cout << endl;
}

int main()
{
    DoubleLL l1;
    l1.Insert(0,3);
    l1.Insert(0,1);
    l1.Insert(1,2);
    l1.Insert(3,4);
    l1.Insert(4,6);
    l1.Insert(4,5);
    l1.Display();
    l1.Search(4);
    l1.Search(10);
    l1.displayReverse();
    cout << "Deleted Element at index 0 = " << l1.Delete(0) << endl;
    l1.Display();
    cout << "Deleted Element at index 2 = " << l1.Delete(2) << endl;
    l1.Display();
    cout << "Deleted Element at index 3 = " << l1.Delete(3) << endl;
    l1.Display();
}