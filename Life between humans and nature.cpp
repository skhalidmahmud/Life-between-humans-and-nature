#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <time.h>

int DELAY = 100;
int m_cloud = 300, m_sun = 0, s_count = 1, m = 10;

void singleMan(int x, int y, int legDis){
	circle(x, y - 90 + m, 10);   //head
	line(x, y - 80 + m, x, y - 30 + 10);    //body line
	line(x, y - 70 + m, x + 10, y - 60 + m);    //hand
	line(x, y -70 + m, x - 10, y - 60 + m);  //hand
	line(x + 10, y - 60 + m, x + 20, y - 70 + m);  //arm
	line(x - 10, y - 60 + m, x - 20, y - 70 + m);  //arm
	line(x, y - 30 + 10, x + legDis, y); //leg
	line(x, y - 30 + 10, x - legDis, y); //leg
}

void RIP(int x, int y){
	line(x, y, x, y - 25);
	line(x - 40, y, x - 40, y - 25);
	line(x - 40, y, x, y);
	outtextxy(x-35, y-25, "R.I.P");
    arc(x - 20, y - 22, 0, 180, 21);
}

void tree1(int x, int y){
    line(207 + x,220 + y,207 + x,280 + y);
    line(240 + x,220 + y,240 + x,280 + y);
    ellipse(200 + x,200 + y,90,290,25,30);
    ellipse(222 + x,175 + y,360,180,30,30);
    ellipse(243 + x,200 + y,270,90,35,30);
}

void tree2(int x, int y){
    line(215 + x,220 + y,215 + x,270 + y);
    line(240 + x,220 + y,240 + x,270 + y);

    line(218 + x,225 + y,195 + x,225 + y);
    line(237 + x,225 + y,260 + x,225 + y);

    line(195 + x,225 + y,227 + x,185 + y);
    line(260 + x,225 + y,227 + x,185 + y);
}

void customCircle(int x, int y,int rad, int outlnColor, int fillColor){
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

void customCloud(int x, int y, int rad){
    if(x >= 1050){
        x = m_cloud+250;
    }
    setcolor(BLACK);
    arc(x, y, 35, 90+55, rad);
    arc(x, y, 180+35, 180+90+55, rad);
    arc(x-30, y, 35, 180+90+55, rad);
    arc(x+30, y, 180+35, 90+55, rad);

    setcolor(11);
    setfillstyle(SOLID_FILL, 11);
    floodfill(x, y, 0);

    setcolor(15);
}

void humansAndTree(int bgColor){
    setcolor(bgColor);
   // singleMan(500, 500, 10);
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
    customCircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCircle(midx+35, midy+20, 4, 15, 15);
    customCircle(midx-135,midy+80, 4, 15, 15);
    customCircle(midx+150,midy+100, 10, 15, 15);

    customStar4Edge(midx-120, midy-120, 15);
    showTextInGraphicsWindow(midx+180, midy+40, "The OLD EARTH", 12, 15, 3);
    ShowPressKey(midx, midy);
    getch();
    cleardevice();

    //2nd still img...
    customCircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCircle(midx+35, midy+20, 4, 15, 15);
    customCircle(midx-135,midy+80, 4, 15, 15);
    customCircle(midx+150,midy+100, 10, 15, 15);

    customCircle(midx+450,midy-250, 4, 15, 15);

    customStar4Edge(midx-120, midy-120, 15);
    showTextInGraphicsWindow(midx+180, midy+40, "The OLD EARTH", 12, 15, 3);
    showTextInGraphicsWindow(midx+450, midy-220, "Unknown OBJECT", 12, 15, 3);
    ShowPressKey(midx, midy);
    getch();
    cleardevice();

    //3nd still img...
    customCircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCircle(midx+35, midy+20, 4, 15, 15);
    customCircle(midx-135,midy+80, 4, 15, 15);
    customCircle(midx+150,midy+100, 10, 15, 15);

    customCircle(midx+100,midy-205, 4, 15, 15);

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
    customCircle(midx, midy, 125, 15, 4);

    ellipse(midx, midy, start_angle, end_angle, x_rad, y_rad);

    customCircle(midx+35, midy+20, 4, 15, 15);
    customCircle(midx-135,midy+80, 4, 15, 15);
    customCircle(midx+150,midy+100, 10, 15, 15);

    customStar4Edge(midx-120, midy-120, 15);
    ShowPressKey(midx, midy);

    ellipse(midx+100, 755, 90, 120, 200, 600);
    line(midx+450,midy-250, midx+100,midy-205);

    customCircle(midx, midy, 125, 15, 7);

    setcolor(4);
    customCircle(midx, midy-125, 4, 4, 4);

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
    floodfill(midx, midy, 1);

    setbkcolor(BLACK);

    ShowPressKey(midx, midy);
    getch();
    cleardevice();
}

void daySeen(int midx, int midy){

    for(; ;){
        cleardevice();
        if(m_sun == 150){           //this valid or not
            m_sun = 0;
            s_count = 0;
            break;
        }

        if(kbhit()){           //this valid break loop and stop code
            break;
        }

        int x0 = 125, y0 = 90;
        int here_y = 80;

        setbkcolor(WHITE);                  //for full screen color 15

        setcolor(YELLOW);
        m_sun = m_sun +1;

        customCircle(x0, m_sun, 40, YELLOW, YELLOW);        //for sun

        m_cloud = m_cloud+2;
        if(m_cloud==1050){
            m_cloud = 300;
        }
        customCloud( m_cloud-20,y0+10, 25);
        customCloud( m_cloud+150,y0-50, 25);
        customCloud( m_cloud+500,y0+10, 25);         //3 cloud

        //(0,0 to 1079,179)---Here add [ 'sky', planet or sky view [like, moon, sun, star, etc] ]---//

        humansAndTree(0);

        setcolor(YELLOW);
        line(0,179,1079,179);

        //(0,359 to 1079,359)--------Here add [ Tree & other senary ]-------------------------------//

        setcolor(YELLOW);
        line(0,359,1079,359);

        setcolor(BLACK);
        line(0,610,1079,610);
        line(0,611,1079,611);

        setlinestyle(1, 0, 1);
        line(0,612,1079,612);
        line(0,613,1079,613);

        setlinestyle(0, 0, 1);
        line(0,614,1079,614);
        line(0,615,1079,615);

        //(0,659 to 1079,659)------Here add [ Subject & main content ]-------------------------------//

        setcolor(YELLOW);
        line(0,659,1079,659);

        setcolor(BLACK);
        for(int i = -30; i<1150; i = i+60){
            arc(i, 700, 0+40, 180-40, 50);
        }
        //(0,659 to 1079,659)-------------Here add [ Footer ]-----------------------------------------//
        delay(DELAY);
    }
}

void nightSeen(int midx, int midy){
    for(; ;){
        cleardevice();

        if(kbhit()){           //this valid break loop and stop code
            break;
        }

        for(int i=0; i<=100; i++){
            int x=rand()%1079;
            int y=rand()%179;
            putpixel(x,y,i%15);

            if(i==25){
                customStar4Edge(x, y, 5);
                customStar4Edge(x+400, y, 5);
            }
        }

        customStar4Edge(1000, 100, 8);
        customStar4Edge(300, 50, 6);

        if(m_sun == 150){           //this valid or not
            m_sun = 0;
            s_count = 1;
            break;
        }

        int x0 = 125, y0 = 90;
       /*for moon*/
        int here_y = 80;

        setbkcolor(BLACK);                  //for full screen color 0

        setcolor(WHITE);
        m_sun = m_sun +1;

        setfillstyle(SOLID_FILL,WHITE);

        arc(x0, m_sun, 180+30, 90, 41);              //for moon
        arc(x0-15, m_sun-9, 180+55, 90-22, 35);

        floodfill(x0+39, m_sun,WHITE);

        //(0,0 to 1079,179)---Here add [ 'sky', planet or sky view [like, moon, sun, star, etc] ]---//

        setcolor(YELLOW);
        line(0,179,1079,179);

        humansAndTree(15);

        //(0,359 to 1079,359)--------Here add [ Tree & other senary ]-------------------------------//

        setcolor(YELLOW);
        line(0,359,1079,359);

        setcolor(WHITE);
        line(0,610,1079,610);
        line(0,611,1079,611);

        setlinestyle(1, 0, 1);
        line(0,612,1079,612);
        line(0,613,1079,613);

        setlinestyle(0, 0, 1);
        line(0,614,1079,614);
        line(0,615,1079,615);

        //(0,659 to 1079,659)------Here add [ Subject & main content ]-------------------------------//

        setcolor(YELLOW);
        line(0,659,1079,659);

        setcolor(WHITE);
        for(int i = -30; i<1150; i = i+60){
            arc(i, 700, 0+40, 180-40, 50);
        }
        //(0,659 to 1079,659)-------------Here add [ Footer ]-----------------------------------------//
        delay(DELAY);
    }
}

void mainProcess(int midx, int midy){
    showTextInGraphicsWindowFullScr(midx, midy, "A long, long time ago...");

    while(!kbhit()){
        cleardevice();

        if(s_count == 1){
            daySeen(midx, midy);
        }else{
            nightSeen(midx, midy);
        }
    }
}

int main(){
    initwindow(1080,720,"The Khalid's BGI");
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    firstIntro(midx, midy);       //This is done!! :)
    secondIntro(midx, midy);      //This is done!! :)
    mainProcess(midx, midy);      //Total placement done//

    getch();
    closegraph();
}
