#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

int abs(int n) {
    return (n > 0 ? n : (-n));
}

int Round(float a) {
    return (int)(a + 0.5);
}

void DDA(int X0, int Y0, int X1, int Y1) {
    int i, dx, dy, steps;
    float Xinc, Yinc, X, Y;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setbkcolor(WHITE);

    cleardevice();

    dx = X1 - X0;
    dy = Y1 - Y0;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    Xinc = dx / (float)steps;
    Yinc = dy / (float)steps;

    X = X0;
    Y = Y0;

    for (i = 0; i <= steps; i++) {
	putpixel(Round(X), Round(Y), RED);
	X += Xinc;
	Y += Yinc;
    }

    getch();
    closegraph();
}

int main() {
    int X0 = 2, Y0 = 2, X1 = 100, Y1 = 120;

    DDA(X0, Y0, X1, Y1);
    return 0;
}
