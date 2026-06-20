//PLANKTON 

#include <graphics.h>
#include <iostream>
#include <stdio.h>
//#include <SDL2/SDL.h>

//int road, roads, sky, buns, house1, winColor, sign;

#define road     COLOR(68,  84,  110)
#define roads    COLOR(208, 214, 148)
#define sky      COLOR(116, 185, 237)
#define buns     COLOR(250, 213, 92)
#define house1   COLOR(12,  72,  125)
#define winColor COLOR(131, 201, 222)
#define sign     COLOR(147, 179, 230)
#define myWhite  COLOR(255,255,255)
#define myBlack  COLOR(0,0,0)

int plankton = 425;
int planktonSpeed = 2;


void drawScene(bool showLeg, bool showLeg2, bool showArm, bool showArm2, int plankton) {

    cleardevice();

    //background color
      setfillstyle (SOLID_FILL, sky);
      setcolor (sky);
      bar (0, 0, 680, 480);


    //bubble text
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, myWhite);
      fillellipse (405, 60, 150, 60);
      fillellipse (510, 120, 10, 10);
      fillellipse (535, 140, 7, 7);
      fillellipse (560, 160, 6, 6);

      /*
    //text
      setcolor (myBlack);
      setbkcolor (myWhite);
      settextstyle(0, 0, 2);
      outtextxy(330, 15, (char*)"MR. KRAB!!!");
      outtextxy (310, 45, (char*)"PLANKTON STOLE");
      outtextxy (295, 75, (char*)"THE KRABBY PATTY");
*/
      
    //road
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, road);
      fillellipse (340, 455, 340, 45); // filled road shape
      bar (0, 455, 680, 480);          // solid bottom strip
      // original outline arcs kept for appearance
      ellipse (0, 430, 360, 90, 680, 45);
      ellipse (0, 500, 180, 0, 680, 45);
      ellipse (0, 450, 360, 90, 680, 50);

      
    //parking lot
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, road);
      fillellipse (650, 360, 75, 25);

    //pole - use bar instead of floodfill
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, BROWN);
      bar (630, 160, 650, 360);
      // original ellipses kept for shape
      ellipse (650, 260, 90, 270, 10, 100);
      ellipse (630, 260, 90, 270, 10, 100);

    //lines of pole
      line (625, 175, 650, 175);
      line (622, 200, 650, 200);
      line (622, 225, 650, 225);
      line (622, 250, 650, 250);
      line (622, 275, 650, 275);
      line (622, 300, 650, 300);
      line (622, 325, 650, 325);
      line (625, 350, 650, 350);

    //sign - fill with fillellipse/bar then draw outlines on top
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, sign);
      fillellipse (635, 90, 45, 65);   // filled base of sign
      bar (590, 125, 680, 145);
      fillellipse (620, 141, 50, 20);
      // original outlines on top
      setcolor (myBlack);
      ellipse(620, 73, 180, 270, 30, 60);
      ellipse(650, 73, 270, 360, 30, 60);
      ellipse(620, 73, 180, 270, 10, 40);
      line (635, 73, 635, 113);
      line (620, 133, 650, 133);
      arc (605, 73, 0, 180, 15);
      arc (635, 73, 0, 180, 15);
      arc (665, 73, 0, 180, 15);
      arc (580, 140, 0, 180, 10);
      arc (600, 140, 0, 180, 10);
      arc (620, 140, 0, 180, 10);
      arc (640, 140, 0, 180, 10);
      arc (660, 140, 0, 180, 10);

    //coral - fill then draw outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, RED);
      fillellipse (270, 315, 8, 75);
      fillellipse (300, 320, 8, 70);
      fillellipse (285, 280, 60, 40);
      fillellipse (233, 278, 19, 18);
      fillellipse (335, 295, 18, 22);
      // original outlines
      setcolor (myBlack);
      ellipse (270, 350, 90, 270, 5, 40);
      ellipse (300, 355, 90, 270, 5, 35);
      ellipse (300, 285, 270, 360, 55, 35);
      ellipse (270, 277, 180, 270, 55, 35);
      ellipse (290, 270, 180, 0, 40, 20);
      ellipse (233, 275, 0, 180, 19, 20);
      ellipse (335, 290, 360, 90, 20, 25);
      line (330, 270, 335, 265);

    //road 2 - filled polygon then outline
      setcolor (roads);
      setfillstyle (SOLID_FILL, roads);
      int r2pts[] = {315, 390, 720, 300, 720, 318, 315, 408};
      fillpoly (4, r2pts);
      setcolor (myBlack);
      line (315, 390, 720, 300);

    //house 1 - bar then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, house1);
      bar (540, 300, 570, 340);
      bar (550, 280, 560, 300);
      // original outlines
      line (540, 300, 570, 300);
      line (540, 340, 540, 300);
      line (570, 300, 570, 334);
      line (560, 300, 560, 280);
      line (550, 300, 550, 280);
      line (550, 280, 560, 280);
      // window
      setfillstyle (SOLID_FILL, myBlack);
      fillellipse (555, 318, 10, 10);
      circle (555, 318, 10);
      setfillstyle (SOLID_FILL, winColor);
      fillellipse (555, 318, 5, 5);
      circle (555, 318, 5);

    //house 2 - bar then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, DARKGRAY);
      bar (45, 330, 65, 385);
      bar (50, 315, 55, 330);
      // original outlines
      line (45, 330, 65, 330);
      line (45, 385, 45, 330);
      line (65, 330, 65, 385);
      line (50, 330, 50, 315);
      line (55, 330, 55, 315);
      line (50, 315, 55, 315);
      // window
      setfillstyle (SOLID_FILL, myBlack);
      fillellipse (55, 350, 7, 7);
      setfillstyle (SOLID_FILL, winColor);
      fillellipse (55, 350, 4, 4);

    //flower - original lines kept, just fill center
      setcolor (MAGENTA);
      setfillstyle (SOLID_FILL, MAGENTA);
      fillellipse (15, 80, 20, 20);
      circle (15, 80, 20);
      arc (15, 26, 0, 180, 20);
      line (35, 26, 35, 50);
      line (45, 60, 65, 60);
      arc (45, 50, 180, 270, 10);
      arc (65, 78, 270, 90, 19);
      line (35, 104, 35, 120);
      line (45, 95, 65, 95);
      arc (45, 104, 90, 180, 10);
      arc (15, 120, 180, 0, 20);

//KRABBY PATTY

    //buns bottom - fill then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, buns);
      // filled shape
      int bbd[] = {plankton-100, 230, plankton+120, 230, plankton+110, 255, plankton-90, 255};
      fillpoly (4, bbd);
      fillellipse (plankton+10, 255, 100, 15);
      // original outlines
      ellipse (plankton + 10, 255, 180, 0, 100, 15);
      line (plankton - 90, 255, plankton - 100, 230);
      line (plankton + 110, 255, plankton + 120, 230);
      line (plankton - 100, 230, plankton + 120, 230);

    //buns top - fill then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, buns);
      fillellipse (plankton + 10, 175, 120, 55);
      bar (plankton-110, 195, plankton+130, 205);
      ellipse (plankton + 10, 200, 0, 180, 120, 75);
      line (plankton - 110, 200, plankton + 130, 200);
      // sesame seeds
      setfillstyle (SOLID_FILL, myBlack);
      fillellipse (plankton - 95, 190, 3, 3);
      fillellipse (plankton + 5, 170, 3, 3);
      fillellipse (plankton + 35, 160, 3, 3);
      fillellipse (plankton + 75, 150, 3, 3);
      fillellipse (plankton + 85, 160, 3, 3);
      fillellipse (plankton - 25,  160, 3, 3);
      fillellipse (plankton + 35, 140, 3, 3);
      fillellipse (plankton + 85, 150, 3, 3);
      fillellipse (plankton + 55, 150, 3, 3);
      fillellipse (plankton - 5, 150, 3, 3);
      fillellipse (plankton - 45, 140, 3, 3);
      fillellipse (plankton - 65, 150, 3, 3);

    //patty - fill then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, RED);
      fillellipse (plankton + 10, 215, 115, 15);
      ellipse (plankton + 10, 227, 180, 0, 115, 15);
      arc (plankton - 95, 217, 90, 270, 15);
      arc (plankton + 115, 217, 270, 90, 15);
      line (plankton - 95, 202, plankton + 115, 202);

    //lettuce
      setcolor (LIGHTGREEN);
      setfillstyle (SOLID_FILL, LIGHTGREEN);
      fillellipse (plankton - 90, 205, 25, 15);
      fillellipse (plankton - 75, 205, 25, 10);
      fillellipse (plankton - 65, 200, 35, 10);
      fillellipse (plankton - 55, 200, 25, 10);
      fillellipse (plankton - 35, 205, 25, 15);
      fillellipse (plankton - 25, 200, 35, 10);
      fillellipse (plankton - 15, 205, 25, 15);
      fillellipse (plankton + 10, 205, 15, 10);
      fillellipse (plankton + 25, 200, 25, 10);
      fillellipse (plankton + 30, 200, 35, 15);
      fillellipse (plankton + 35, 205, 25, 10);
      fillellipse (plankton + 55, 200, 15, 10);
      fillellipse (plankton + 75, 205, 25, 15);
      fillellipse (plankton + 85, 205, 15, 15);
      fillellipse (plankton + 95, 205, 35, 10);
      fillellipse (plankton + 105, 205, 15, 15);
      fillellipse (plankton + 120, 205, 15, 10);

//PLANKTON

    //robotic arm left - fill then outline
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, LIGHTGRAY);
      fillellipse (plankton - 20, 292, 7, 45);
      ellipse (plankton - 20, 270, 180, 0, 7, 45);
      line (plankton - 27, 268, plankton - 13, 268);

    //robotic arm right - fill then outline
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, LIGHTGRAY);
      fillellipse (plankton + 50, 298, 7, 50);
      ellipse (plankton + 50, 275, 180, 0, 7, 50);
      line (plankton + 43, 275, plankton + 43, 268);
      line (plankton + 57, 275, plankton + 57, 268);
      line (plankton + 43, 268, plankton + 57, 268);

    //body
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      fillellipse (plankton, 325, 27, 50);

    //eye
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, myWhite);
      fillellipse (plankton - 5, 310, 12, 15);
      ellipse (plankton - 5, 310, 0, 360, 12, 15);

    //eye iris
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, RED);
      fillellipse (plankton - 8, 310, 5, 8);
      ellipse (plankton - 8, 310, 0, 360, 5, 8);
      setcolor (YELLOW);
      setfillstyle (SOLID_FILL, YELLOW);
      fillellipse (plankton - 5, 307, 3, 3);
      circle (plankton - 5, 307, 3);

    //mouth - fill then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, RED);
      fillellipse (plankton - 5, 338, 15, 15);
      ellipse (plankton - 5, 330, 180, 0, 15, 5);
      ellipse (plankton + 15, 328, 180, 270, 6, 6);
      ellipse (plankton + 7, 333, 270, 360, 5, 17);
      ellipse (plankton - 3, 350, 180, 0, 10, 5);
      line (plankton - 10, 333, plankton - 8, 352);

    //tongue
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, LIGHTRED);
      fillellipse (plankton + 5, 354, 10, 6);
      ellipse (plankton + 10, 352, 90, 180, 10, 12);

    //eyebrow - fill then outlines
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, myBlack);
      fillellipse (plankton - 3, 288, 15, 6);
      ellipse (plankton + 10, 288, 90, 270, 3, 5);
      ellipse (plankton - 3, 292, 0, 180, 12, 3);
      ellipse (plankton - 3, 285, 0, 180, 12, 3);
      ellipse (plankton - 15, 288, 90, 270, 3, 5);

    // left arm
    if (showArm){
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      fillellipse (plankton - 42, 335, 15, 4);
      ellipse (plankton - 40, 333, 180, 0, 15, 3);
      ellipse (plankton - 40, 338, 180, 0, 15, 3);
      ellipse (plankton - 55, 335, 90, 270, 3, 3);
    }

    // left arm 2
    if (showArm2) {
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      fillellipse (plankton - 30, 348, 25, 20);
      ellipse (plankton - 50, 333, 270, 360, 25, 25);
      ellipse (plankton - 48, 338, 270, 360, 25, 25);
      arc (plankton - 50, 360, 90, 270, 4);
    }

    //right arm
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      fillellipse (plankton + 42, 335, 20, 5);
      ellipse (plankton + 33, 333, 360, 90, 20, 5);
      ellipse (plankton + 33, 338, 360, 90, 20, 5);
      arc (plankton + 52, 335, 270, 90, 3);
      line (plankton + 33, 328, plankton + 33, 333);

    //backpack
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, DARKGRAY);
      // front face
      int bp1[] = {plankton+24, 300, plankton+38, 300, plankton+38, 360, plankton+15, 360};
      fillpoly (4, bp1);
      // side face
      int bp2[] = {plankton+38, 300, plankton+43, 298, plankton+60, 290, plankton+60, 340, plankton+38, 360};
      fillpoly (5, bp2);
      // top
      int bp3[] = {plankton+18, 290, plankton+42, 290, plankton+43, 298, plankton+24, 300};
      fillpoly (4, bp3);
      // original outlines
      line (plankton + 38, 300, plankton + 38, 360);
      line (plankton + 38, 360, plankton + 15, 360);
      line (plankton + 38, 300, plankton + 24, 300);
      line (plankton + 38, 300, plankton + 43, 298);
      line (plankton + 60, 290, plankton + 55, 293);
      line (plankton + 60, 290, plankton + 60, 340);
      line (plankton + 38, 360, plankton + 60, 340);
      line (plankton + 42, 290, plankton + 18, 290);

    //strap
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, myBlack);
      fillellipse (plankton + 33, 333, 6, 12);
      ellipse (plankton + 30, 333, 90, 270, 5, 12);
      ellipse (plankton + 37, 333, 90, 270, 5, 12);
      line (plankton + 30, 321, plankton + 37, 321);
      line (plankton + 30, 345, plankton + 37, 345);

    //left leg
    if (showLeg){
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      fillellipse (plankton - 8, 390, 6, 28);
      ellipse (plankton - 10, 397, 90, 180, 5, 25);
      ellipse (plankton - 5, 397, 90, 180, 5, 25);
      line (plankton - 15, 397, plankton - 10, 397);

    //right leg
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      int rl[] = {plankton+12, 365, plankton+18, 375, plankton+35, 375, plankton+35, 380, plankton+15, 380, plankton+10, 370};
      fillpoly (6, rl);
      line (plankton + 10, 370, plankton + 15, 380);
      line (plankton + 12, 365, plankton + 18, 375);
      line (plankton + 18, 375, plankton + 35, 375);
      line (plankton + 15, 380, plankton + 35, 380);
      arc (plankton + 35, 378, 270, 90, 3);
    }

    //left leg (2)
    if (showLeg2){
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      int ll2[] = {plankton-12, 370, plankton-8, 370, plankton, 375, plankton+22, 375, plankton+22, 380, plankton-5, 380};
      fillpoly (6, ll2);
      ellipse (plankton + 10, 375, 180, 0, 12, 5);
      ellipse (plankton + 8, 380, 180, 0, 12, 5);
      line (plankton - 12, 370, plankton - 5, 380);
      line (plankton - 8, 370, plankton, 375);
      line (plankton + 22, 378, plankton + 20, 380);
      line (plankton + 20, 375, plankton + 22, 380);

    //right leg (2)
      setcolor (myBlack);
      setfillstyle (SOLID_FILL, GREEN);
      int rl2[] = {plankton+5, 373, plankton+10, 370, plankton+5, 400, plankton, 400};
      fillpoly (4, rl2);
      line (plankton + 5, 373, plankton, 400);
      line (plankton + 10, 370, plankton + 5, 400);
      setfillstyle (SOLID_FILL, GREEN);
      fillellipse (plankton + 3, 401, 5, 3);
      arc (plankton + 3, 400, 180, 0, 4);
    }

} // closes drawScene()


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"680 480");

    /*
    road     = COLOR(68,  84,  110);
    roads    = COLOR(208, 214, 148);
    sky      = COLOR(116, 185, 237);
    buns     = COLOR(250, 213, 92);
    house1   = COLOR(12,  72,  125);
    winColor = COLOR(131, 201, 222);
    sign     = COLOR(147, 179, 230);
    */

    bool showLeg  = true;
    bool showLeg2 = false;
    bool showArm  = true;
    bool showArm2 = false;

    while (true) {
        plankton -= planktonSpeed;
        if (plankton < -150) {
            plankton = getmaxx() + 150;
        }

        showLeg  = !showLeg;
        showLeg2 = !showLeg2;
        showArm  = !showArm;
        showArm2 = !showArm2;

        drawScene(showLeg, showLeg2, showArm, showArm2, plankton);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                closegraph();
                return 0;
            }
        }

        SDL_Delay(100);
    }

    getch();
    closegraph();
    return 0;
}