#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

void lineBres(int x0, int y0, int x1, int y1){
    int dx, dy, x, y;
    int p; // decision parameter

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x = x0;
    y = y0;

    dx = x1 - x0;
    dy = y1 - y0;

    p = 2*dy - dx; // initial decision parameter

    setbkcolor(WHITE);
    cleardevice();

    while(x <= x1){
	putpixel(x,y, RED);
	x++;
	if(p<0){
	    p = p+2*dy;
	}
	else
	{
	    p = p + 2*dy - 2*dx;
	}
	y++;
    delay(20);
    }

    getch();
    closegraph();
}

int main(){
    // int X0 = 2, Y0 = 2, X1 = 200, Y1 = 240;

    printf("Bresenham's line drawing algorithm\n");
	printf("Enter co-ordinates of first point: ");
	scanf("%d%d", &X0, &Y0);
 
	printf("Enter co-ordinates of second point: ");
	scanf("%d%d", &X1, &Y1);
	

    lineBres(X0, Y0, X1, Y1);
    return 0;
}