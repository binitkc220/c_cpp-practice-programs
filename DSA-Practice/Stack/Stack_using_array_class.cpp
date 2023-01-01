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

int main()
{
    Stack<int> s1(5);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.stackTop() << endl;
}