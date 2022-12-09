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

int Delete(struct Node *p, int pos)
{
    struct Node *t;
    int x=-1;

    if(pos < 1 || pos > Length(p))
        return -1;
    if(pos==1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(first);
    printf("Deleted element at position 1 - %d\n",Delete(first,1));
    Display(first);
    printf("Deleted element at position 3 - %d\n",Delete(first,3));
    Display(first);
}