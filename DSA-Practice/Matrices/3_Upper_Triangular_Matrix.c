#include<stdio.h>
#include<stdlib.h>
//Row-major formula = (i-1)*n - (i-2)(i-1)/2 + (j-i)
//Column-major formula = j*(j-1)/2 + i-1
//Index starting from 1
struct Matrix
{
    int *A;
    int n;
};
void Set(struct Matrix *m, int i, int j, int x)
{
    if(i<=j)
        m->A[j*(j-1)/2+i-1] = x;
}

int Get(struct Matrix *m, int i, int j)
{
    if(i<=j)
        return m->A[j*(j-1)/2+i-1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            if(i<=j)
                printf("%d ",m.A[j*(j-1)/2+i-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix M;
    int x;
    printf("Enter the size of matrix : ");
    scanf("%d",&M.n);
    M.A = (int*) malloc(M.n*sizeof(int));
    printf("Enter the elements of matrix : ");
    for(int i=1;i<=M.n;i++)
    {
        for(int j=1;j<=M.n;j++)
        {
            scanf("%d",&x);
            Set(&M,i,j,x);
        }
    }
    Display(M);
    free(M.A);
    return 0;
}