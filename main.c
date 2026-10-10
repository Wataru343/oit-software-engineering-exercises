#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
#include "main.h"
#include "mainLoop.h"

int frameCount;
float fps;

void initSetting(){
  WINDOW *window;
  setlocale(LC_ALL ,"");
  window = initscr();
  noecho();
  cbreak();
  crmode();
  curs_set(0);
  timeout(0);
  keypad(stdscr, TRUE);
  
}  

void showMainMenu(){
  int x,y,a=0;
  int ch;
  int cursor = 0;
  frameCount = 0;

  move(0 ,0);
  addch('G' | A_UNDERLINE);
  addch('a' | A_UNDERLINE);
  addch('m' | A_UNDERLINE);
  addch('e' | A_UNDERLINE);
  addch(' ' | A_UNDERLINE);
  addch('s' | A_UNDERLINE);
  addch('t' | A_UNDERLINE);
  addch('a' | A_UNDERLINE);
  addch('r' | A_UNDERLINE);
  addch('t' | A_UNDERLINE);
  mvprintw(1 ,0 ,"Ranking");
  mvprintw(2 ,0 ,"Exit");

  getmaxyx(stdscr, y, x);

  while(1){
    ch = getch();

    if(ch == 10){
      clear();
      switch(cursor){
      case 0:
	mvprintw(10 ,10 ,"Game start");
	mainLoop();
	continue;
      case 1:
	mvprintw(10 ,10 ,"Ranking");
	continue;
      case 2:
	mvprintw(10 ,10 ,"Exit");
	return;
	continue;
      default:
	break;
      }
    }

    if(ch == KEY_UP){
      if(cursor != 0) cursor--;
    }
    if(ch == KEY_DOWN){
      if(cursor != 2) cursor++;
    }
    mvprintw(0 ,0 ,"Game start");
    mvprintw(1 ,0 ,"Ranking");
    mvprintw(2 ,0 ,"Exit");

    switch(cursor){
    case 0:
      move(0 ,0);
      addch('G' | A_UNDERLINE);
      addch('a' | A_UNDERLINE);
      addch('m' | A_UNDERLINE);
      addch('e' | A_UNDERLINE);
      addch(' ' | A_UNDERLINE);
      addch('s' | A_UNDERLINE);
      addch('t' | A_UNDERLINE);
      addch('a' | A_UNDERLINE);
      addch('r' | A_UNDERLINE);
      addch('t' | A_UNDERLINE);
      break;
    case 1:
      move(1 ,0);
      addch('R' | A_UNDERLINE);
      addch('a' | A_UNDERLINE);
      addch('n' | A_UNDERLINE);
      addch('k' | A_UNDERLINE);
      addch('i' | A_UNDERLINE);
      addch('n' | A_UNDERLINE);
      addch('g' | A_UNDERLINE);
      break;
    case 2:
      move(2 ,0);
      addch('E' | A_UNDERLINE);
      addch('x' | A_UNDERLINE);
      addch('i' | A_UNDERLINE);
      addch('t' | A_UNDERLINE);
      break;
    default:
      break;
    }

    mvprintw(1 ,75 ,"%dframe",frameCount);
    frameCount++;
    if(ch == 'q'){
      endwin();
      return;
    }
    usleep(1000000/60);
  }
}


      
int main(int argc, char **argv) {

  initSetting();
  showMainMenu();

  initscr();
  printw("EXIT\n");  
  refresh();
  sleep (1);
  endwin();
      
  return 0;
}
