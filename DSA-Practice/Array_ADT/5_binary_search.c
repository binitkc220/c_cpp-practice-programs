#include<stdio.h>
struct Array{
    int A[16];
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

int BinSearch(struct Array arr,int key)
{
    int l=0,mid;
    int h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key>arr.A[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
    int mid=0;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h,key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43},16,15};
    Display(arr);
    printf("Key found at index %d\n",BinSearch(arr,15));
    printf("Key found at index %d\n",RBinSearch(arr.A,0,arr.length-1,39));
}