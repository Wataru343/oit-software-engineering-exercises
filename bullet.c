#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include "mainLoop.h"

void initBullet(Bullet **bullet){
  int x ,y;
  *bullet = malloc(sizeof(Bullet));
  getmaxyx(stdscr ,y ,x);
  (*bullet)->x = width/2 + 10;
  (*bullet)->y = height - 20;
  (*bullet)->direction = M_PI + M_PI/2 + 0.5;
  (*bullet)->speed = 1.233;
  (*bullet)->c1.x =(*bullet)->x - 6;
  (*bullet)->c1.y =(*bullet)->y - 3;
  (*bullet)->c2.x =(*bullet)->x + 6;
  (*bullet)->c2.y =(*bullet)->y - 3;
  (*bullet)->c3.x =(*bullet)->x - 6;
  (*bullet)->c3.y =(*bullet)->y + 3;
  (*bullet)->c4.x =(*bullet)->x + 6;
  (*bullet)->c4.y =(*bullet)->y + 3;
}

void updateBullet(Bullet *bullet ,Pixel *buffer ,BOOL start){
  int i;

  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->update = TRUE;
    }

  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->update = TRUE;
  }


  if(start){
    bullet->x += cos(bullet->direction) * bullet->speed * 4;
    bullet->y += sin(bullet->direction) * bullet->speed;
  }


  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->update = TRUE;
  }

  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->update = TRUE;
  }


  bullet->c1.x = bullet->x - 6;
  bullet->c1.y = bullet->y - 3;
  bullet->c2.x = bullet->x + 6;
  bullet->c2.y = bullet->y - 3;
  bullet->c3.x = bullet->x - 6;
  bullet->c3.y = bullet->y + 3;
  bullet->c4.x = bullet->x + 6;
  bullet->c4.y = bullet->y + 3;

}

void restartBullet(Bullet *bullet ,Pixel *buffer ,Bar *bar){
  int i ,j;

  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->update = TRUE;
    }

  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->bullet = FALSE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->update = TRUE;
  }


  bullet->x = bar->x;
  bullet->y = bar->y - 5;


  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 3))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 2))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y - 1))->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)bullet->y)->update = TRUE;
  }

  for(i = -6 ; i <= 6 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 1))->update = TRUE;
  }

  for(i = -4 ; i <= 4 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 2))->update = TRUE;
  }

  for(i = -2 ; i <= 2 ; i++){
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->bullet = TRUE;
    (buffer + (int)bullet->x + i + width * (int)(bullet->y + 3))->update = TRUE;
  }
}
