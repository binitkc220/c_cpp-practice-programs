#ifndef QueueCpp_h
#define QueueCpp_h

#include<iostream>

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class LLNode
{
    public:
        Node *data;
        LLNode *next;
};
class Queue
{
    private:
        LLNode *head;
    public:
        Queue(){head=NULL;}
        bool isEmpty(){return (head==NULL)?1:0;}
        void enqueue(Node *data);
        Node * dequeue();
        void display();
};
void Queue:: enqueue(Node *data)
{
    LLNode *t;
    t = new LLNode;
    t->data = data;
    t->next = NULL;
    if(head==NULL)
        head = t;
    else
    {
        LLNode *p=head;
        while(p->next!=NULL)
            p=p->next;
        p->next = t;
    }
}
Node * Queue:: dequeue()
{
    LLNode *t;
    Node *x=NULL;
    if(isEmpty())
    {
        printf("Queue is Empty!");
        exit(0);
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
void Queue:: display()
{
    LLNode *p=head;
    while(p)
    {
        std::cout << p->data << "\t";
        p=p->next;
    }
    std::cout << std::endl;
}

#endif