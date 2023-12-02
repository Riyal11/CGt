#include <graphics.h>
#include <conio.h>
#include <math.h>

#define MAX_SIDES 100

int gd = DETECT, gm;
int n, xs[MAX_SIDES], ys[MAX_SIDES], i, ty, tx, s;
float sx, sy, angle;

void draw();
void translate();
void scale();
void rotate();

int mround(double x) {
    return (int)(x + 0.5);
}

void main() {
    printf("Enter number of sides of polygon (up to %d): ", MAX_SIDES);
    scanf("%d", &n);

    if (n > MAX_SIDES || n < 3) {
        printf("Invalid number of sides. Exiting...\n");
        return;
    }

    printf("Enter the co-ordinates: x,y for each vertex ");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &xs[i], &ys[i]);
    }

    printf("Enter the operation you want to perform: \n"
           "1. Translate\n2. Scale\n3. Rotate\n");
    scanf("%d", &s);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    switch (s) {
    case 1:
        translate();
        break;
    case 2:
        scale();
        break;
    case 3:
        rotate();
        break;
    }

    getch();
    closegraph();
}

void draw() {
    for (i = 0; i < n; i++) {
        line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
    }
}

void translate() {
    printf("Enter translation values tx and ty: ");
    scanf("%d %d", &tx, &ty);
    cleardevice();

    setbkcolor(WHITE);
    setcolor(RED);
    draw();

    for (i = 0; i < n; i++) {
        xs[i] = xs[i] + tx;
        ys[i] = ys[i] + ty;
    }

    
    setcolor(BLUE);
    draw();
}

void scale() {
    printf("Enter scaling factors sx and sy: ");
    scanf("%f %f", &sx, &sy);
    cleardevice();

    setbkcolor(WHITE);
    setcolor(RED);
    draw();

    for (i = 0; i < n; i++) {
        xs[i] = mround(xs[i] * sx);
        ys[i] = mround(ys[i] * sy);
    }

    
    setcolor(BLUE);
    draw();
}

void rotate() {
    float radian = angle * (3.1416 / 180);
    int cx = 0, cy = 0; // Assuming rotation about the origin

    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle);
    cleardevice();

    setbkcolor(WHITE);
    setcolor(BLACK);
    draw();

    for (i = 0; i < n; i++) {
        int x = xs[i];
        int y = ys[i];

        xs[i] = mround((x - cx) * cos(radian) - (y - cy) * sin(radian) + cx);
        ys[i] = mround((x - cx) * sin(radian) + (y - cy) * cos(radian) + cy);
    }

    setcolor(BLUE);
    draw();
}
