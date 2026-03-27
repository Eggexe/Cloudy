#include "input_man.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>



CDY_InputManager *CDY_InputManagerCreate(); // input_man init
void CDY_UpdateInput(CDY_InputManager *input);
int CDY_IsKeyHeld(CDY_InputManager *input, SDL_Scancode key);
