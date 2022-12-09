#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void Create(int A[], int n)
{
    struct Node *t,*last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;
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
        p = p->next;
    }
    printf("\n");
}

void insertIntoSorted(struct Node *p, int key)
{
    struct Node *t,*q;
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    q = NULL;
    if(head==NULL)
        head=t;
    else
    {
        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if(p==head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    struct Node *L1;
    int A[] = {3,5,8,12};
    Create(A,4);
    Display(head);
    insertIntoSorted(head,2);
    Display(head);
    insertIntoSorted(head,6);
    Display(head);
    insertIntoSorted(head,15);
    Display(head);
}