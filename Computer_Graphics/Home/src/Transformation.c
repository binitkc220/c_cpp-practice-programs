#include<stdio.h>
#include<graphics.h>
#include<math.h>

void triangle(int x[3], int y[3])
{
    for(int i=0;i<3;i++)
    {
        line(x[i],y[i],x[(i+1)%3],y[(i+1)%3]);
    }
}

void translate(int x[3], int y[3], int tx, int ty)
{
    int x_t[3],y_t[3];
    for(int i=0;i<3;i++)
    {
        x_t[i] = x[i]+tx;
        y_t[i] = y[i]+ty;
    }
    triangle(x_t,y_t);
}

void scale(int x[3], int y[3], int sx, int sy)
{
    int x_s[3],y_s[3];
    for(int i=0;i<3;i++)
    {
        x_s[i] = x[i]*sx;
        y_s[i] = y[i]*sy;
    }
    triangle(x_s,y_s);
}

void rotate(int x[3], int y[3], float angle, int xk, int yk)   //xk and yk are arbitary pivot position from that point to rotate
{
    int x_r[3],y_r[3];
    angle = angle*3.14/180.0;
    for(int i=0;i<3;i++)
    {
        x_r[i] = xk+ceil((float)(x[i]-xk)*cos(angle)-(float)(y[i]-yk)*sin(angle));
        y_r[i] = yk+ceil((float)(x[i]-xk)*sin(angle)+(float)(y[i]-yk)*cos(angle));
    }
    triangle(x_r,y_r);
}

int main()
{
    int gm, gd=DETECT;
    int x[]={200,150,270};
    int y[]={50,150,150};
    //Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char gdata[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,gdata);

    triangle(x,y);
    translate(x,y,100,100);
    scale(x,y,2,2);
    rotate(x,y,45.0,150,150);

    getch();
    closegraph();
    return 0;
}