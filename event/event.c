#include "event.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

int CDY_PollEvent(CDY_Event *event) {
    SDL_Event sdl_event;

    if (SDL_PollEvent(&sdl_event))
    {
        if (sdl_event.type == SDL_QUIT) event->type = CDY_EVENT_QUIT;
        else if (sdl_event.type == SDL_KEYDOWN) event->type = CDY_EVENT_KEYDOWN;
        else if (sdl_event.type == SDL_KEYUP) event->type = CDY_EVENT_KEYUP;
        else event->type = CDY_EVENT_BLANK;
        return 1;
    }
    return 0;
}
