#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

// Keyboard events to raise for future events
// QUIT: Close game
// Keydown: Key is pressed down
// Keyup: Key is released
// None: No event
typedef enum {
    CDY_EVENT_QUIT,
    CDY_EVENT_KEYDOWN,
    CDY_EVENT_KEYUP,
    CDY_EVENT_NONE
} CDY_EventType;

// Places event types into CDY_Event for function usage
typedef struct {
    CDY_EventType type;
} CDY_Event;

// Asks for an event
// *event will require the address of event (&)
int CDY_PollEvent(CDY_Event *event);

#endif
