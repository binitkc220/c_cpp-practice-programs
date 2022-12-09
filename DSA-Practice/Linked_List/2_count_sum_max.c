#include<stdio.h>
#include<stdlib.h>
#define MIN_INT -32768

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void display(struct Node *p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int countRecursively(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return countRecursively(p->next) + 1;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=0)
    {
        s=s+p->data;
        p=p->next;
    }
    return s;
}

int sumRecursively(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return sumRecursively(p->next) + p->data;
}

int max(struct Node *p)
{
    int m = MIN_INT;
    while(p!=NULL)
    {
        if(p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int maxRecursively(struct Node *p)
{
    int x=0;
    if(p==0)
        return MIN_INT;
    x = maxRecursively(p->next);
    return (x>p->data)?x:p->data; 
}

void create(int A[], int n)
{
    struct Node *t,*last;
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(int i=1;i<n;i++)  
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int main()
{
    int A[] = {1,2,3,4,5};
    create(A,5);
    display(head);

    printf("\nUsing Normal function : \n");
    printf("No. of Elements = %d\n",count(head));
    printf("Sum = %d\n",sum(head));
    printf("Maximum Element = %d\n",max(head));
    
    printf("\nUsing Recursive function : \n");
    printf("No. of Elements = %d\n",countRecursively(head));
    printf("Sum = %d\n",sumRecursively(head));
    printf("Maximum Element = %d\n",maxRecursively(head));
    
    return 0;
}