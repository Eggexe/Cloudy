#include "simple_window.h"
#include <SDL2/SDL.h>
#include <stdio.h>

CDY_Simple_Window *cdy_simple_window_create(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Init video error %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow(title, 250, 250, width, height, 0);
    if (window == NULL) {
        printf("Window load error %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer load error %s\n", SDL_GetError());
        return NULL;
    }

    CDY_Simple_Window *cdy_window = malloc(sizeof(CDY_Simple_Window));
    cdy_window->sdl_window = window;
    cdy_window->renderer = renderer;

    return cdy_window;
}
