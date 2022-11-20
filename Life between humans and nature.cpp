#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void firstIntro(int m, int n)
{
    // printf("This is just second intro!\n");
}
void secondIntro()
{
}
void mainProcess()
{
    while (!kbhit())
    {
    }
}

int main()
{

    initwindow(1080, 720, "The Khalid's BGI");
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    // firstIntro(midx, midy);
    // secondIntro();
    // mainProcess();

    getch();
    closegraph();
}