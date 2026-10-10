#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "mainLoop.h"

void initPixelmap(Pixel **buffer){
  *buffer = malloc(sizeof(Pixel) * width * height);
  memset(*buffer ,0 ,sizeof(Pixel) * width * height);
}

void updatePixel(Pixel *buffer ,Block *b){
  int i ,j;
 
  for(j = 0 ; j < height ; j++){
    for(i = 0 ; i < width ; i++){
      if(buffer->update == FALSE){
	buffer++;
	continue;
      }
      if(buffer->block == TRUE || buffer->bar == TRUE || buffer->bullet == TRUE || buffer->wall == TRUE){
	mvprintw(j ,i ,"■");
	buffer->update = FALSE;
      }else{
	/*move(j ,i);
	clrtoeol();*/
	mvprintw(j ,i ," ");
	buffer->update = FALSE;
      }
	buffer++;
    }
  }
}
