#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

typedef struct {
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
} CDY_SimpleWindow;

CDY_SimpleWindow *CDY_SWCreate(const char *title, int width, int height);

void CDY_SWDestroy(CDY_SimpleWindow *window);
