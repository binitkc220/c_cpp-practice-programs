#include<iostream>
#include<stdio.h>

class Node
{
    public:
        int data;
        Node *lchild, *rchild;
};

class BST
{
    Node *root;
    public:
        BST(){root = NULL;}
        void CreateBST();
        void Insert(int key);
        void Inorder(Node *p);
        void displayInorder(){Inorder(root);}
};

void BST::Insert(int key)
{
    Node *t,*r;
    Node *p=root;
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if(root==NULL)
    {
        root = t;
        return;
    }
    while(p!=NULL)
    {
        r = p;
        if(p->data==key)
        {
            printf("Duplicate Key!\n");
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

void BST::CreateBST()
{
    int x;
    while(1)
    {
        printf("Enter the data : ");
        scanf("%d",&x);
        if(x==-1)
            return;
        else
            Insert(x);
    }
}

void BST::Inorder(Node *p)
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
    BST b;
    b.CreateBST();
    b.displayInorder();
    return 0;   
}