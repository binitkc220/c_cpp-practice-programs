#include<iostream>
using namespace std;
template<class T>
class Array
{
    private:
        T *A;
        int size, length;
    public:
        void input()
        {
            cout << "Enter the size of array : ";
            cin >> size;
            cout << "Enter the length of array : ";
            cin >> length;
            A = new T[size];
            printf("Enter the elements of array : ");
            for(int i=0;i<length;i++)
                cin >> A[i];
        }

        void display()
        {
            printf("[");
            for(int i=0;i<length;i++)
            {
                printf("%d, ",A[i]);
            }
            printf("\b\b] , Size = %d , Length = %d\n",size,length);
        }

        void set(int index, int element)
        {
            if(index>=0 && index<length)
            {
                A[index] = element;
            }
        }

        void append(int element)
        {
            A[length] = element;
            length++;
        }

        void insert(int index, int element)
        {
            for(int i=length;i>=index;i--)
                A[i] = A[i-1];
            A[index] = element;
            length++;
        }

        void get(int index)
        {
            if(index>=0 && index<length)
            {
                printf("Element at index %d = %d\n",index,A[index]);
            }
        }

        void pop(int index)
        {
            if(index>=0 && index<length)
            {
                int x = A[index];
                for(int i=index;i<length-1;i++)
                    A[i] = A[i+1];
                length--;
                printf("Deleted element at index %d = %d\n",index,x);
            }
        }

        void max()
        {
            int max = A[0];
            for(int i=0;i<length;i++)
            {
                if(A[i]>max)
                    max = A[i];
            }
            printf("The maximum element in aray is %d\n\n\n",max);
        }

        void min()
        {
            int min = A[0];
            for(int i=0;i<length;i++)
            {
                if(A[i]<min)
                    min = A[i];
            }
            printf("The minimum element in aray is %d\n\n\n",min);
        }

        void sum_avg()
        {
            int sum=0;
            for(int i=0;i<length;i++)
                sum = sum + A[i];
            float avg = float(sum)/length;
            printf("The sum of elements of array is %d\n",sum);
            printf("The average of elements of array is %.2f\n\n\n",avg);
        } 
        void Reverse()
        {
            int temp;
            for(int i=0,j=length-1;i<j;i++,j--)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            printf("The array after reversing is : \n");
            display();
        } 
        void LeftShift()
        {
            int temp=A[0];
            for(int i=0;i<length-1;i++)
            {
                A[i] = A[i+1];
            }
            A[length-1] = temp;
            printf("The array after left shifting the array is : \n");
            display();
        }

        void RightShift()
        {
            int temp = A[length-1];
            for(int i=length-2;i>=0;i--)
            {
                A[i+1] = A[i];
            }
            A[0] = temp;
            printf("The array after right shifting the array is : \n");
            display();
        }

        bool isSorted()
        {
            for(int i=0;i<length-2;i++)
            {
                if(A[i]>A[i+1])
                    return false;
            }
            return true;
        }

        int LinearSearch(int key)
        {
            int flag=0;
            for(int i=0;i<length;i++)
            {
                if(A[i]==key)
                    return i;
            }
            return -1;
        }

        int BinarySearch(int key)
        {
            int l=0,h=length-1,mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(key==A[mid])
                    return mid;
                else if(key>A[mid])
                    l=mid+1;
                else
                    h=mid-1;
            }
            return -1;
        }

        void SearchElement(int key)
        {
            int elementatIndex;
            if(isSorted())
            {
                elementatIndex = BinarySearch(key);
                if(elementatIndex!=-1)
                    printf("Element %d found by binary search at index %d\n",key,elementatIndex);
                else
                    printf("Element not Found !\n");           
            }
            else
            {
                elementatIndex = LinearSearch(key);
                if(elementatIndex!=-1)
                    printf("Element %d found by linear search at index %d\n",key,elementatIndex);
                else
                    printf("Element not Found !\n");
            }
        }

        void NegativeOnLeft()
        {
            int temp;
            int i=0,j=length-1;
            while(i<j)
            {
                while(A[i]<0)
                    i++;
                while(A[j]>=0)
                    j--;
                if(i<j)
                {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }

        Array *Merge(Array arr)
        {
            Array *arr2 = new Array(length + arr.length);
            arr2.size = size + arr.size;
            arr2.A = new T[arr2.size];
            int i=0,j=0,k=0;
            while(i<length && j<arr.length)
            {
                if(A[i]<arr.A[j])
                    arr2.A[k++] = A[i++];
                else
                    arr2.A[k++] = arr.A[j++];
            }
            for(;i<length;i++)
                arr2.A[k++] = A[i];
            for(;j<arr.length;j++)
                arr2.A[k++] = arr.A[j];
            arr2.length = k;
            return arr2;
        }

        ~Array()
        {
            delete []A;
        }
};

int main()
{
    Array<int> A;
    A.input();
    A.display();
    A.set(1,2);
    A.display();
    A.append(7);
    A.display();
    A.insert(2,3);
    A.display();
    A.pop(4);
    A.display();
    A.get(2);
    A.min();
    A.max();
    A.sum_avg();
    printf("%d\n",A.isSorted());
    A.display();
    A.SearchElement(4);
    A.Reverse();
    A.LeftShift();
    A.RightShift();
    printf("%d\n",A.isSorted());
    A.display();
    A.SearchElement(4);
    A.NegativeOnLeft();
    A.display();
}
