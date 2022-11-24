#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <time.h>

void customCcircle(int x, int y,int rad, int outlnColor, int fillColor){
    setfillstyle(SOLID_FILL,fillColor);
    circle(x,y,rad);
    floodfill(x+1,y+1,outlnColor);
}

void customStar4Edge(int x, int y, int e){
	int m = e/4;
    setfillstyle(1, 15);

	line(x-m, y, x, y+e);
	line(x, y+e, x+m, y);
	line(x+m, y, x, y-e);
	line(x, y-e, x-m, y);

	floodfill(x, y, WHITE);

	line(x, y+m, x+e, y);
	line(x+e, y, x, y-m);
	line(x, y-m, x-e, y);
	line(x-e, y, x, y+m);

	floodfill(x+m+1, y, WHITE);
	floodfill(x-m-1, y, WHITE);
}

void ShowPressKey(int midx, int midy){
    settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(10, HORIZ_DIR, 12);
    outtextxy(midx+250, midy+250, "For next seen, press any key[FROM KEYBOARD]");
}

void showTextInGraphicsWindowFullScr(int x, int y, char showText[50]){
    int midx = x;
    int midy = y;

	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(0, HORIZ_DIR, 18);
    outtextxy(midx, midy, showText);

    delay(3000);

    settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(0, HORIZ_DIR, 18);
    outtextxy(midx, midy, showText);

    ShowPressKey(midx, midy);

    getch();
    cleardevice();
}

void showTextInGraphicsWindow(int x, int y, char showText[50], int textSize, int textColor, int textStyle){
    setcolor(textColor);
    settextstyle(textStyle, HORIZ_DIR, 1);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(0, HORIZ_DIR, textSize);
    outtextxy(x, y, showText);
}

void planetMove(int xrad, int yrad, int midx, int midy, int x[60], int y[60]){
    int i, j = 0;
    for (i = 360; i > 0; i = i - 6){
        x[j] = midx - (xrad * cos((i * 3.14) / 180));
        y[j++] = midy - (yrad * sin((i * 3.14) / 180));
    }
}

void firstIntro(int m, int n){
    time_t secondsStart, secondsEnd;
    secondsStart = time(NULL);

    int i = 0, midx, midy;
    midx = m;
    midy = n;

    showTextInGraphicsWindowFullScr(midx, midy, "Eternity ago...");
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

        showTextInGraphicsWindow(midx, midy+5, "SUN", 0, 15, 3);

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

        secondsEnd = time(NULL);

        if((secondsEnd - secondsStart) >= 20){
            ShowPressKey(midx, midy);
        }
        setcolor(WHITE);
        customStar4Edge(midx-220, midy+160, 25);
        customStar4Edge(midx+190, midy+10, 5);
        customStar4Edge(midx+200, midy+120, 10);
        customStar4Edge(midx+100, midy-150, 4);
        customStar4Edge(midx-100, midy-220, 4);
        customStar4Edge(midx+150, midy-180, 4);
        customStar4Edge(midx-180, midy-250, 4);
        customStar4Edge(midx-280, midy-20, 4);
        customStar4Edge(midx-420, midy+15, 4);
        customStar4Edge(midx+420, midy-315, 4);

        delay(400);
        cleardevice();
    }
    cleardevice();
}
void secondIntro(int midx, int midy){
    showTextInGraphicsWindowFullScr(midx, midy, "After infinity time...");

    int start_angle = 90+45, end_angle = 90-45, x_rad = 170, y_rad = 50;

    //1st still img...
    customCcircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCcircle(midx+35, midy+20, 4, 15, 15);
    customCcircle(midx-135,midy+80, 4, 15, 15);
    customCcircle(midx+150,midy+100, 10, 15, 15);

    customStar4Edge(midx-120, midy-120, 15);
    showTextInGraphicsWindow(midx+180, midy+40, "The OLD EARTH", 12, 15, 3);
    ShowPressKey(midx, midy);
    getch();
    cleardevice();

    //2nd still img...
    customCcircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCcircle(midx+35, midy+20, 4, 15, 15);
    customCcircle(midx-135,midy+80, 4, 15, 15);
    customCcircle(midx+150,midy+100, 10, 15, 15);

    customCcircle(midx+450,midy-250, 4, 15, 15);

    customStar4Edge(midx-120, midy-120, 15);
    showTextInGraphicsWindow(midx+180, midy+40, "The OLD EARTH", 12, 15, 3);
    showTextInGraphicsWindow(midx+450, midy-220, "Unknown OBJECT", 12, 15, 3);
    ShowPressKey(midx, midy);
    getch();
    cleardevice();

    //3nd still img...
    customCcircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCcircle(midx+35, midy+20, 4, 15, 15);
    customCcircle(midx-135,midy+80, 4, 15, 15);
    customCcircle(midx+150,midy+100, 10, 15, 15);

    customCcircle(midx+100,midy-205, 4, 15, 15);

    ellipse(midx+100, 755, 90, 120, 200, 600);
    line(midx+450,midy-250, midx+100,midy-205);

    customStar4Edge(midx-120, midy-120, 15);
    showTextInGraphicsWindow(midx+180, midy+40, "The OLD EARTH", 12, 15, 3);
    showTextInGraphicsWindow(midx+150, midy-180, "Unknown OBJ.", 12, 15, 3);
    showTextInGraphicsWindow(midx, midy-200, "SPEED UP!!", 12, 15, 3);
    ShowPressKey(midx, midy);
    getch();
    cleardevice();

    //4th and last still img...
    customCcircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCcircle(midx+35, midy+20, 4, 15, 15);
    customCcircle(midx-135,midy+80, 4, 15, 15);
    customCcircle(midx+150,midy+100, 10, 15, 15);

    customStar4Edge(midx-120, midy-120, 15);
    ShowPressKey(midx, midy);

    ellipse(midx+100, 755, 90, 120, 200, 600);
    line(midx+450,midy-250, midx+100,midy-205);

    customCcircle(midx, midy, 125, 15, 7);

    setcolor(4);
    customCcircle(midx, midy-125, 4, 4, 4);

    setcolor(7);
    line(midx, midy-130, midx, midy-138);
    line(midx+1, midy-130, midx+1, midy-138);
    line(midx-1, midy-130, midx-1, midy-138);

    setcolor(7);
    setfillstyle(SOLID_FILL,7);
    ellipse(midx, midy-140, 0, 360, 12, 5);
    floodfill(midx-5, midy-140,7);

    showTextInGraphicsWindow(midx+180, midy+40, "The OLD EARTH", 12, 15, 3);
    showTextInGraphicsWindow(midx-20, midy-150, "BUMM!!!", 12, 15, 3);
    getch();
    cleardevice();

    //Intro 2 done with white color screen...
    setcolor(WHITE);
    floodfill(midx, midy, 15);
    ShowPressKey(midx, midy);
    getch();
    cleardevice();
}
void mainProcess(int midx, int midy){
    showTextInGraphicsWindowFullScr(midx, midy, "A long, long time ago...");

    while(!kbhit()){

    }
}

int main(){

    initwindow(1080,720,"The Khalid's BGI");
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    firstIntro(midx, midy);       //This is done!! :)
    secondIntro(midx, midy);      //This is done!! :)
    mainProcess(midx, midy);

    getch();
    closegraph();
}
