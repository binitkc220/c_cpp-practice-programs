#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[20];
    int length;
};
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}
struct Array * hashMissing(struct Array arr)
{
    struct Array *hash = (struct Array *) malloc(sizeof(struct Array));
    hash->length = max(arr) + 1;
    int i=0,j=0;
    for(i=0;i<hash->length;i++)
        hash->A[i] = 0;
    for(i=0;i<arr.length;i++)
        hash->A[arr.A[i]] = 1;
    return hash;
}
int main()
{
    struct Array arr = {{3,7,4,9,12,6,1,11,2,10},10};
    struct Array *missing = hashMissing(arr);
    printf("The missing elements are : ");
    for(int i=1;i<missing->length;i++)
    {
        if(missing->A[i] == 0)
            printf("%d, ",i);      
    }
    printf("\b\b");
}