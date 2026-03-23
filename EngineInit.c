#include "Render/misc.h"
#include "Render/simple_window.h"
#include "Render/drawing.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <stdio.h>

int main(void) {

    CDY_Simple_Window *simple_window = CDY_SimpleWindowCreate("yes", 250, 250);

    CDY_ColorRenderer(simple_window, 100, 0, 0, 255);
    CDY_WipeRenderer(simple_window);
    CDY_ArmRenderer(simple_window);

    /* MAIN ENGINE LOOP START*/

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            printf("Work?");
            CDY_Pause(16);
        }

        CDY_ArmRenderer(simple_window);
    }

    /* MAIN ENGINE LOOP END */

    CDY_Close();

    return 0;
}
