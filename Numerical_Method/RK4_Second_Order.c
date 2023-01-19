//Second Order RK-4
#include<stdio.h>
float f(float x, float y, float z)
{
    return z;
}
float g(float x, float y, float z)
{
    return (6*x+3*y-2*z);
}
int main()
{
    float x,y,z,x_final,k1,k2,k3,k4,l1,l2,l3,l4,k,l,h;
    printf("Enter initial x0,y0,z0 : ");
    scanf("%f%f%f",&x,&y,&z);
    printf("Approximate x ? ");
    scanf("%f",&x_final);
    printf("Enter h : ");
    scanf("%f",&h);
    printf("x\ty\tz\n");
    printf("%.2f\t%.4f\t%.4f\n",x,y,z);
    while(x<x_final)
    {
        k1=h*f(x,y,z);
        l1=h*g(x,y,z);
        k2=h*f(x+h/2,y+k1/2,z+l1/2);
        l2=h*g(x+h/2,y+k1/2,z+l1/2);
        k3=h*f(x+h/2,y+k2/2,z+l2/2);
        l3=h*g(x+h/2,y+k2/2,z+l2/2);
        k4=h*f(x+h,y+k3,z+l3);
        l4=h*g(x+h,y+k3,z+l3);
        k=(k1+2*k2+2*k3+k4)/6;
        l=(l1+2*l2+2*l3+l4)/6;
        y=y+k;
        x=x+h;
        z=z+l;
        printf("%.2f\t%.4f\t%.4f\n",x,y,z);
    }
    printf("\n\ty=%.4f",y);
}