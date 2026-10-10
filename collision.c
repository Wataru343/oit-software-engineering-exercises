#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include "mainLoop.h"


void checkBlockCollision(Block *block ,Bullet *bullet ,Pixel *buffer){
  int i , j ,k;

  for(i = 0 ; i < block->cnt ; i ++){
    if(bullet->c2.x >= block[i].c1.x && bullet->c1.x <= block[i].c2.x && bullet->c1.y <= block[i].c3.y && bullet->c3.y >= block[i].c1.y && block[i].collision){

      for(k = -6 ; k <= 4 ; k++){
	for(j = -10 ; j <= 8 ; j++){
	  (buffer + block[i].x + j + width * (block[i].y + k))->block = FALSE;
	  (buffer + block[i].x + j + width * (block[i].y + k))->update = TRUE;
	}
      }
      block[i].collision = FALSE;
      bullet->speed += 0.01;

      //left
      if(bullet->c1.x - cos(bullet->direction) * bullet->speed >= block[i].c2.x){
	bullet->direction +=M_PI;
	bullet->direction *= -1;
	break;
      }

      if(bullet->c2.x - cos(bullet->direction) * bullet->speed <= block[i].c1.x){
	bullet->direction +=M_PI;
	bullet->direction *= -1;
	break;
      }


      if(bullet->c1.y - sin(bullet->direction) * bullet->speed >= block[i].c3.y){
	bullet->direction *= -1;
	break;
      }

      if(bullet->c2.y - sin(bullet->direction) * bullet->speed <= block[i].c1.y){
	bullet->direction *= -1;
	break;
      }
    }
    /*if((int)bullet->x == block[i].x && (int)bullet->y == block[i].y){
      (buffer + block[i].x + width * block[i].y)->block = FALSE;
      (buffer + block[i].x + width * block[i].y)->update = TRUE;
      block[i].updateFlg = FALSE;
      bullet->angle = -bullet->angle;
    }*/
  }
}

void checkWallCollision(Bullet *bullet){
  if(bullet->c2.x >= width - 10){
    bullet->direction +=M_PI;
    bullet->direction *= -1;
  }

  if(bullet->c1.x <= 10){
    bullet->direction +=M_PI;
    bullet->direction *= -1;
  }
  if(bullet->c1.y <= 10){
    bullet->direction *= -1;
  }
  if(bullet->c3.y >= height -10){
    // bullet->direction *= -1;
  }
}

void checkBarCollision(Bullet *bullet ,Bar *bar){
  if(bullet->c3.x <= bar->c2.x && bullet->c4.x >= bar->c1.x && bullet->c3.y > bar->c1.y){
    bullet->direction *= -1;
    bullet->direction +=  ((float)(rand() / ((float)RAND_MAX + 1)) * 0.314);
  }
}

BOOL checkLineOver(Bullet *bullet ,int *stock){
  if(bullet->c3.y > height -5){
bullet->direction = M_PI + M_PI/2 +  0.5;
    return TRUE;
  }
  return FALSE;
}
