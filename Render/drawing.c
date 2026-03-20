#include "drawing.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

void CDY_ArmRenderer(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
}

void CDY_ColorRenderer(SDL_Renderer *renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
}

void CDY_WipeRenderer(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
}
