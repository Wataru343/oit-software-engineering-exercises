LDLIBS = -lncursesw

main.o: main.c
	cc -c main.c
mainLoop.o: mainLoop.c
	cc -c mainLoop.c
block.o: block.c
	cc -c block.c
bar.o: bar.c
	cc -c bar.c
bullet.o: bullet.c
	cc -c bullet.c -lm
wall.o: wall.c
	cc -c wall.c
collision.o: collision.c
	cc -c collision.c -lm
pixelmap.o: pixelmap.c
	cc -c pixelmap.c
main: main.o mainLoop.o block.o bar.o bullet.o wall.o collision.o pixelmap.o
	cc -o main.exe main.o mainLoop.o block.o bar.o bullet.o wall.o collision.o pixelmap.o  -lncursesw -lm
