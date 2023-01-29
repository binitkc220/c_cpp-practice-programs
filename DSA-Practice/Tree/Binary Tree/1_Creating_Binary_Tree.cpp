#include "QueueCpp.h"
#include<iostream>
#include<stdio.h>
//For Queue STL ->#include<queue> and queue<Node*> q;

class Tree
{
    public:
        Node *root;
        Tree(){root=NULL;}
        void CreateTree();
        void Preorder(Node *p);
        void displayPreorder(){Preorder(root);}
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue Q;
    
    printf("Enter the root value : ");
    scanf("%d",&x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = 0;
    Q.enqueue(root);

    while(!Q.isEmpty()){
        p = Q.dequeue();
        
        printf("Enter left child if %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            Q.enqueue(t);
        }

        printf("Enter right child if %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            Q.enqueue(t);
        }

    }
}

void Tree::Preorder(Node *p){
    if(p)
    {
        printf("%d\t",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    printf("\nPreorder Traversal : \n");
    t.displayPreorder();
}