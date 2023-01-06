//3. infix to prefix
#include<iostream>
#include<string.h>
using namespace std;

template<class T>
class Stack
{
    int top,size;
    T *st;
    public:
        Stack(){top=-1;}

        Stack(int size)
        {
            this->size = size;
            top = -1;
            st = new T[size];
        }

        bool isEmpty()
        {
            if(top==-1)
                return 1;
            else
                return 0;
        }

        bool isFull()
        {
            if(top==size-1)
                return 1;
            else
                return 0;
        }

        void push(T  x)
        {
            if(!isFull())
            {
                top++;
                st[top] = x;
            }
            else
                cout << "Stack Overflow !" << endl;
        }

        T pop()
        {
            if(!isEmpty())
                return st[top--];
            else
                cout << "Stack is Empty !" << endl;
        }

        T stackTop()
        {
            if(!isEmpty())
                return st[top];
            else
                cout << "Stack is Empty !" << endl;
        }

        ~Stack()
        {
            delete []st;
        }
};

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

char * infixToPrefix(char *exp)
{
    int i=0,j=0;
    char t, *prefixexp;
    exp = strrev(exp);
    while(exp[i]!=0)
    {
        if(exp[i]=='(')
            exp[i] = ')';
        else if(exp[i]==')')
            exp[i] = '(';
        i++;
    }
    i=0;
    prefixexp = new char[strlen(exp)+1];
    Stack<char> st(strlen(exp)+1);
    while(exp[i]!='\0')
    {
        t=exp[i++];
        if(isOperand(t))
            prefixexp[j++] = t;
        else
        {
            if(t=='(')
                st.push(t);
            else if(t==')')
            {
                while(st.stackTop()!='(')
                    prefixexp[j++] = st.pop();
                st.pop();
            }
            else
            {
                while(!st.isEmpty() && (precendence(t)<=precendence(st.stackTop())))
                    prefixexp[j++] = st.pop();
                st.push(t);
            }
        }
    }
    while(!st.isEmpty())
        prefixexp[j++] = st.pop();
    prefixexp[j] = '\0';
    prefixexp = strrev(prefixexp);
    return prefixexp;
}

int main()
{
    char infix[]="(A+B^C)*D+E^5";
    cout << infixToPrefix(infix);
    return 0;
}