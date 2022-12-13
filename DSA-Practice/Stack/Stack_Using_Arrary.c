#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void Create(struct Stack *st)
{
    printf("Enter the size of stack : ");
    scanf("%d",&st->size);
    st->top = -1;
    st->s = (int*) malloc(st->size*sizeof(int));
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}

void stackTop(struct Stack st)
{
    if(!isEmpty(st))
        printf("\nThe top element of stack is %d\n",st.s[st.top]);
    else
        printf("\nStack is Empty\n");
}

void Display(struct Stack st)
{
    printf("\nThe stack is : \n");
    int index = st.top;
    for(int i=index;i>=0;i--)
        printf("%d\n",st.s[i]);
    printf("\n");
}

void Push(struct Stack *st, int data)
{
    if(isFull(*st))
    {
        printf("Stack Overflow!\n");
        return;
    }
    else
    {
        st->top++;
        st->s[st->top] = data;
    }
}

void Pop(struct Stack *st)
{
    int x = -1;
    if(isEmpty(*st))
    {
        printf("Stack Underflow!\n");
        return;
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    printf("The popped element is %d\n",x);
}

void Peek(struct Stack st, int index)
{
    int x=-1;
    if(st.top-index+1<0 || index<=0)
    {
        printf("\nInvalid index!\n");
        return;
    }
    x = st.s[st.top-index+1];
    printf("\nElement at index %d is %d\n",index,x);
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,10);   
    Push(&st,20);   
    Push(&st,30);  
    Push(&st,40);  
    Push(&st,50);    
    Display(st);
    Peek(st,1);
    Peek(st,3);
    Peek(st,5);
    stackTop(st);
    Pop(&st);
    Display(st);
    stackTop(st);
    Pop(&st);
    stackTop(st);
    Display(st);
}