#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
    struct Node *last, *t; 
    first = (struct Node *) malloc(sizeof(struct Node));
    first->prev = first->next = NULL;
    first->data = A[0];
    last = first;
    for(int i=1; i<n; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    printf("\n");
    while(p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int findMidNode(struct Node *p)
{
    struct Node *q=p;
    while(q)
    {
        q = q->next;
        if(q)
            q = q->next;
        if(q)
            p = p->next;
    }
    return p->data;
}

int main()
{
    int A[] = {1,2,3,4,5,6};
    Create(A,6);
    Display(first);
    printf("Middle Node Element = %d",findMidNode(first));
}