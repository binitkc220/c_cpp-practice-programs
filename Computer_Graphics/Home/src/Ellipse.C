//Mid-Point Ellipse Algorithm
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void plot(int xCenter, int yCenter, int x, int y)
{
    putpixel(xCenter+x,yCenter+y,WHITE);
    putpixel(xCenter-x,yCenter+y,WHITE);
    putpixel(xCenter+x,yCenter-y,WHITE);
    putpixel(xCenter-x,yCenter-y,WHITE);
}

void midPointEllipse(int xCenter, int yCenter, int a, int b)
{
    int p,x=0,y=b,px=0,py=2*a*a*y;

    //Plot first point
    plot(xCenter,yCenter,x,y);

    //Region 1
    p=ceil(b*b-(a*a+b)+(0.25*a*a));
    while(px<py)
    {
        x++;
        px=px+2*b*b;
        if(p<0)
            p=p+b*b+px;
        else
        {
            y--;
            py=py-2*a*a;
            p=p+b*b+px-py;
        }
        plot(xCenter,yCenter,x,y);
    }

    //Region 2
    p = ceil(b*b*(x+0.25)*(x+0.25)+a*a*(y-1)*(y-1)-a*a*b*b);
    while(y>0)
    {
        y--;
        py = py-2*a*a;
        if(p>0)
            p=p+a*a-py;
        else
        {
            x++;
            px=px+2*b*b;
            p=p+a*a-py+px;
        }
        plot(xCenter,yCenter,x,y);
    }
}

int main()
{
	int gm, gd=DETECT;
	int a,b,xCenter,yCenter;

	//Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);

    printf("Enter the coordinates of center : ");
    scanf("%d%d",&xCenter,&yCenter);
    printf("Enter x-radius and y-raduis : ");
    scanf("%d%d",&a,&b);

    midPointEllipse(xCenter,yCenter,a,b);

    getch();
    return 0;
}