#include<stdio.h>
#include<stdbool.h>
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

bool isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return false;
    }
    return true;
}

int main()
{
    struct Array arr = {{2,4,6,18,10},10,5};
    printf("%d",isSorted(arr));
    return 0;
}