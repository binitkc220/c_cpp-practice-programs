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

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL) return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node* InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p = p->rchild;
    return p;
}

struct Node* InSuc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p = p->lchild;
    return p;
}

struct Node * Delete(struct Node *p, int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
        return p;
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
    Inorder(root);
    printf("\n");
    Delete(root,50);
    Inorder(root);
    printf("\n");
    Delete(root,10);
    Inorder(root);
}