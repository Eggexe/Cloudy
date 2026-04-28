#ifndef  INPUT_MAN_H
#define INPUT_MAN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

// 1 byte is saved for saving keys pressed on keyboard state
// for future comparison
typedef struct{
    const Uint8 *keyboard_state;
} CDY_InputManager;

// Abstracts SDL_SCANCODE to a CDY alternative
typedef enum {
    CDY_KEY_W = SDL_SCANCODE_W,
    CDY_KEY_S = SDL_SCANCODE_S,
    CDY_KEY_UP = SDL_SCANCODE_UP,
    CDY_KEY_DOWN = SDL_SCANCODE_DOWN,
    CDY_KEY_SPACE = SDL_SCANCODE_SPACE,
    CDY_KEY_ESCAPE = SDL_SCANCODE_ESCAPE
} CDY_Scancode;

// Creates an input manager, takes no parameters
CDY_InputManager *CDY_InputManagerCreate(); // input_man init

// Asks OS for the newest events
// *input: variable to the input manager
void CDY_UpdateInput(CDY_InputManager *input);

// Asks for the key held, returns 1 if it is, 0 if not
// *input: variable to the input manager
// CDY_Scancode key: See CDY_Scancode enum above for a list of keys
int CDY_IsKeyHeld(CDY_InputManager *input, CDY_Scancode key);

#endif
