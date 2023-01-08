#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
	int gm, gd=DETECT;
	int i;

	//Turbo C
    //initgraph(&gm,&gd,"C:\\TC\\BGI");
    
    //VS Code
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);
	
	printf("%dx%d",getmaxx(),getmaxy());
	for(i=0;i<getmaxx()-180;i++)
	{
	cleardevice();
	circle(90+i,60,60);
	circle(65+i,40,8);
	circle(115+i,40,8);
	line(90+i,50,90+i,70);
	line(60+i,90,120+i,90);
	line(90+i,120,90+i,300);
	line(90+i,150,35+i,200);
	line(90+i,150,145+i,200);
	line(90+i,300,35+i,350);
	line(90+i,300,145+i,350);
	line(5+i,350,175+i,350);
	line(5+i,350,0+i,330);

	line(175+i,350,180+i,330);
	circle(45+i,360,10);
	circle(135+i,360,10);
	delay(10);
	}
	getch();
	closegraph();
	return 0;
}