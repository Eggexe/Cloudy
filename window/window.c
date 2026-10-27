#include "window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

CDY_SimpleWindow *CDY_SWCreate(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {printf("Init error %s\n", SDL_GetError()); return NULL;}

    SDL_Window *window = SDL_CreateWindow(title, 250, 250, width, height, 0);
    if (window == NULL) {printf("Window error %s\n", SDL_GetError()); return NULL;}

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {printf("Render error %s\n", SDL_GetError()); return NULL;}

    CDY_SimpleWindow *CDY_SW = malloc(sizeof(CDY_SimpleWindow));
    CDY_SW->sdl_window = window;
    CDY_SW->sdl_renderer = renderer;

    return CDY_SW;
}

void CDY_SWDestroy(CDY_SimpleWindow *window) {
    SDL_DestroyRenderer(window->sdl_renderer);
    SDL_DestroyWindow(window->sdl_window);
    free(window);
}
