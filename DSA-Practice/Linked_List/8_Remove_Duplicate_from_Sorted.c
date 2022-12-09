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
void RemoveDuplicate(struct Node *p)
{
    struct Node *q=NULL;
    while(p->next!=NULL)
    {
        if(p->next->data == p->data)
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
        }
        else
            p = p->next;
    }
}
int main()
{
    int A[] = {1,2,2,2,3,4,4,5,5,5};
    Create(A,10);
    Display(head);
    RemoveDuplicate(head);
    Display(head);
}