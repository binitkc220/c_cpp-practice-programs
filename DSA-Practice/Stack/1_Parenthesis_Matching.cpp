#include<iostream>
using namespace std;

class Node
{
    public:
        char data;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        bool isEmpty();
        void push(char x);
        char pop();
        void Display();
};

bool Stack::isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void Stack::push(char x)
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

char Stack::pop()
{
    char x=-1;
    if(top==NULL)
        cout << "Stack is Empty!" << endl;
    else
    {
        x = top->data;
        Node *p = top;
        top = top->next;
        delete p;
    }
    return x;
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

bool isBalance(char *exp)
{
    Stack s1;
    char x;
    for(int i=0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            s1.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(s1.isEmpty())
                return 0;
            x = s1.pop();
            if(exp[i]==')' && x=='(')
                continue;
            else if(exp[i]=='}' && x=='{')
                continue;
            else if(exp[i]==']' && x=='[')
                continue;
            else
                return 0;
        }
    }
    if(s1.isEmpty())
        return 1;
    return 0;
}

int main()
{
    char exp[] = "{([a+b]*[c+d])/e}";
    cout << isBalance(exp);
}