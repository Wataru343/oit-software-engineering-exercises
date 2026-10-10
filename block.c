#include <stdlib.h>
#include <ncurses.h>
#include "mainLoop.h"

void initBlock(Block **block){
  int blockCount;
  int i ,j ,x ,y;
  Block *tmp;

  *block = malloc(sizeof(Block) * 600);
  getmaxyx(stdscr ,y ,x);

  (*block)->cnt = 600;
  tmp = (*block);

  for(i = 0 ; i < 25 ; i++){
    for(j = 0 ; j < 6 ; j++){
      tmp->updateFlg = TRUE;
      tmp->collision = TRUE;
      tmp->x =width / 2 + i * 20 - 5 - 250;
      tmp->y = j * 12 + 20 +5;

      tmp->c1.x = tmp->x - 10;
      tmp->c1.y = tmp->y - 6;
      tmp->c2.x = tmp->x + 8;
      tmp->c2.y = tmp->y - 6;
      tmp->c3.x = tmp->x - 10;
      tmp->c3.y = tmp->y + 4;
      tmp->c4.x = tmp->x + 8;
      tmp->c4.y = tmp->y + 4;

      tmp++;
    }
  }
}

void updateBlock(Block *block ,Pixel *buffer){
  int i ,j ,k;

  for(i = 0 ; i < block->cnt ; i++){
    if(block[i].updateFlg){
      for(k = -6 ; k <= 4 ; k++){
	for(j = -10 ; j <= 8 ; j++){
	  (buffer + block[i].x + j + width * (block[i].y + k))->block = TRUE;
	  (buffer + block[i].x + j + width * (block[i].y + k))->update = TRUE;
	}
      }
      block[i].updateFlg = FALSE;
    }
  }
}
