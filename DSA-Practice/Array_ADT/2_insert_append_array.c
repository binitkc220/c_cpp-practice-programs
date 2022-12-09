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

void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
    {
        for(int i=arr->length; i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{2,4,6,8,10},10,5};
    Display(arr);
    Append(&arr,12);
    Display(arr);
    Insert(&arr,2,5);
    Display(arr);
    return 0;
}
