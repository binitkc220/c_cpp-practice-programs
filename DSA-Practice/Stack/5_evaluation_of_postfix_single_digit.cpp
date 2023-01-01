//3. infix to prefix
#include<iostream>
#include<string.h>
#include<math.h>
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
            {
                cout << "Stack is Empty !" << endl;
                return 0;
            }
        }

        T stackTop()
        {
            if(!isEmpty())
                return st[top];
            else
            {
                cout << "Stack is Empty !" << endl;
                return 0;
            }
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

int evaluatePostfix(char *exp)
{
    int i=0,val1,val2;
    Stack<int> s(strlen(exp)+1);
    while(exp[i]!='\0')
    {
        if(isOperand(exp[i]))
            s.push(exp[i]-'0');
        else
        {
            val1 = s.pop();
            val2 = s.pop();
            switch(exp[i])
            {
                case '+': s.push(val2+val1);break;
                case '-': s.push(val2-val1);break;      
                case '*': s.push(val2*val1);break;      
                case '/': s.push(val2/val1);break;      
                case '^': s.push(pow(val2,val1));break;      
            }
        }
        i++;
    }
    return s.pop();
}

int main()
{
    char postfix[]="12+3-21+3^-";
    cout << evaluatePostfix(postfix);
    return 0;
}