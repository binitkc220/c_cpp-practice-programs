//Line using Digital Differentail Analyzer Algorithm
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

void DDA(float x1, float y1, float x2, float y2)
{
	float dx,dy,xi,yi,x,y,step;
	int k=0;
	cleardevice();
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	step = (dx>dy || dx==dy)?dx:dy;
	xi = dx/step;
	yi = dy/step;
	x = x1;
	y=y1;
	while(k<step)
	{
		putpixel(x,y,WHITE);
		x=x+xi;
		y=y+yi;
		k++;
	}
}

int main()
{
	int gm, gd=DETECT;
	float x1,y1,x2,y2;

	//Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);
	
	printf("Enter the starting coordinates : ");
	scanf("%f%f",&x1,&y1);
	printf("Enter the ending coordinates : ");
	scanf("%f%f",&x2,&y2);
	
	DDA(x1,y1,x2,y2);

	getch();
	closegraph();
	return 0;
}