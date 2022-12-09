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

int Delete(struct Array *arr, int index)
{
    int x=0;
    if(index>=0 && index<arr->length)
    {
        x = arr->A[index];
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    struct Array arr={{2,4,6,8,10},10,5};
    Display(arr);
    printf("%d\n",Delete(&arr,0));
    Display(arr);
    return 0;
}
