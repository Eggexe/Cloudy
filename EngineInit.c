#include "Render/simple_window.h"
#include "Render/drawing.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int main(void) {

    CDY_Simple_Window *simple_window = cdy_simple_window_create("yes", 250, 250);

    SDL_SetRenderDrawColor(simple_window->renderer, 255, 255, 140, 255);
    SDL_RenderClear(simple_window->renderer);
    CDY_ArmRenderer(simple_window->renderer);

    SDL_Delay(2000);
    SDL_Quit();

    return 0;
}
