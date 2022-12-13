#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void isEmpty();
        void push(int x);
        void pop();
        void Display();
};

void Stack::isEmpty()
{
    if(top==NULL)
        cout << "Stack is Empty!" << endl;
    else
        cout << "Stack is not Empty !" << endl;
}

void Stack::push(int x)
{
    Node *t = new Node;
    if(t==NULL)
        cout << "Stack is Empty!" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

void Stack::pop()
{
    int x=-1;
    if(top==NULL)
        cout << "Stack is Empty!" << endl;
    else
    {
        x = top->data;
        Node *p = top;
        top = top->next;
        delete p;
    }
    cout << "Popped Element = " << x << endl;
}

void Stack::Display()
{
    Node *p=top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    Stack s1;
    s1.isEmpty();
    s1.push(5);
    s1.Display();
    s1.push(10);
    s1.Display();
    s1.push(15);
    s1.Display();
    s1.pop();
    s1.Display();
    s1.isEmpty();
    return 0;
}