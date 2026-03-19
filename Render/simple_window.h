#ifndef SIMPLE_WINDOW_H // makes the simple window header if not alr made
#define SIMPLE_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

typedef struct {
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;
} CDY_Simple_Window; // this makes it the word

CDY_Simple_Window *cdy_simple_window_create(const char *title, int width, int height);
void cdy_simple_window_destroy(CDY_Simple_Window *window); // parameters here

#endif
// simple window definition ft window + rend
// mostly a proof of concept cuz this is rlly useless
