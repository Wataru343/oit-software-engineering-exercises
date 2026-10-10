#include <stdlib.h>
#include <ncurses.h>
#include "mainLoop.h"

void initBar(Bar **bar){
  int x ,y;
  *bar = malloc(sizeof(Bar));
  getmaxyx(stdscr ,y ,x);
  (*bar)->x = width / 2 + 10;
  (*bar)->y = height - 15;
}

void updateBar(Bar *bar ,int cursor ,Pixel *buffer ,Bullet *bullet ,BOOL start){
  int i ,j;

  for(j = -1 ; j <= 1 ; j++){
    for(i = -60 ; i <= 60 ; i++){
      (buffer + bar->x - i + width * (bar->y + j))->bar = FALSE;
      (buffer + bar->x - i + width * (bar->y + j))->update = TRUE;
    }
  }

  switch(cursor){
  case KEY_RIGHT:
    bar->x += 15;

    if(bar->c2.x >= width - 15){
      bar->x -= 15;
      break;
    }

    if(!start){
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
      bullet->x += 15;
    }
    break;
  case KEY_LEFT:
    bar->x -= 15;

    if(bar->c1.x < 30){
      bar->x += 15;
      break;
    }

    if(!start){
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
      bullet->x -= 15;
    }
    break;
  default:
    break;
  }

  for(j = -1 ; j <= 1 ; j++){
    for(i = -60 ; i <= 60 ; i++){
      (buffer + bar->x - i + width * (bar->y + j))->bar = TRUE;
      (buffer + bar->x - i + width * (bar->y + j))->update = TRUE;
    }
  }
  bar->c1.x = bar->x - 60;
  bar->c1.y = bar->y;
  bar->c2.x = bar->x + 60;
  bar->c2.y = bar->y;
}
