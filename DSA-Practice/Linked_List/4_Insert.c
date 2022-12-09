#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void Create(int A[], int n)
{
    struct Node *t,*last,*head;
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
    printf("\n");
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

void Insert(struct Node *p, int pos, int key)
{
    struct Node *t;
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
    if(head==NULL)
    {
        t->next = NULL;
        head = t;
    }
    else
    {
        if(pos==0)
        {
            t->next = head;
            head = t;
        }
        else
        {
            for(int i=1;i<pos-1;i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
}

int main()
{
    Insert(head,1,2);
    Display(head);
    Insert(head,2,3);
    Display(head);
    Insert(head,3,4);
    Display(head);
    Insert(head,0,1);
    Display(head);
    Insert(head,5,5);
    Display(head);
}