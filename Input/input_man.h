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


CDY_InputManager *CDY_InputManagerCreate(); // input_man init
void CDY_UpdateInput(CDY_InputManager *input);
int CDY_IsKeyHeld(CDY_InputManager *input, SDL_Scancode key);

#endif
