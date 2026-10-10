#define BOOL _Bool
#define bool _Bool
#define TRUE 1
#define true 1
#define FALSE 0
#define false 0
#define width 800
#define height 200

typedef struct{
  int x;
  int y;
}Collision;

typedef struct{
  int x;
  int y;
  int cnt;
  BOOL updateFlg;
  BOOL collision;
  Collision c1 ,c2 ,c3, c4;
}Block;

typedef struct{
  int x;
  int y;
  Collision c1 ,c2 ,c3 ,c4;
}Bar;

typedef struct{
  float x;
  float y;
  float direction;
  float speed;
  Collision c1 ,c2 ,c3, c4;
}Bullet;

typedef struct{
  BOOL block;
  BOOL bar;
  BOOL bullet;
  BOOL wall;
  BOOL update;
}Pixel;

extern int frameCount;
extern float fps;

void mainLoop();
