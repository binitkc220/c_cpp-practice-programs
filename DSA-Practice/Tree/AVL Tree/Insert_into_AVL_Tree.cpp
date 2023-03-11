#include<iostream>
#include<cstdio>
using namespace std;

class Node {
    public:
        int data, height;
        Node *lchild, *rchild;
};

class AVL {
    Node *root;
    public:
        AVL(){root=NULL;}

        int nodeHeight(Node *p);
        int balanceFactor(Node *p);
        Node *LLRotation(Node *p);
        Node *RRRotation(Node *p);
        Node *LRRotation(Node *p);
        Node *RLRotation(Node *p);
        Node* insertRec(Node*p, int data);
        void insertData(int data){root = insertRec(root,data);}
        void Insert();
        void Preorder(Node *p);
        void displayPreorder(){Preorder(root);cout<<endl;}

        int max(int a, int b){return a>b?a:b;}
};

int AVL::nodeHeight(Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->lchild ? p->rchild->height : 0;
    return hl>hr ? hl: hr;
}

int AVL::balanceFactor(Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->lchild ? p->rchild->height : 0;
    return hl-hr;
}


Node* AVL::insertRec(Node*p, int key) {
    Node *t;
    if(p==NULL) {
        t = new Node;
        t->data = key;
        t->height = 0;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = insertRec(p->lchild, key);
    else
        p->rchild = insertRec(p->rchild, key);

    p->height = nodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1)
        return RLRotation(p);

    return p;
}

void AVL::Insert() {
    int key;
    while(true)
    {
        printf("Enter the value to insert : ");
        scanf("%d",&key);
        if(key==-1) break;
        root = insertRec(root, key);
    }
}

void AVL::Preorder(Node *p)
{
    if(p) {
        printf("%d,h=%d\t",p->data,p->height);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{
    AVL avl;
    avl.Insert();
    avl.displayPreorder();
}