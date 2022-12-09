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

int Length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int key, int index)
{
    struct Node *t;
    
    if(index < 0 || index > Length(p))  //Check for out of range
        return;
    
    if(index==0)  //Inserting at beginning
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = key;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else   //Insert at given index
    {
        for(int i=0;i<index-1;i++)
            p = p->next;
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = key;
        t->next = p->next;
        t->prev = p;
        if(p->next)  //if index is not last element of list
            p->next->prev = t;
        p->next = t;
    }
}

int main()
{
    int A[] = {2,3,4,5,7};
    Create(A,5);
    Display(first);
    Insert(first,1,0);
    Display(first);
    Insert(first,6,5);
    Display(first);
    Insert(first,8,7);
    Display(first);
}