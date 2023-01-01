#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
    //return y+sin(x+y);
    return (x+pow(y,2));
}
int main()
{
    float x,y,h,approx_x,slope;
    printf("Enter initial x0 and y0 : ");
    scanf("%f%f",&x,&y);
    printf("Enter h : ");
    scanf("%f",&h);
    printf("Approx x ? ");
    scanf("%f",&approx_x);
    printf("x\ty\tSlope\ty(new)\n");
    while(x<approx_x)
    {
        printf("%.2f\t%.4f\t",x,y);
        slope = f(x,y);
        x = x+h;
        y = y+h*slope;
        printf("%.4f\ty(%.1f)=%.4f\n",slope,x,y);
    }
    return 0;
}