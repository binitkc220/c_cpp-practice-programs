//Line using Brehensen's Line Algorithm
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void BLA(int x1,int y1, int x2, int y2)
{
	int x,y,dx,dy,lx,ly,p,step,i=0;
	cleardevice();
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1,y=y1;
	lx=(x2>x1)?1:-1;
	ly=(y2>y1)?1:-1;
	p=2*dy-dx;
	step=(x2>x1)?x2:x1;
	while(i<step)
	{
		putpixel(x,y,WHITE);
		if(p<=0)
		{
			x=x+lx;
			y=y;
			p=p+2*dy;
		}
		else
		{
			x=x+lx;
			y=y+ly;
			p=p+2*dy-2*dx;
		}
		i++;
	}
}

int main()
{
	int gm, gd=DETECT;
	int x1,y1,x2,y2;

	//Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);
	
	printf("Enter the starting point : ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the ending point : ");
	scanf("%d%d",&x2,&y2);
	
	BLA(x1,y1,x2,y2);

	getch();
	closegraph();
	return 0;
}
