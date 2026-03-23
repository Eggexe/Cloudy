#include "drawing.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

void CDY_ArmRenderer(CDY_Simple_Window *window) {
    SDL_RenderPresent(window->renderer);
}

void CDY_ColorRenderer(CDY_Simple_Window *window, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) {
    SDL_SetRenderDrawColor(window->renderer, red, green, blue, alpha);
}

void CDY_WipeRenderer(CDY_Simple_Window *window) {
    SDL_RenderClear(window->renderer);
}
