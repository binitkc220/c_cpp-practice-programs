#include<stdio.h>
#include<stdlib.h>

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
        p = p->next;
    }
}

void displayRecursively(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        display(p->next);
    }
}

void create(int A[], int n)
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
int main()
{
    int A[] = {1,2,3,4,5};
    create(A,5);
    display(head);
    printf("\n");
    displayRecursively(head);
    return 0;
}