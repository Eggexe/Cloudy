#ifndef DRAWING_H
#define DRAWING_H

#include "simple_window.h"
#include "../Entity/entity.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>


// Abstraction of SDL_Rectangle into a CDY counterpart, used the same
typedef struct{
    SDL_Rect rectangle;
} CDY_Rectangle;


// Creates a rectangle with an x and y position, width and height as integers
CDY_Rectangle CDY_CreateRectangle(int x, int y, int w, int h);

// Draw entity on screen, renderer needs to be colored and armed after drawing
// *window is the simple window variable
// *entity is the entity variable to draw
int CDY_DrawEntity(CDY_Simple_Window *window, CDY_Entity *entity);

// Draw to the screen everything that needs to be sent to the screen
void CDY_ArmRenderer(CDY_Simple_Window *window);

// Colour renderer. If used after an entity it will colour that entity
void CDY_ColorRenderer(CDY_Simple_Window *window, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

// Clears the renderer to avoid repeated entity stamping
void CDY_WipeRenderer(CDY_Simple_Window *window);



#endif
