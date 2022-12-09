#include<stdio.h>
#include<stdlib.h>
struct Array{
    int A[20];
    int length;
};

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

void pairSum(struct Array arr, int k)
{
    printf("The pairs in the array having sum %d are : \n",k);
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]<=k)    //optimization
        {
            for(int j=i+1;j<arr.length;j++)
            {
                if(arr.A[i]+arr.A[j]==k)
                    printf("(%d,%d)\n",arr.A[i],arr.A[j]);
            }
        }
    }
}

void pairSumHash(struct Array arr, int k)
{
    struct Array *H = (struct Array*) malloc(sizeof(struct Array));
    H->length = max(arr);
    printf("The pairs in the array having sum %d are : \n",k);
    for(int i=0;i<H->length;i++)
        H->A[i] = 0;
    for(int i=0;i<arr.length;i++)
    {
        if(H->A[k-arr.A[i]]!=0)
            printf("(%d,%d)\n",k-arr.A[i],arr.A[i]);
        H->A[arr.A[i]]++;
    }
}

int main()
{
    struct Array arr = {{6,3,8,10,16,7,5,2,9,14},10};
    pairSum(arr,10);
    pairSumHash(arr,10);
}