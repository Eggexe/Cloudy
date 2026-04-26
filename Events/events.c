#include "events.h"
#include <SDL2/SDL_events.h>

int CDY_PollEvent(CDY_Event *event) {
    SDL_Event sdl_event;
    if (SDL_PollEvent(&sdl_event)) {
        if (sdl_event.type == SDL_QUIT) event->type = CDY_EVENT_QUIT;
        else if (sdl_event.type == SDL_KEYDOWN) event->type = CDY_EVENT_KEYDOWN;
        else event->type = CDY_EVENT_NONE;
        return 1;
    }
    return 0;

    /* CDY_Event event;
    while (CDY_PollEvent(&event)) {
        if (event.type == CDY_EVENT_QUIT) running = 0;
    }
    */
}
