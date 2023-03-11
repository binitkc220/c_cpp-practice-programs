#include<stdio.h>
#include<math.h>
int n;

float max(float x[n])
{
    float maxm=0;
    for(int i=0;i<n;i++)
    {
        if(fabs(x[i]) > fabs(maxm))
            maxm = x[i];
    }
    return maxm;
}

int isEqual(float a[n], float b[n])
{
    float diff[n];
    for(int i=0;i<n;i++)
        diff[i] = fabs(fabs(a[i]) - fabs(b[i]));
    return (max(diff) < 0.00001)?1:0;
}

int main()
{
    int i,j;
    printf("Enter the order of matrix : ");
    scanf("%d",&n);
    float A[n][n], X[n], Z[n], sum, lambda;
    printf("Enter the elements of matrix : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%f",&A[i][j]);
    }
    printf("Enter the elements of initial guess vector : \n");
    for(i=0;i<n;i++)
        scanf("%f",&X[i]);
    while(1)
    {
        printf("\n=>\n");
        for(i=0;i<n;i++)
        {
            sum = 0;
            for(j=0;j<n;j++)
                sum += A[i][j] * X[j];
            Z[i] = sum;
        }
        lambda = max(Z);
        printf("Eigen Value = %.4f\n",lambda);
        printf("Eigen Vector : \n");
        for(i=0;i<n;i++)
        {
            Z[i] /= lambda;
            printf("%.4f\n",Z[i]);
        }
        if(isEqual(X,Z))
            break;
        for(i=0;i<n;i++)
            X[i] = Z[i];
    }
    return 0;
}