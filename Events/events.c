#include "events.h"
#include <SDL2/SDL_events.h>

int CDY_PollEvent(CDY_Event *event) {
    return SDL_PollEvent(&event->event);
}
