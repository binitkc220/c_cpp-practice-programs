#include<stdio.h>
#include<graphics.h>

#define bool int
#define true 1
#define false 0

const int inside = 0;
const int left = 1;
const int right = 2;
const int bottom = 4;
const int top = 8;

int compute_code(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
    int code = inside;
    if(x < xmin)
        code |= left;
    else if(x > xmax)
        code |= right;
    if(y < ymin)
        code |= bottom;
    else if(y > ymax)
        code |= top;
    return code;
}

void cohen_sutherland_clip(float x1, float y1, float x2, float y2, float xmin, float ymin, float xmax, float ymax)
{
    int code, code1, code2;
    float x,y;
    code1 = compute_code(x1,y1,xmin,ymin,xmax,ymax);
    code2 = compute_code(x2,y2,xmin,ymin,xmax,ymax);
    bool accept = false;
    while(true) {
        if(code1==0 && code2==0) {
            accept = true;
            break;
        }
        else {
            x=y=0;
            code = (code1!=0)?code1:code2;
            if(code & top) {
                x = x1 + (x2-x1)*(ymax-y1)/(y2-y1);
                y = ymax;
            }
            else if(code & bottom) {
                x = x1 + (x2-x1)*(ymin-y1)/(y2-y1);
                y = ymin;
            }
            else if(code & right) {
                y = y1 + (y2-y1)*(xmax-x1)/(x2-x1);
                x = xmax;
            }
            else if(code & left) {
                y = y1 + (y2-y1)*(xmin-x1)/(x2-x1);
                x = xmin;
            }
            if(code == code1) {
                x1 = x;
                y1 = y;
                code1 = compute_code(x1,y1,xmin,ymin,xmax,ymax);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = compute_code(x2,y2,xmin,ymin,xmax,ymax);
            }
        }
    }
    rectangle(xmin,ymin,xmax,ymax);
    if(accept)
        line(x1,y1,x2,y2);
}

int main()
{
    int x1=10,y1=10,x2=240,y2=350,xmin=100,ymin=100,xmax=250,ymax=250;
    int gm=DETECT, gd=DETECT;
    //Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);

    rectangle(xmin,ymin,xmax,ymax);
    line(x1,y1,x2,y2);

    getch();
    cleardevice();

    cohen_sutherland_clip(x1,y1,x2,y2,xmin,ymin,xmax,ymax);
    getch();

    closegraph();
    return 0;
}