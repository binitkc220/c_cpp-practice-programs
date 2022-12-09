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

void Insert(struct Array *arr, int x)
{
    int i=arr->length-1;
    while(arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[++i] = x;
    arr->length++;
}
int main()
{
    struct Array arr = {{1,2,3,5,6,7,8,9},10,8};
    Display(arr);
    Insert(&arr,4);
    Display(arr);
}