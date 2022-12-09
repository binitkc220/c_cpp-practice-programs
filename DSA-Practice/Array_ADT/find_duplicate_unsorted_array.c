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

void findDuplicate(struct Array *arr)
{
    int count;
    for(int i=0;i<arr->length-1;i++)
    {
        if(arr->A[i]!=-1)
        {
            count =1;
            for(int j=i+1;j<arr->length;j++)
            {
                if(arr->A[i]==arr->A[j])
                {
                    count++;
                    arr->A[j] = -1;
                }
            }
            if(count>1)
                printf("%d is appearing %d times.\n",arr->A[i],count);
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
    printf("\nHash Array : \n");
    Display(*H);
    for(int i=1;i<H->length;i++)
    {
        if(H->A[i]>1)
            printf("%d is appearing %d times.\n",i,H->A[i]);
    }
}

int main()
{
    struct Array arr1={{8,3,6,4,6,5,6,8,2,7},10};
    struct Array arr2={{8,3,6,4,6,5,6,8,2,7},10};
    findDuplicate(&arr1);
    findDuplicateHash(arr2);
    return 0;
}