#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;

void displayMatrix(float a[][n+n])
{
    for(int i=0;i<n;i++)
    {
        printf("\t");
        for(int j=0;j<n+n;j++)
        {
            if(j==n)
                printf(":\t");
            printf("%.3f\t",a[i][j]);
        }
        printf("\n");
    }
}

void convertToDiagonal(float a[][n+n])
{
    float ratio;
    //Diagonalize the matrix
    for(int i=0;i<n;i++)
    {
        if(fabs(a[i][i])<=0.00005)
        {
            printf("Error!");
            exit(0);
        }
        for(int j=0;j<n;j++)
        {
            printf("\n=>\n",i+1);
            if(i!=j)
            {
                ratio = a[j][i]/a[i][i]; 
                for(int k=0;k<n+n;k++)
                    a[j][k] = a[j][k]-(ratio*a[i][k]);
            }
            displayMatrix(a);
        }
    }
    printf("\n=>\n");
    //Convert Diagonal elements to 1
    for(int i=0;i<n;i++)
    {
        ratio = a[i][i];
        for(int j=0;j<n+n;j++)
        {
            a[i][j] = a[i][j]/ratio;
        }
    }
    displayMatrix(a);
}

int main()
{
    printf("Enter the order of matrix : ");
    scanf("%d",&n);
    float a[n][n+n];
    printf("Enter the elements of matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+n;j++)
        {
            if(j<n)
                scanf("%f",&a[i][j]);
            else if((i+n)==j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    printf("The augmented matrix is \n");
    convertToDiagonal(a);
    printf("\nHence the inverse matrix is : \n");
    for(int i=0;i<n;i++)
    {
        printf("\t");
        for(int j=n;j<n+n;j++)
        {
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }
}