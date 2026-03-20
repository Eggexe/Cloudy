CC = gcc
CFLAGS = -I/usr/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT
LIBS = -L/usr/lib -lSDL2

all:
	$(CC) EngineInit.c Render/simple_window.c Render/drawing.c Render/misc.c -o cloudy $(CFLAGS) $(LIBS)
