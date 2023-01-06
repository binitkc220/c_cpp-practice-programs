//Higher the number, higher the priority
#include<iostream>
using namespace std;
template<class T>
class PriorityQueue
{
    int size,n;
    T *q;
    public:
        PriorityQueue(int size)
        {
            this->size = size;
            n=0;
            q = new T[size];
        }
        void enqueue(T x)
        {
            if(n==size-1)
            {
                cout << "Queue is Full !" << endl;
                return;
            }
            int i=n-1;
            while(i>=0 && x<q[i])
            {
                q[i+1] = q[i];
                i--;
            }
            q[i+1] = x;
            n++;
        }
        T dequeue()
        {
            if(n==0)
            {
                cout << "Queue is Empty !" << endl;
                return 0;
            }
            return q[--n];
        }
        void display()
        {
            for(int i=0;i<n;i++)
                cout << q[i] << "\t";
            cout << endl;
        }
        ~PriorityQueue()
        {
            delete[] q;
        }
};
int main()
{
    PriorityQueue<int> p1(5);
    p1.enqueue(2);
    p1.enqueue(1);
    p1.enqueue(5);
    p1.display();
    p1.enqueue(4);
    p1.display();
    cout << p1.dequeue() << endl;
    cout << p1.dequeue() << endl;
    p1.display();
}