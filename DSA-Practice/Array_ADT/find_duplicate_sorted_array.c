#include<stdio.h>
#include<stdlib.h>
struct Array{
    int A[20];
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

int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

void findDuplicate(struct Array arr)
{
    int j=0;
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]==arr.A[i+1])
        {
            j=i+1;
            while(arr.A[i]==arr.A[j])
                j++;
            printf("%d is apparing %d times.\n",arr.A[i],j-i);
            i=j-1;
        }
    }
}

void findDuplicateHash(struct Array arr)
{
    struct Array *H = (struct Array *) malloc(sizeof(struct Array));
    H->length = max(arr)+1;
    for(int i=0;i<H->length;i++)
        H->A[i] = 0;
    for(int i=0;i<arr.length;i++)
        H->A[arr.A[i]]++;
    for(int i=1;i<H->length;i++)
    {
        if(H->A[i]>1)
            printf("%d is appearing %d times.\n",i,H->A[i]);
    }
}

int main()
{
    struct Array arr1 = {{1,2,3,3,4,5,5,5,6,7},10};
    struct Array arr2 = {{3,6,8,8,10,12,15,15,15,18},10};
    Display(arr1);
    findDuplicate(arr1);
    Display(arr2);
    findDuplicateHash(arr2);
    return 0;
}