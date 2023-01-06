#include<iostream>
using namespace std;
template<class T>
class Queue
{
    int size,front,rear;
    T *q;
    public:
        Queue(int size)
        {
            this->size = size;
            q = new T[size];
            front = -1;
            rear = -1;
        }
        bool isFull()
        {
            if(rear==size-1)
                return 1;
            else
                return 0;
        }
        bool isEmpty()
        {
            if(front==rear)
                return 1;
            else
                return 0;
        }
        void enqueue(T x)
        {
            if(isFull())
            {
                cout<< "Queue is Full !" << endl;
            }
            else
            {
                q[++rear] = x;
            }
        }
        T dequeue()
        {
            T x=-1;
            if(isEmpty())
            {
                cout << "Queue is Empty !" << endl;
            }
            else
                x = q[++front];
            return x;
        }
        void display()
        {
            for(int i=front+1;i<=rear;i++)
                cout << q[i] << "\t";
            cout << endl;
        }
};
int main()
{
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
}