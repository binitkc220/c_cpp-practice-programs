#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Array
{
    int *A;
    int size;
    int length;
};

struct Array Input(){
    int length,size;
    struct Array arr;
    printf("Enter size of array : ");
    scanf("%d",&arr.size);
    printf("Enter length of array : ");
    scanf("%d",&arr.length);
    arr.A = (int*) malloc(arr.size * sizeof(int));
    printf("Enter the elements of array : ");
    for(int i=0;i<arr.length;i++)
        scanf("%d",&arr.A[i]);
    return arr;
}

void Display(struct Array arr)
{
    printf("A -> [");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d, ",arr.A[i]);
    }
    printf("\b\b] , Size: %d , Length: %d\n",arr.size,arr.length);
}

void Set(struct Array *arr, int index, int n)
{
    if(index>=0 && index < arr->length)
        arr->A[index] = n;
}

void Append(struct Array *arr, int n)
{
    arr->A[arr->length] = n;
    arr->length++;
}

void Insert(struct Array *arr, int index, int n)
{
    if(index>=0 && index<arr->length)
    {
        for(int i=arr->length-1;i>=index;i--)
            arr->A[i+1] = arr->A[i];
        arr->A[index] = n;
        arr->length++;
    }
}

void Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
        printf("Element at index %d = %d\n",index,arr.A[index]);
}

void Delete(struct Array *arr,int index)
{
    if(index>=0 && index<arr->length)
    {
        int x = arr->A[index];
        for(int i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        printf("Deleted element at index %d = %d\n",index,x);
    }
}

void Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    printf("The maximum element in aray is %d\n",max);
}

void Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    printf("The minimum element in aray is %d\n",min);
}

void Sum_Avg(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum = sum + arr.A[i];
    float avg = (float)sum/arr.length;
    printf("The sum of elements of array is %d\n",sum);
    printf("The average of elements of array is %.2f\n",avg);
}

void Reverse(struct Array *arr)
{
    int temp;
    for(int i=0, j=arr->length-1;i<j;i++,j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    printf("The array after reversing is : \n");
    Display(*arr);
}

void LeftShift(struct Array *arr)
{
    int temp=arr->A[0];
    for(int i=0;i<arr->length-1;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
    printf("The array after left shifting the array is : \n");
    Display(*arr);
}

void RightShift(struct Array *arr)
{
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-2;i>=0;i--)
    {
        arr->A[i+1] = arr->A[i];
    }
    arr->A[0] = temp;
    printf("The array after right shifting the array is : \n");
    Display(*arr);
}

bool isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-2;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return false;
    }
    return true;
}

int LinearSearch(struct Array arr, int key)
{
    int flag=0;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
            return i;
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l=0,h=arr.length-1,mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key>arr.A[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
void SearchElement(struct Array arr, int key)
{
    int elementatIndex;
    if(isSorted(arr))
    {
        elementatIndex = BinarySearch(arr,key);
        if(elementatIndex!=-1)
            printf("Element %d found by binary search at index %d\n",key,elementatIndex);
        else
            printf("Element not Found !\n");           
    }
    else
    {
        elementatIndex = LinearSearch(arr,key);
        if(elementatIndex!=-1)
            printf("Element %d found by linear search at index %d\n",key,elementatIndex);
        else
            printf("Element not Found !\n");
    }
}

void NegativeOnLeft(struct Array *arr)
{
    int temp;
    int i=0,j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>=0)
            j--;
        if(i<j)
        {
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

struct Array * Merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->A = (int*) malloc(arr3->size*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    return arr3;
}

struct Array * Union(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->A = (int*) malloc(arr3->size*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    return arr3;
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = arr1->size;
    arr3->A = (int*) malloc(arr3->size*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else if(arr1->A[i]<arr2->A[j])
            i++;
        else
            j++;
    }
    arr3->length = k;
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = arr1->size;
    arr3->A = (int*) malloc(arr3->size*sizeof(int));
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            i++;
            j++;
        }
        else if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            j++;
    }
    arr3->length = k;
    return arr3;
}

int main()
{
    // struct Array A;
    // A = Input();
    // Display(A);
    // Set(&A,1,2);
    // Display(A);
    // Append(&A,7);
    // Display(A);
    // Insert(&A,2,3);
    // Display(A);
    // Delete(&A,4);
    // Display(A);
    // Get(A,2);
    // Min(A);
    // Max(A);
    // Sum_Avg(A);
    // printf("%d\n",isSorted(A));
    // Display(A);
    // SearchElement(A,4);
    // Reverse(&A);
    // LeftShift(&A);
    // RightShift(&A);
    // printf("%d\n",isSorted(A));
    // Display(A);
    // SearchElement(A,4);
    // NegativeOnLeft(&A);
    // Display(A);
    struct Array A,B,*C,*D,*E,*F;
    A=Input();
    B=Input();
    C = Merge(&A,&B);
    D = Union(&A,&B);
    E = Intersection(&A,&B);
    F = Difference(&A,&B);
    Display(*C);
    Display(*D);
    Display(*E);
    Display(*F);
}