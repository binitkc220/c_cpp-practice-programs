#include<stdio.h>
#include<stdlib.h>
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

void Reverse(struct Array *arr)
{
    int *B;
    B = (int*)malloc(arr->length*sizeof(int));
    for(int i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(int i=0;i<arr->length;i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse1(struct Array *arr)
{
    int temp;
    for(int i=0,j=arr->length-1;i<j;i++,j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main()
{
    struct Array arr = {{2,4,6,8,10},10,5};
    Display(arr);
    Reverse(&arr);
    Display(arr);
    Reverse1(&arr);
    Display(arr);
}