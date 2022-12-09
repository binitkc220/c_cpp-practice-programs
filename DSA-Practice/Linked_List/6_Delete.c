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
        p = p->next;
    }
    printf("\n");
}

void DeleteByPosition(struct Node *p, int pos)
{
    struct Node *q;
    q = NULL;
    if(pos==1)
    {
        q = head;
        printf("Deleted Element = %d\n",q->data);
        head = head->next;
        free(q);
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("Deleted Element = %d\n",p->data);
        free(p);
    }
}

void DeleteElement(struct Node *p, int key)
{
    struct Node *q;
    q = NULL;
    int i=0;
    while(p)
    {
        if(p->data == key && i==0)   //if element is at first position
        {
            q = head;
            printf("Deleted Element = %d\n",head->data);
            head = head->next;
            free(q);
            break;
        }
        else if(p->data == key)
        {
            q->next = p->next;
            printf("Deleted Element = %d\n",p->data);
            free(p);
            break;
        }
        q = p;
        p = p->next;
        i++;
    }
}
int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(head);
    DeleteByPosition(head,1);
    Display(head);
    DeleteByPosition(head,2);
    Display(head);
    DeleteElement(head,5);
    Display(head);
    DeleteElement(head,2);
    Display(head);
}