#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL;

void Create(int A[], int n)
{
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Create2(int A[], int n)
{
    struct Node *t,*last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for(int i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

void Concat(struct Node *p, struct Node *q)
{
    while(p->next!=NULL)
        p = p->next;
    p->next = q;
    second = NULL;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    int B[] = {6,7,8,9,10};
    Create2(B,5);
    printf("First Linked List : \n");
    Display(first);
    printf("\n\nSecond Linked List : \n");
    Display(second);
    Concat(first, second);
    printf("\n\nAfter Concatenating : \n");
    Display(first);
}