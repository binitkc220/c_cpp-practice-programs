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

struct Array * Union(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;
    arr3 = (struct Array*) malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else
        {
            if(arr1->A[i]<arr2->A[j])
                arr3->A[k++] = arr1->A[i++];
            else
                arr3->A[k++] = arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;
    return arr3;
}

struct Array * Intersetion(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {

        if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else
        {
            if(arr1->A[i]<arr2->A[j])
                i++;
            else
                j++;
        }
    }
    arr3->length = k;
    arr3->size = arr1->size;
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {

        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    arr3->length = k;
    arr3->size = arr1->size;
    return arr3;
}
int main()
{
    struct Array arr1={{3,4,5,6,10},10,5};
    struct Array arr2={{2,4,6,8,12},10,5};
    struct Array *arr3;
    struct Array *arr4;
    struct Array *arr5;
    arr3 = Union(&arr1,&arr2);
    Display(*arr3);
    arr4 = Intersetion(&arr1,&arr2);
    Display(*arr4);
    arr5 = Difference(&arr1,&arr2);
    Display(*arr5);
    return 0;
}