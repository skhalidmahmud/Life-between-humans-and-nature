#include <graphics.h>
#include<stdio.h>
int main(){
    initwindow(1080,720,"The BGI");

    //(0,0 to 1079,179)-----------------------------------------Here add [ 'sky', planet or sky view [like, moon, sun, star, etc] ]-----------------------------------------//

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(150,90,40);
    floodfill(150,90,WHITE);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(150-10,90-7,35);
    floodfill(150-20,90-18,BLACK);

    setcolor(YELLOW);
    line(0,179,1079,179);

    //(0,359 to 1079,359)----------------------------------------------------------Here add [ Tree & other senary ]--------------------------------------------------------//

    setcolor(YELLOW);
    line(0,359,1079,359);

    //(0,659 to 1079,659)---------------------------------------------------------Here add [ Subject & main content ]-------------------------------------------------------//

    setcolor(YELLOW);
    line(0,659,1079,659);


    //(0,659 to 1079,659)----------------------------------------------------------------Here add [ Footer ]----------------------------------------------------------------//
	getch();
	closegraph();

	return 0;
}