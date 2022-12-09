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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BringtLeft(struct Array *arr)
{
    int i=0,j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>=0)
            j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{-6,-8,7,6,-9,10,5,-3,-2,12},10,10};
    Display(arr);
    BringtLeft(&arr);
    Display(arr);
}