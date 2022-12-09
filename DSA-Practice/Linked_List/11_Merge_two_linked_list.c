#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *merged=NULL;

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

void Merge(struct Node *p, struct Node *q)
{
    merged = (struct Node *) malloc(sizeof(struct Node));
    struct Node *last;
    last = (struct Node *) malloc(sizeof(struct Node));
    if(p->data < q->data)
    {
        merged = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        merged = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p!=NULL)
        last->next = p;
    else
        last->next = q;
}

int main()
{
    int A[] = {2,8,10,15};
    Create(A,4);
    int B[] = {4,7,12,14};
    Create2(B,4);
    printf("First Linked List : \n");
    Display(first);
    printf("\n\nSecond Linked List : \n");
    Display(second);
    Merge(first, second);
    printf("\n\nAfter Merging : \n");
    Display(merged);
}