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

int findMissing(struct Array arr)
{
    int diff = arr.A[0]-0;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i != diff)
            return i+diff;
    }
    return -1;
}
struct Array * findMultipleMissing(struct Array arr)
{
    struct Array *missing = (struct Array *) malloc(sizeof(struct Array));
    int diff = arr.A[0] - 0;
    int j=0;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i] - i != diff)
        {
            while(diff<arr.A[i]-i)
            {
                missing->A[j++] = i+diff;
                diff++;
            }
        }
    }
    missing->length = j;
    return missing;
}
int main()
{
    struct Array arr1={{6,7,8,9,10,11,12,13,15,16,17},11};
    struct Array arr2={{5,6,9,10,11,13},6};
    
    int missing = findMissing(arr1);
    if(missing == -1)
        printf("No missing element found!\n");
    else
        printf("The missing element is %d\n",missing);

    struct Array *multipleMissing = findMultipleMissing(arr2);
    printf("The missing elements are : \n");
    Display(*multipleMissing);
    return 0;
}