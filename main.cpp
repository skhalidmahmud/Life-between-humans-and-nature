#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void planetMove(int xrad, int yrad, int midx, int midy, int x[60], int y[60]){
    int i, j = 0;
    for (i = 360; i > 0; i = i - 6){
            x[j] = midx - (xrad * cos((i * 3.14) / 180));
            y[j++] = midy - (yrad * sin((i * 3.14) / 180));
    }
}

void firstIntro(int m, int n){
    int i = 0, midx, midy;
    midx = m;
    midy = n;
    int xrad[9], yrad[9], x[9][60], y[9][60];
    int pos[6], planet[6], tmp;

    planet[0] = 5;
    for (i = 1; i < 6; i++){
        planet[i] = planet[i - 1] + 1;
    }

    for(i = 0; i < 6; i++){
        pos[i] = i * 6;
    }

    xrad[0] = 60, yrad[0] = 30;

    for(i = 1; i < 9; i++){
        xrad[i] = xrad[i - 1] + 30;
        yrad[i] = yrad[i - 1] + 15;
    }

    for(i = 0; i < 6; i++){
        planetMove(xrad[i], yrad[i], midx, midy, x[i], y[i]);
    }

    while (!kbhit()){
        setcolor(WHITE);
        for(i = 0; i < 6; i++){
            ellipse(midx, midy, 0, 360, xrad[i], yrad[i]);
        }

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(midx, midy, 25);
        floodfill(midx, midy, RED);

        setcolor(15);
        settextstyle(3, HORIZ_DIR, 1);
        outtextxy(midx-35, midy, "OLD SUN");

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        pieslice(x[0][pos[0]], y[0][pos[0]], 0, 360, planet[0]);

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        pieslice(x[1][pos[1]], y[1][pos[1]], 0, 360, planet[1]);

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        pieslice(x[2][pos[2]], y[2][pos[2]], 0, 360, planet[2]);

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        pieslice(x[3][pos[3]], y[3][pos[3]], 0, 360, planet[3]);

        setcolor(BROWN);
        setfillstyle(SOLID_FILL, BROWN);
        pieslice(x[4][pos[4]], y[4][pos[4]], 0, 360, planet[4]);

        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        pieslice(x[5][pos[5]], y[5][pos[5]], 0, 360, planet[5]);

        for(i = 0; i < 6; i++){
            if(pos[i] <= 0)
                pos[i] = 59;
            else
                pos[i] = pos[i] - 1;
        }

        delay(500);
        cleardevice();
    }
    closegraph();
}
void secondIntro(){
    // printf("This is just second intro!\n");
}
void mainProcess(){
    while(!kbhit()){
        // printf("This is mian project [cpde] part.");
    }
}

int main(){

    initwindow(1080,720,"The Khalid's BGI");
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    firstIntro(midx, midy);
    //secondIntro();
    //mainProcess();

    getch();
    closegraph();
}
