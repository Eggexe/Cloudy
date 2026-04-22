#include "drawing.h"
#include "simple_window.h"
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

int CDY_DrawRectangle(CDY_Simple_Window *window, CDY_Rectangle rectangle) {
    SDL_RenderDrawRect(window->renderer, &rectangle.rectangle);
    /* Required to draw a rectangle first, see CDY_CreateRectangle */
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
