#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class StackLL
{
    private:
        Node *head;
    public:
        StackLL(){head=NULL;}
        bool isEmpty(){return (head==NULL)?1:0;}
        void push(int data);
        int pop();
        void display();
};
void StackLL:: push(int data)
{
    Node *t;
    t = new Node;
    t->data = data;
    if(head==NULL)
    {
        t->next = NULL;
        head = t;
    }
    else
    {
        t->next = head;
        head = t;
    }
}
int StackLL:: pop()
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
void StackLL:: display()
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
    StackLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout << "Popped Element = " << s.pop() << endl;
    s.display();   
}