#include<stdio.h>
#include<stdlib.h>
struct Node{
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
        p=p->next;
    }
    printf("\n");
}
void Reverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
void ReverseRecursively(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        ReverseRecursively(p,p->next);
        p->next = q;
    }
    else
    {
        head = q;
    }
}
int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(head);
    Reverse(head);
    Display(head);
    ReverseRecursively(NULL, head);
    Display(head);
}