#include "drawing.h"
#include "simple_window.h"
#include "../Entity/entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
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

int CDY_DrawEntity(CDY_Simple_Window *window, CDY_Entity *entity) {
    SDL_Rect rect;
    rect.x = (int)entity->posX;
    rect.y = (int)entity->posY;
    rect.w = (int)entity->scaleX;
    rect.h = (int)entity->scaleY;
    SDL_RenderFillRect(window->renderer, &rect);
}

CDY_Rectangle CDY_CreateRectangle(int x, int y, int w, int h) {
    CDY_Rectangle rect;
    rect.rectangle.x = x;
    rect.rectangle.y = y;
    rect.rectangle.w = w;
    rect.rectangle.h = h;

    return rect;

    /* USAGE: CDY_Rectangle NAME = CDY_CreateRectangle(x,y,w,h) */
}
