#include "drawing.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

void CDY_ArmRenderer(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
}
