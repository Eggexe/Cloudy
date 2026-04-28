#include "input_man.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>

CDY_InputManager *CDY_InputManagerCreate() {   // input_man initm
    CDY_InputManager *input = malloc(sizeof(CDY_InputManager));
    input -> keyboard_state = SDL_GetKeyboardState(NULL);
    return input;
} // creates input manager on heap
  // GetKeyboardState returns pointer to SDL's keyboard array
  // NULL ignores volume of keys, we want them all

void CDY_UpdateInput(CDY_InputManager *input) {
    SDL_PumpEvents(); // ask os for new events otherwise nothing gets sent back to engine
}

int CDY_IsKeyHeld(CDY_InputManager *input, CDY_Scancode key) {
    return input->keyboard_state[key];
    // Reminder - SDL_Scancode is an enum, keys become numbers
    // Function purely returns a 1 if key is held, 0 if not
    // (It checks the byte at the malloc location btw)
}
