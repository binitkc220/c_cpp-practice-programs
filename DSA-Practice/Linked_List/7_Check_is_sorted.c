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
}
int checkIsSorted(struct Node *p)
{
    while(p->next!=NULL)
    {
        if(p->next->data < p->data)
        {
            return 0;
        }
        p = p->next;
    }
    return 1;
}
int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(head);
    if(checkIsSorted(head))
        printf("\nGiven Linked List is sorted !");
    else
        printf("\nGiven Linked List is not sorted !");
}