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

void LeftShift(struct Array *arr)
{
    int temp = arr->A[0];
    for(int i=0;i<arr->length-1;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}

void RightShift(struct Array *arr)
{
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-1;i>0;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}

int main(){
    struct Array arr = {{2,4,6,8,10},10,5};
    Display(arr);
    LeftShift(&arr);
    Display(arr);
    RightShift(&arr);
    Display(arr);
    return 0;
}