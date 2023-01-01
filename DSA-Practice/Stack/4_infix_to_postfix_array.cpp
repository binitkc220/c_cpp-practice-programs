//4. infix to postfix
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

char * infixToPostfix(char *exp)
{
    int i=0,j=0;
    char t, *postfixexp;
    postfixexp = new char[strlen(exp)+1];
    Stack<char> st(strlen(exp)+1);
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