//2. reverse string using concept of stack
#include<iostream>
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

        void push(int  x)
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

int main()
{
    Stack<char> s1(20);
    char str[20],rev_str[20];
    int i=0;
    cout << "Enter your string : ";
    cin >> str;
    while(str[i]!='\0')
    {
        s1.push(str[i]);
        i++;
    }
    i=0;
    cout << "The reversed string is ";
    while(str[i]!='\0')
    {
        cout << s1.pop();
        i++;
    }
    return 0;
}