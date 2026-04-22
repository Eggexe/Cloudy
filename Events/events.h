#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

typedef struct {
    SDL_Event event;
} CDY_Event; // CDY Event typedef

int CDY_PollEvent(CDY_Event *event);

#endif
