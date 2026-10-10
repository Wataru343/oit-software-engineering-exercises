#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "mainLoop.h"
#include "block.h"
#include "bullet.h"
#include "wall.h"
#include "collision.h"
#include "pixelmap.h"

void mainLoop(){
  int blockCount;
  int i ,j ,x ,y;
  int ch;
  int stock;
  struct timeval tStart ,tEnd;
  double delay;
  int fpsUpdateCount;
  float fps[10] ,avefps;
  BOOL start;

  clear();

  Block  *block;  
  initBlock(&block);

  Bar *bar;
  initBar(&bar);

  Bullet *bullet;
  initBullet(&bullet);

  Pixel *buffer;
  initPixelmap(&buffer);

  initWall(buffer);

  fpsUpdateCount = 0;
  start = FALSE;

  stock = 3;

  mousemask(BUTTON1_PRESSED | BUTTON2_PRESSED | BUTTON3_PRESSED | REPORT_MOUSE_POSITION, NULL);

  while(1){
    gettimeofday(&tStart ,NULL);
    ch = getch();

    if(ch == 's'){
      start = TRUE;
    }
    
    checkBlockCollision(block ,bullet ,buffer);
    checkWallCollision(bullet);
    checkBarCollision(bullet ,bar);
    updateBlock(block ,buffer);
    updateBar(bar ,ch ,buffer ,bullet ,start);
    updateBullet(bullet ,buffer ,start);
    updatePixel(buffer ,block);

    if(checkLineOver(bullet ,&stock)){
      start = FALSE;
      restartBullet(bullet ,buffer ,bar);
    }
    move(0, 0);

    if(ch == 'q'){
      clear();
      free(block);
      return;
    }
    
    refresh();

    gettimeofday(&tEnd ,NULL);
    delay = (float)(tEnd.tv_usec - tStart.tv_usec);
    if(delay < 0){
     delay += 1000000;
    }

    if(delay < 1000000/60){
      usleep(1000000/60 - (int)delay);
    }

    gettimeofday(&tEnd ,NULL);

    if(fpsUpdateCount < 10){
      fps[fpsUpdateCount] = 1000000 / ((float)(tEnd.tv_usec - tStart.tv_usec));
      if(fps[fpsUpdateCount] < 0){
	fps[fpsUpdateCount] += 60;
      }
      fpsUpdateCount++;
    }else if(fpsUpdateCount == 10){
      avefps = 0;
      avefps = fps[0] + fps[1] + fps[2] + fps[3] + fps[4] + fps[5] + fps[6] + fps[7] + fps[8] + fps[9];
      avefps /= 10;
      fpsUpdateCount = 0;
    }


    mvprintw(0 ,75 ,"%dframe",frameCount);
    mvprintw(1 ,75 ,"%.2ffps",avefps);
    frameCount++;
  }


 return;
}
