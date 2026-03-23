#ifndef DRAWING_H
#define DRAWING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "simple_window.h"

void CDY_ArmRenderer(CDY_Simple_Window *window);
void CDY_ColorRenderer(CDY_Simple_Window *window, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void CDY_WipeRenderer(CDY_Simple_Window *window);

#endif
