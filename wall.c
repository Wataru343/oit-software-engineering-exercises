#include <ncurses.h>
#include "mainLoop.h"

void initWall(Pixel *buffer){
  int i ,j;

  for(j = 0 ; j < height ; j++){
    for(i = 0 ; i < width ; i++){
      if(i == 10 && j >= 10 && j <= height -10 || i == width - 10  && j >= 10 && j <= height -10 || j == 10 && i >=10 && i <= width -10 || j == height -10 && i >=10 && i <= width -10){
      (buffer + i + width * j)->wall = TRUE;
      (buffer + i + width * j)->update = TRUE;
      }
    }
  }
}
