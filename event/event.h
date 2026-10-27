#pragma once

typedef enum {
    CDY_EVENT_QUIT,
    CDY_EVENT_KEYDOWN,
    CDY_EVENT_KEYUP,
    CDY_EVENT_BLANK
} CDY_EventType;

typedef struct {
    CDY_EventType type;
} CDY_Event;

// Required -> *event requires &event
// Matches a CDY_Event var to a CDY_EventType
// CDY_EVENT_BLANK is an unknown type, scope for which may be added
int CDY_PollEvent(CDY_Event *event);
