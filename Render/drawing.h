#ifndef DRAWING_H
#define DRAWING_H

#include "simple_window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct{
    SDL_Rect rectangle;
} CDY_Rectangle;

CDY_Rectangle CDY_CreateRectangle(int x, int y, int w, int h);
int CDY_DrawRectangle(CDY_Simple_Window *window, CDY_Rectangle rectangle);
void CDY_ArmRenderer(CDY_Simple_Window *window);
void CDY_ColorRenderer(CDY_Simple_Window *window, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void CDY_WipeRenderer(CDY_Simple_Window *window);



#endif
