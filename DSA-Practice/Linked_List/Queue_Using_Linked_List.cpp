#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class QueueLL
{
    private:
        Node *head;
    public:
        QueueLL(){head=NULL;}
        bool isEmpty(){return (head==NULL)?1:0;}
        void enqueue(int data);
        int dequeue();
        void display();
};
void QueueLL:: enqueue(int data)
{
    Node *t;
    t = new Node;
    t->data = data;
    t->next = NULL;
    if(head==NULL)
        head = t;
    else
    {
        Node *p=head;
        while(p->next!=NULL)
            p=p->next;
        p->next = t;
    }
}
int QueueLL:: dequeue()
{
    Node *t;
    int x=-1;
    if(isEmpty())
    {
        printf("Stack is Empty!");
        return 0;
    }
    else
    {
        t=head;
        x=t->data;
        head=head->next;
        delete t;
    }
    return x;
}
void QueueLL:: display()
{
    Node *p=head;
    while(p)
    {
        cout << p->data << "\t";
        p=p->next;
    }
    cout << endl;
}

int main()
{
    QueueLL s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.display();
    cout << "dequeued Element = " << s.dequeue() << endl;
    s.display();   
}