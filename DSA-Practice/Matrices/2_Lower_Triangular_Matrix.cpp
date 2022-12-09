#include<iostream>
using namespace std;
//Row-major Formula = i*(i-1)/2+j-1 & index starting from 1 not 0
class Matrix
{
    private:
        int *A;
        int n;
    public:
        Matrix(int n)
        {
            this->n=n;
            A = new int[n];
        }
        
        void Set()
        {
            int x;
            printf("Enter the elements of matrix : ");
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    scanf("%d",&x);
                    if(i>=j)
                        A[i*(i-1)/2+j-1] = x;
                }
            }
        }

        int Get(int i, int j)
        {
            if(i>=j)
                return A[i*(i-1)/2+j-1];
            else
                return 0;
        }

        void Display()
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i>=j)
                        cout << A[i*(i-1)/2+j-1] << " ";
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
    int n;
    printf("Enter the size of matrix : ");
    scanf("%d",&n);
    class Matrix M(n);
    M.Set();
    M.Display();
    return 0;
}