#ifndef  INPUT_MAN_H
#define INPUT_MAN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

typedef struct{
    const Uint8 *keyboard_state;
    /*
     * Why do this? Personal note
     * const - forces it to be untouched so no weird things happen
     * Uint8 ensures 8 bits (1 byte) for a char on keyboard, point to that too
     * save as input manager
     */
} CDY_InputManager;

typedef enum {
    CDY_KEY_W = SDL_SCANCODE_W,
    CDY_KEY_S = SDL_SCANCODE_S,
    CDY_KEY_UP = SDL_SCANCODE_UP,
    CDY_KEY_DOWN = SDL_SCANCODE_DOWN,
    CDY_KEY_SPACE = SDL_SCANCODE_SPACE,
    CDY_KEY_ESCAPE = SDL_SCANCODE_ESCAPE
} CDY_Scancode;

CDY_InputManager *CDY_InputManagerCreate(); // input_man init
void CDY_UpdateInput(CDY_InputManager *input);
int CDY_IsKeyHeld(CDY_InputManager *input, CDY_Scancode key);

#endif
