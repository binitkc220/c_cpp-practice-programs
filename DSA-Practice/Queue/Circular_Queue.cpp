#include<iostream>
using namespace std;
template<class T>
class CircularQueue
{
    int size,front,rear;
    T *q;
    public:
        CircularQueue(int size)
        {
            this->size = size;
            q = new T[size];
            front = 0;
            rear = 0;
        }
        bool isFull()
        {
            if((rear+1)%size==front)
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
                rear = (rear+1)%size;
                q[rear] = x;
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
            {
                front = (front+1)%size;
                x = q[front];
            }
            return x;
        }
};
int main()
{
    CircularQueue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(5);
    cout << q.dequeue() << endl;
    q.enqueue(6);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}