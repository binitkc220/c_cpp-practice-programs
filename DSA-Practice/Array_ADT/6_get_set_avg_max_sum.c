#include<stdio.h>
struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("[");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d, ",arr.A[i]);
    }
    printf("\b\b]\n");
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int n, int index)
{
    if(index>=0 && index<arr->length)
        arr->A[index] = n;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum=sum+arr.A[i];
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

int main()
{
    struct Array arr = {{2,5,6,8,10},10,5};
    printf("%d\n",Get(arr,1));
    Display(arr);
    Set(&arr,4,1);
    Display(arr);
    printf("The maximum element is %d\n",Max(arr));
    printf("The minimum element is %d\n",Min(arr));
    printf("The sum of elements of array is %d\n",Sum(arr));
    printf("The average of elements of array is %.2f\n",Avg(arr));
    return 0;
}