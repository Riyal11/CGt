#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>
using namespace std;

int main(){
    initwindow(1000,800,"Moving Circle");
    int i,x=100;
    rectangle(200,200,300,300);
    for(i=0;i<100;i++){
    rectangle(200,200,300,300);
    circle(200+i,200,50);
    delay(x);
    cleardevice();
    }
    for(i=0;i<100;i++){
    rectangle(200,200,300,300);
    circle(300,200+i,50);
    delay(x);
    cleardevice();
    }
    for(i=100;i>0;i--){
    rectangle(200,200,300,300);    
    circle(200+i,300,50);
    delay(x);
    cleardevice();
    }
    for(i=100;i>0;i--){
    rectangle(200,200,300,300);
    circle(200,200+i,50);
    delay(x);
    cleardevice();
    }
    delay(400);
}