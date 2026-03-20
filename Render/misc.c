#include "misc.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void CDY_Pause(int time) {
    SDL_Delay(time);
}


void CDY_Close() {
    SDL_Quit();
}
