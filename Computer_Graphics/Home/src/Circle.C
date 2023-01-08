//Circle using Mid-Point Algorithm
#include<stdio.h>
#include<graphics.h>

void put(int x0,int y0, int x, int y)
{
    putpixel(x0+x,y0+y,15);
    putpixel(x0-x,y0+y,15);
    putpixel(x0+x,y0-y,15);
    putpixel(x0-x,y0-y,15);
    putpixel(x0+y,y0+x,15);
    putpixel(x0-y,y0+x,15);
    putpixel(x0+y,y0-x,15);
    putpixel(x0-y,y0-x,15);
}

void midPointCircle(int x0, int y0, int r)
{
    int x,y,p;
    x=0,y=r;
    p=1-r;
    put(x0,y0,x,y);
    while(x<y)
    {
        x++;
        if(p<0)
            p=p+2*x+1;
        else
        {
            y--;
            p=p+2*(x-y)+1;
        }
        put(x0,y0,x,y);
    }
}

int main()
{
	int gm, gd=DETECT;
	int r,x0,y0;
    
    //Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);

    printf("Enter the center coordinates of circle : ");
    scanf("%d%d",&x0,&y0);
    printf("Enter the radius of circle : ");
    scanf("%d",&r);
    
    midPointCircle(x0,y0,r);
   
    getch();
    closegraph();
    return 0;
}