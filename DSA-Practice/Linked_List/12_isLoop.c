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

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q?q->next:q;
    } while (p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}

int main()
{
    int A[] = {2,8,10,15,20};
    struct Node *t1, *t2;
    Create(A,5);
    t1 = head->next->next;
    t2 = head->next->next->next->next;
    t2->next = t1;
    if(isLoop(head))
        printf("There is Loop !");
    else
        printf("The Linked List is Linear !");
}