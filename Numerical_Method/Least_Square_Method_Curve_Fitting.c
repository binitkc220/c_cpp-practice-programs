//Least Square Method for Curve Fitting of any degree polynomial equation
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int degree;

void displayMatrix(float a[][degree+1])
{
    for(int i=0;i<degree;i++)
    {
        printf("\t");
        for(int j=0;j<degree+1;j++)
        {
            if(j==degree)
                printf(":\t");
            printf("%.3f\t",a[i][j]);
        }
        printf("\n");
    }
}

void convertToDiagonal(float a[][degree+1])
{
    float ratio;
    //Diagonalize the matrix
    for(int i=0;i<degree;i++)
    {
        if(fabs(a[i][i])<=0.0005)
        {
            printf("Error!");
            exit(0);
        }
        for(int j=0;j<degree;j++)
        {
            printf("\n=>\n");
            if(i!=j)  //operations to be performed on elements other than diagonal element
            {
                ratio = a[j][i]/a[i][i];
                for(int k=0;k<degree+1;k++)                
                    a[j][k] = a[j][k]-(ratio*a[i][k]);  //Apply Row Operations
            }
            displayMatrix(a);
        }
    }
    printf("\n=>\n\t");
    //Convert Diagonal elements to 1
    for(int i=0;i<degree;i++)
    {
        ratio = a[i][i];
        for(int j=0;j<degree+1;j++)
            a[i][j] = a[i][j]/ratio;
    }
    displayMatrix(a);
}

int main()
{
    int n,i,j,k;
    float sum;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    float x[n], y[n];
    printf("Enter the data of x\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);
    printf("Enter the data of y\n");
    for(i = 0; i < n; i++)
        scanf("%f", &y[i]);
    printf("Enter the degree of equation to fit : ");
    scanf("%d",&degree);
    degree++;
    float a[degree][degree+1];
    //Form the augmented matrix
    for(i=0;i<degree;i++)
    {
        for(j=0;j<degree+1;j++)
        {
            sum = 0;
            for(k=0;k<n;k++)
            {
                if(j!=degree)
                    sum = sum + pow(x[k],i+j);
                else
                    sum = sum + pow(x[k],i)*y[k];
            }
            a[i][j] = sum;
        }
    }
    printf("The augmented matrix is : ");
    //Diagonalise the Augmented Matrix
    convertToDiagonal(a);
    printf("\nHence, the best fit equation is ");
    for(int i=0;i<degree;i++)
        printf("%.2fx^%d +  ",a[i][degree],i);
    printf("\b\b\b ");
}