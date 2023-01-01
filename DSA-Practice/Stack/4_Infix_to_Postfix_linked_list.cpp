#include<iostream>
#include<string.h>
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
        char stackTop();
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
    {
        return -1;
    }
    else
    {
        x = top->data;
        Node *p = top;
        top = top->next;
        delete p;
    }
    return x;
}

char Stack::stackTop()
{
    if(top==NULL)
        return -1;
    else
    {
        return top->data;
    }
}

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    else
        return 1;
}

int precendence(char x)
{
    if(x=='^')
        return 2;
    else if(x=='*' || x=='/')
        return 1;
    else if(x=='+' || x=='-')
        return 0;
    else
        return -1;
}

char * infixToPostfix(char *exp)
{
    int i=0,j=0;
    char t, *postfixexp;
    postfixexp = new char[strlen(exp)+1];
    Stack st;
    while(exp[i]!='\0')
    {
        t=exp[i++];
        if(isOperand(t))
            postfixexp[j++] = t;
        else
        {
            if(t=='(')
                st.push(t);
            else if(t==')')
            {
                while(st.stackTop()!='(')
                    postfixexp[j++] = st.pop();
                st.pop();
            }
            else
            {
                while(!st.isEmpty() && (precendence(t)<=precendence(st.stackTop())))
                    postfixexp[j++] = st.pop();
                st.push(t);
            }
        }
    }
    while(!st.isEmpty())
        postfixexp[j++] = st.pop();
    postfixexp[j] = '\0';
    return postfixexp;
}

int main()
{
    char infix[]="((4+8)(6-5))/((3-2)(2+2))";
    cout << infixToPostfix(infix);
    return 0;
}