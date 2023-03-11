#include<iostream>
#include<cstdio>

class Node
{
    public:
        int data;
        Node *rchild, *lchild;
};

class BinarySearchTree
{
    Node *root;
    public:
        BinarySearchTree(){root=NULL;}
        void Insert(int key);
        void Create();
        void Inorder(Node *p);
        void displayInorder(){Inorder(root);printf("\n");}
        int Height(Node *p);
        Node* inorderPrecessor(Node *p);
        Node* inorderSuccessor(Node *p);
        Node* deleteKey(Node *p, int key);
        void Delete(int key){deleteKey(root,key);}
};

void BinarySearchTree::Insert(int key)
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
        if(p->data == key)
        {
            printf("Duplcate Key!\n");
            return;
        }
        else if(key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if(key < r->data) r->lchild = t;
    else r->rchild = t; 
}

void BinarySearchTree::Create()
{
    int x;
    while(true)
    {
        printf("Enter the element : ");
        scanf("%d",&x);
        if(x!=-1)
            Insert(x);
        else
            break;
    }
}

void BinarySearchTree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d\t",p->data);
        Inorder(p->rchild);
    }
}

int BinarySearchTree::Height(Node *p)
{
    int x,y;
    if(p==NULL) return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

Node* BinarySearchTree::inorderPrecessor(Node *p)
{
    while(p && p->rchild!=NULL)
        p = p->rchild;
    return p;
}

Node* BinarySearchTree::inorderSuccessor(Node *p)
{
    while(p && p->lchild!=NULL)
        p = p->lchild;
    return p;
}

Node* BinarySearchTree::deleteKey(Node *p, int key)
{                        
    Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root = NULL;
        delete p;
        return NULL;
    }
    if(key < p->data)
        p->lchild = deleteKey(p->lchild,key);
    else if(key > p->data)
        p->rchild = deleteKey(p->rchild,key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = inorderPrecessor(p->lchild);
            p->data = q->data;
            p->lchild = deleteKey(p->lchild,q->data);
        }
        else
        {
            q = inorderPrecessor(p->rchild);
            p->data = q->data;
            p->rchild = deleteKey(p->rchild,q->data);
        }
        return p;
    }
}

int main()
{
    BinarySearchTree BST;
    BST.Create();
    BST.displayInorder();
    BST.Delete(30);
    BST.displayInorder();
}
