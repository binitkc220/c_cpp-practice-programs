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

void ReverseDisplay(struct Node *p)
{
    while(p->next!=NULL)
        p = p->next;
    printf("\n");
    while(p)
    {
        printf("%d\t",p->data);
        p = p->prev;
    }
    printf("\n");
}

int Len(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(first);
    printf("The length of linked list is %d",Len(first));
    ReverseDisplay(first);
}