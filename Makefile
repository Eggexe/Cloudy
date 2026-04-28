CC = gcc
CFLAGS = -I/usr/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT -I.
LIBS = -L/usr/lib -lSDL2 -lSDL2_mixer -lSDL2_ttf

all:
	$(CC) EngineTest.c Render/simple_window.c Render/drawing.c Input/input_man.c Entity/entity.c Physics/physics.c Ext/misc.c -o cloudy $(CFLAGS) $(LIBS)
