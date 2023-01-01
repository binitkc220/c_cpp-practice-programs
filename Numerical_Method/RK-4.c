#include<stdio.h>
#include<math.h>
float f(float x, float y)
{
    //return y+sin(x+y);
    return (pow(x,2)+pow(y,2));
}
int main()
{
    float x,y,h,approx_x,i,k1,k2,k3,k4,k;
    i=x;
    printf("Enter initial x0 and y0 : ");
    scanf("%f%f",&x,&y);
    printf("Enter h : ");
    scanf("%f",&h);
    printf("Approx x ? ");
    scanf("%f",&approx_x);
    printf(" x\t  y\n");
    while(x<=approx_x)
    {
        printf("%.1f\t%.4f\t\ty(%.1f)=%.4f\n",x,y,x,y);
        k1 = h*f(x,y);
        k2 = h*f(x+h/2,y+k1/2);
        k3 = h*f(x+h/2,y+k2/2);
        k4 = h*f(x+h,y+k3);
        k = (k1+2*k2+2*k3+k4)/6;
        x = x+h;
        y = y+k;
        i++;
    }
    return 0;
}