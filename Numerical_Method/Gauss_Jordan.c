#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;

void displayMatrix(float a[][n+1])
{
    for(int i=0;i<n;i++)
    {
        printf("\t");
        for(int j=0;j<n+1;j++)
        {
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }
}

void convertToDiagonal(float a[][n+1])
{
    float ratio;
    //Diagonalize the matrix
    for(int i=0;i<n;i++)
    {
        if(fabs(a[i][i])<=0.0005)
        {
            printf("Error!");
            exit(0);
        }
        for(int j=0;j<n;j++)
        {
            printf("\n=>\n");
            if(i!=j)  //operations to be performed on elements other than diagonal element
            {
                ratio = a[j][i]/a[i][i];
                for(int k=0;k<n+1;k++)                
                    a[j][k] = a[j][k]-(ratio*a[i][k]);  //Apply Row Operations
            }
            displayMatrix(a);
        }
    }
    printf("\n=>\n\t");
    //Convert Diagonal elements to 1
    for(int i=0;i<n;i++)
    {
        ratio = a[i][i];
        for(int j=0;j<n+1;j++)
            a[i][j] = a[i][j]/ratio;
    }
    displayMatrix(a);
}
int main()
{
    printf("Enter the no. of unknowns : ");
    scanf("%d",&n);
    float a[n][n+1];
    //Input the elements of Augmented Matrix
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficients of eqation %d:\n",i+1);
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    //Diagonalise the Augmented Matrix
    convertToDiagonal(a);
    printf("\nHence, the required solutions are ");
    for(int i=0;i<n;i++)
        printf("x%d=%.2f  ",i+1,a[i][n]);
}