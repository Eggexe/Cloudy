#ifndef SIMPLE_WINDOW_H // makes the simple window header if not alr made
#define SIMPLE_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

// SDL abstractions for a single-colour window
typedef struct {
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;
} CDY_Simple_Window;

// Creates a simple, single colour window
CDY_Simple_Window *CDY_SimpleWindowCreate(const char *title, int width, int height);

// Destroys said window
void CDY_SimpleWindowDestroy(CDY_Simple_Window *window);

#endif
