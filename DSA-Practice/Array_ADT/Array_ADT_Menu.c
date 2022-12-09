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
    printf("\n\tA -> [");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d, ",arr.A[i]);
    }
    printf("\b\b] , Size: %d , Length: %d\n\n",arr.size,arr.length);
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
        printf("\n\n\tElement at index %d = %d\n",index,arr.A[index]);
}

void Delete(struct Array *arr,int index)
{
    if(index>=0 && index<arr->length)
    {
        int x = arr->A[index];
        for(int i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        printf("\n\n\tDeleted element at index %d = %d\n",index,x);
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
    printf("\n\n\tThe maximum element in aray is %d\n\n\n",max);
}

void Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    printf("\n\n\tThe minimum element in aray is %d\n\n\n",min);
}

void Sum_Avg(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum = sum + arr.A[i];
    float avg = (float)sum/arr.length;
    printf("\n\n\tThe sum of elements of array is %d\n",sum);
    printf("\tThe average of elements of array is %.2f\n\n\n",avg);
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
    printf("\n\n\tThe array after reversing is : \n");
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
    printf("\n\n\tThe array after left shifting the array is : \n");
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
    printf("\n\n\tThe array after right shifting the array is : \n");
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
            printf("\n\n\tElement %d found by binary search at index %d\n\n\n",key,elementatIndex);
        else
            printf("\n\n\tElement not Found !\n\n\n");           
    }
    else
    {
        elementatIndex = LinearSearch(arr,key);
        if(elementatIndex!=-1)
            printf("\n\n\tElement %d found by linear search at index %d\n\n\n",key,elementatIndex);
        else
            printf("\n\n\tElement not Found !\n\n\n");
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
    struct Array A,B,*merged,*unioned,*intersectioned,*differenced;
    int ch,ch1,ch2,index,element,key;
    top:
    system("clear");
    printf("\t** Menu **\n");
    printf("\t==========\n\n");
    printf("1. Normal Operations on Array");
    printf("\n2. Set/Merge Operations on Array");
    printf("\n3. Exit");
    printf("\n\n\t Enter your choice : ");
    scanf("%d",&ch);
    while(ch>=1 && ch<=3)
    {
        switch(ch)
        {
            case 1:
                system("clear");
                if(A.A==NULL)
                {
                    printf("Enter Array Details : \n\n");
                    A = Input();
                }
                system("clear");
                Display(A);
                printf("\n1. Set");
                printf("\n2. Append");
                printf("\n3. Insert");
                printf("\n4. Get");
                printf("\n5. Delete");
                printf("\n6. Min");
                printf("\n7. Max");
                printf("\n8. Sum");
                printf("\n9. Reverse");
                printf("\n10. Left Shift");
                printf("\n11. Right Shift");
                printf("\n12. isSorted");
                printf("\n13. Search");
                printf("\n14. Negative on Left");
                printf("\n15. Go to main menu");
                printf("\n\n\tEnter your choice of operation : ");
                scanf("%d",&ch1);
                switch(ch1)
                {
                    case 1:
                        system("clear");
                        Display(A);
                        printf("Enter index : ");
                        scanf("%d",&index);
                        printf("Enter element to set : ");
                        scanf("%d",&element);
                        Set(&A,index,element);
                        printf("\n\nThe new array is : ");
                        Display(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 2:
                        system("clear");
                        Display(A);
                        printf("Enter element to append : ");
                        scanf("%d",&element);
                        Append(&A,element);
                        printf("\n\nThe new array is : ");
                        Display(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 3:
                        system("clear");
                        Display(A);
                        printf("Enter index : ");
                        scanf("%d",&index);
                        printf("Enter element to insert : ");
                        scanf("%d",&element);
                        Insert(&A,index,element);
                        printf("\n\nThe new array is : ");
                        Display(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 4:
                        system("clear");
                        Display(A);
                        printf("Enter index : ");
                        scanf("%d",&index);
                        Get(A,index);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 5:
                        system("clear");
                        Display(A);
                        printf("Enter index : ");
                        scanf("%d",&index);
                        Delete(&A,index);
                        printf("\n\nThe new array is : ");
                        Display(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 6:
                        system("clear");
                        Display(A);
                        Min(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 7:
                        system("clear");
                        Display(A);
                        Max(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 8:
                        system("clear");
                        Display(A);
                        Sum_Avg(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 9:
                        system("clear");
                        Display(A);
                        Reverse(&A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 10:
                        system("clear");
                        Display(A);
                        LeftShift(&A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 11:
                        system("clear");
                        Display(A);
                        RightShift(&A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 12:
                        system("clear");
                        Display(A);
                        if(isSorted(A))
                            printf("\n\n\tYes, The array is Sorted ! \n\n\n");
                        else
                            printf("\n\n\tNo, The array is not Sorted ! \n\n\n");
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 13:
                        system("clear");
                        Display(A);
                        printf("Enter element to search : ");
                        scanf("%d",&element);
                        SearchElement(A,element);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 14:
                        system("clear");
                        Display(A);
                        NegativeOnLeft(&A);
                        printf("\n\nThe new array is : ");
                        Display(A);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 15:
                        free(A.A);
                        A.A=NULL;
                        goto top;
                    default:
                        system("read -n1 -r -p \"Enter valid choice...\" key");
                        break;
                }
                break;
            case 2:
                system("clear");
                if(A.A==NULL && B.A==NULL)
                {
                    printf("Enter Array Details of Array1 : \n\n");
                    A = Input();
                    printf("\n\nEnter Array Details of Array2 : \n\n");
                    B = Input();
                }
                system("clear");
                printf("Array1:");
                Display(A);
                printf("Array2:");
                Display(B);
                printf("\n1. Merge two arrays");
                printf("\n2. Unon");
                printf("\n3. Intersection");
                printf("\n4. Difference");
                printf("\n5. Go back to main menu");
                printf("\n\n\tEnter your choice of operation : ");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:
                        system("clear");
                        printf("Array1:");
                        Display(A);
                        printf("Array2:");
                        Display(B);
                        merged = Merge(&A,&B);
                        printf("\n\tThe merged array is :");
                        Display(*merged);
                        free(merged);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 2:
                        system("clear");
                        printf("Array1:");
                        Display(A);
                        printf("Array2:");
                        Display(B);
                        unioned = Union(&A,&B);
                        printf("\n\tThe array after union is :");
                        Display(*unioned);
                        free(unioned);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 3:
                        system("clear");
                        printf("Array1:");
                        Display(A);
                        printf("Array2:");
                        Display(B);
                        intersectioned = Intersection(&A,&B);
                        printf("\n\tThe array after intersection is :");
                        Display(*intersectioned);
                        free(intersectioned);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 4:
                        system("clear");
                        printf("Array1:");
                        Display(A);
                        printf("Array2:");
                        Display(B);
                        differenced = Difference(&A,&B);
                        printf("\n\tThe array after intersection is :");
                        Display(*differenced);
                        free(differenced);
                        system("read -n1 -r -p \"Press any key to continue...\" key");
                        break;
                    case 5:
                        free(A.A);
                        free(B.A);
                        A.A=NULL;
                        B.A=NULL;
                        goto top;
                    default:
                        system("read -n1 -r -p \"Enter valid choice...\" key");
                        break;
                }
                break;
            case 3:
                exit(0);
        }
    }
}