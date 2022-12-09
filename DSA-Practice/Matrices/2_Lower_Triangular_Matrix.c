#include<stdio.h>
#include<stdlib.h>
//Row-major Formula = i*(i-1)/2+j-1 & index starting from 1 not 0
struct Matrix
{
    int *A;
    int n;
};
void Set(struct Matrix *m, int i, int j, int x)
{
    if(i>=j)
        m->A[i*(i-1)/2+j-1] = x;
}

int Get(struct Matrix *m, int i, int j)
{
    if(i>=j)
        return m->A[i*(i-1)/2+j-1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            if(i>=j)
                printf("%d ",m.A[i*(i-1)/2+j-1]);
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