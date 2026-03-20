#ifndef DRAWING_H
#define DRAWING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

void CDY_ArmRenderer(SDL_Renderer *renderer);
void CDY_ColorRenderer(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void CDY_WipeRenderer(SDL_Renderer *renderer);

#endif
