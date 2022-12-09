#include<stdio.h>
#include<stdlib.h>
struct Array{
    int A[20];
    int length;
};

void pairSum(struct Array arr, int k)
{
    int i=0,j=arr.length-1;
    printf("The pairs in the array having sum %d are : \n",k);
    while(i<j)
    {
        if((arr.A[i]+arr.A[j])>k)
            j--;
        else if((arr.A[i]+arr.A[j])<k)
            i++;
        else
        {
            printf("(%d,%d)\n",arr.A[i],arr.A[j]);
            i++,j--;
        }
    }
}

int main()
{
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14},10};
    pairSum(arr,10);
}