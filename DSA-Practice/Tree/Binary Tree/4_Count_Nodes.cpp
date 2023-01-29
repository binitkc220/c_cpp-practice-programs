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
        int AllNodes(Node *p);
        int LeafNodes(Node *p);
        int Nodesdeg2(Node *p);
        int Nodesdeg12(Node *p);
        int Nodesdeg1(Node *p);
        int countAllNodes(){return AllNodes(root);}
        int countLeafNodes(){return LeafNodes(root);}
        int countNodesdeg2(){return Nodesdeg2(root);}
        int countNodesdeg12(){return Nodesdeg12(root);}
        int countNodesdeg1(){return Nodesdeg1(root);}
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

int Tree::AllNodes(Node *p){
    if(p==NULL)
        return 0;
    return AllNodes(p->lchild)+AllNodes(p->rchild)+1;
}

int Tree::LeafNodes(Node *p){
    int x,y;
    if(p)
    {
        x = LeafNodes(p->lchild);
        y = LeafNodes(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int Tree::Nodesdeg2(Node *p){
    int x,y;
    if(p)
    {
        x = Nodesdeg2(p->lchild);
        y = Nodesdeg2(p->rchild);
        if(p->lchild && p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int Tree::Nodesdeg12(Node *p){
    int x,y;
    if(p)
    {
        x = Nodesdeg12(p->lchild);
        y = Nodesdeg12(p->rchild);
        if(p->lchild || p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int Tree::Nodesdeg1(Node *p){
    int x,y;
    if(p)
    {
        x = Nodesdeg1(p->lchild);
        y = Nodesdeg1(p->rchild);
        if(p->lchild!=NULL ^ p->rchild!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int main()
{
    Tree t;
    t.CreateTree();
    printf("\nPreorder Traversal : \n");
    t.displayPreorder();
    printf("No. of Nodes are %d\n",t.countAllNodes());
    printf("No. of leaf Nodes are %d\n",t.countLeafNodes());
    printf("No. of Nodes with degree 2 are %d\n",t.countNodesdeg2());
    printf("No. of Nodes with degree 1 or 2 are %d\n",t.countNodesdeg12());
    printf("No. of Nodes with degree 1 are %d\n",t.countNodesdeg1());
}