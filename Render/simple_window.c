#include "simple_window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

CDY_Simple_Window *CDY_SimpleWindowCreate(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Init video error %s\n", SDL_GetError());
        return NULL;
    }
    if (TTF_Init() != 0) {
        printf("TTF init error %s\n", TTF_GetError());
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


void CDY_SimpleWindowDestroy(CDY_Simple_Window *window) {
    TTF_Quit();
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->sdl_window);
    free(window);
}
