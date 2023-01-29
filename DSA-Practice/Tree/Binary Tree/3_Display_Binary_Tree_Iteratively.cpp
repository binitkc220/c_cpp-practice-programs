#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Tree
{
    public:
        Node *root;
        Tree(){root=NULL;}
        void CreateTree();
        void Inorder();
        void Preorder();
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    std::queue<Node*> Q;
    
    printf("Enter the root value : ");
    scanf("%d",&x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = 0;
    Q.push(root);

    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        
        printf("Enter left child if %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            Q.push(t);
        }

        printf("Enter right child if %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            Q.push(t);
        }

    }
}

void Tree::Inorder(){
    Node *p=root;
    std::stack<Node*> st;
    while(p!=NULL || !st.empty())
    {
        if(p!=NULL)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            printf("%d\t",p->data);
            p = p->rchild;
        }
    }
}

void Tree::Preorder(){
    Node *p=root;
    std::stack<Node*> st;
    while(p!=NULL || !st.empty())
    {
        if(p!=NULL)
        {
            printf("%d\t",p->data);
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    printf("\nInorder Traversal : \n");
    t.Inorder();
    printf("\nPreorder Traversal : \n");
    t.Preorder();
}