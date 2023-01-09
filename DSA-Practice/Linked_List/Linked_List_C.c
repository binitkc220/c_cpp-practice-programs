#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void insert(struct Node *p, int data, int pos)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(pos==0)
    {
        if(head==NULL)  //For Initial node
        {
            temp->next = NULL;
            head=temp;
        }
        else   //insert at beginning
        {
            temp->next = p;
            head=temp;
        }
    }
    else
    {
        int i=0;
        while(i<pos-1)
        {
            p=p->next;
            i++;
        }
        if(p->next == NULL)  //insert at last
        {
            p->next = temp;
            temp->next = NULL;
        }
        else   //insert at middle at any position
        {
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void delete(struct Node *p, int pos)
{
    int x,i=0;
    struct Node *temp=NULL;
    if(pos==0)  //delete beginning node
    {
        x=p->data;
        temp = p;
        head=p->next;
        free(temp);
    }
    else
    {
        while(i<pos)
        {
            temp=p;
            p=p->next;
            i++;
        }
        temp->next = p->next;
        x = p->data;
        free(p);
    }
    printf("Deleted Element = %d\n",x);
}

void search(struct Node *p, int key)
{
    int i=0;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            printf("Key found at index %d\n",i);
            return;
        }
        i++;
        p=p->next;
    }
    printf("Key not found!\n");
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    insert(head, 3,0);
    display(head);
    insert(head, 1,0);
    display(head);
    insert(head,2,1);
    display(head);
    insert(head,5,3);
    display(head);
    insert(head,4,3);
    display(head);

    delete(head,0);
    display(head);
    delete(head,3);
    display(head);

    search(head,3);
    search(head,5);

    return 0;
}