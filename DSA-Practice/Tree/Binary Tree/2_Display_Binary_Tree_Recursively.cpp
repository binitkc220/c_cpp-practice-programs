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
        void Inorder(Node *p);
        void displayInorder(){Inorder(root);}
        void Preorder(Node *p);
        void displayPreorder(){Preorder(root);}
        void Postorder(Node *p);
        void displayPostorder(){Postorder(root);}
        void displayLevelorder();
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

void Tree::Inorder(Node *p){
    if(p)
    {
        Inorder(p->lchild);
        printf("%d\t",p->data);
        Inorder(p->rchild);
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

void Tree::Postorder(Node *p){
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d\t",p->data);
    }
}

void Tree::displayLevelorder(){
    Queue Q;
    Node *p;
    Q.enqueue(root);
    printf("%d\t",root->data);
    while(!Q.isEmpty()){
        p = Q.dequeue();
        if(p->lchild)
        {
            printf("%d\t",p->lchild->data);
            Q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            printf("%d\t",p->rchild->data);
            Q.enqueue(p->rchild);
        }
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    printf("\nInorder Traversal : \n");
    t.displayInorder();
    printf("\nPreorder Traversal : \n");
    t.displayPreorder();
    printf("\nPostorder Traversal : \n");
    t.displayPostorder();
    printf("\nLevelorder Traversal : \n");
    t.displayLevelorder();
}