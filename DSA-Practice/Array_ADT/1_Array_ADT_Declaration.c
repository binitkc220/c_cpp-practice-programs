#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};

void Input(struct Array arr)
{
    printf("Enter the elements of array : \n");
    for(int i=0;i<arr.length;i++)
        scanf("%d",&arr.A[i]);
}

void Display(struct Array arr)
{
    printf("The elements of array are : \n");
    for(int i=0;i<arr.length;i++)
        printf("%d\t",arr.A[i]);
}
int main()
{
    struct Array arr;
    int i;
    printf("Enter the size of array : ");
    scanf("%d",&arr.size);
    printf("Enter the number of elements : ");
    scanf("%d",&arr.length);
    arr.A = (int*)malloc(arr.size*sizeof(int));
    Input(arr);
    Display(arr);
    free(arr.A);
    arr.A=NULL;
    return 0;
}