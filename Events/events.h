#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

typedef enum {
    CDY_EVENT_QUIT,
    CDY_EVENT_KEYDOWN,
    CDY_EVENT_KEYUP,
    CDY_EVENT_NONE
} CDY_EventType;

typedef struct {
    CDY_EventType type;
} CDY_Event;


int CDY_PollEvent(CDY_Event *event);

#endif
