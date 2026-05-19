CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Wpedantic -g -fsanitize=address -fsanitize=undefined
LIBS = -L/usr/lib -lSDL2 -lSDL2_ttf

CLOUDY_OBJS =

all: $(CLOUDY_OBJS)
	$(CC) $(CFLAGS) Cloudy/tests/cdy_demo.c $(CLOUDY_OBJS) -o EngineTest $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLOUDY_OBJS) EngineTest
