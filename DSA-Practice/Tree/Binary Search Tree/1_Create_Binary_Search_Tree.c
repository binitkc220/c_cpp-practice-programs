#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *rchild, *lchild;
}*root=NULL;

void Insert(struct Node *p, int key)
{
    struct Node *t,*r;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->rchild = t->lchild = NULL;
    if(p==NULL)
    {
        root = t;
        return;
    }
    while(p!=NULL)
    {
        r = p;
        if(p->data == key)
        {
            printf("Duplicate Key!");
            return;
        }
        else if(key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if(t->data < r->data) r->lchild = t;
    else r->rchild = t;
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d\t",p->data);
        Inorder(p->rchild);
    }
}

int main()
{
    Insert(root, 50);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 20);
    Insert(root, 90);
    Insert(root, 10);
    Insert(root, 40);
    Insert(root, 100);
    printf("The data in sorted form are : \n");
    Inorder(root);
}