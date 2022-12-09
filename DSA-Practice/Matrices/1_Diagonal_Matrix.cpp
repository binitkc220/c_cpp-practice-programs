#include<iostream>
using namespace std;
class Matrix
{
    private:
        int *A;
        int n;
    public:
        Matrix(int n)
        {
            this->n = n;
            A = new int[n];
        }
        void set(int i, int j, int x)
        {
            if(i==j)
                A[i-1] = x;
        }
        int get(int i, int j)
        {
            if(i==j)
                return A[i-1];
            else
                return 0;
        }
        void display()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                        cout << A[i] << " ";
                    else
                        cout << "0 ";
                }
                cout << endl;
            }
        }
        ~Matrix()
        {
            delete []A;
        }
};
int main()
{
    Matrix M(4);
    M.set(1,1,5);
    M.set(2,2,9);
    M.set(3,3,4);
    M.set(4,4,2);
    M.display();
    return 0;
}