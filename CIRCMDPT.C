#include <stdio.h>
#include <graphics.h>

void midPointCircleDraw(int x_centre, int y_centre, int r) {
    int x = r, y = 0;
    int P = 1 - r;

    while (x >= y) {
	// Plot the points in all eight octants
	putpixel(x + x_centre, y + y_centre, RED);
	putpixel(x + x_centre, -y + y_centre, RED);
	putpixel(-x + x_centre, y + y_centre, RED);
	putpixel(-x + x_centre, -y + y_centre, RED);
	putpixel(y + x_centre, x + y_centre, RED);
	putpixel(-y + x_centre, x + y_centre, RED);
	putpixel(y + x_centre, -x + y_centre, RED);
	putpixel(-y + x_centre, -x + y_centre, RED);

	y++;

	if (P <= 0) {
	    P = P + 2 * y + 1;
	} else {
	    x--;
	    P = P + 2 * y - 2 * x + 1;
	}
    }
}

int main() {
    int x_centre = 300, y_centre = 210 , radius = 100;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Initialize graphics mode

      // Radius of the circle

    setbkcolor(WHITE);

    cleardevice();

    midPointCircleDraw(x_centre, y_centre, radius);

    getch();
    closegraph(); // Close the graphics mode

    return 0;
}
