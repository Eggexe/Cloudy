#include "Entity/entity.h"

#include "Input/input_man.h"

#include "Ext/misc.h"

#include "Render/simple_window.h"
#include "Render/drawing.h"

#include "Physics/physics.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

int main(void) {
    /* ENGINE INSTANCES  */
    CDY_Simple_Window *simple_window = CDY_SimpleWindowCreate("yes", 250, 250);
    CDY_InputManager *input_manager = CDY_InputManagerCreate();
    CDY_EntityManager *entity_manager = CDY_EntityManagerCreate();
    CDY_FPSManager *fps = CDY_FPSManagerCreate(60);

    /* USER VARIABLES */
    CDY_Entity *entity1 = CDY_EntityCreate(entity_manager);
    entity1->scaleX = 500;
    entity1->scaleY = 50;
    entity1->posX = 100;
    entity1->posY = 100;

    /* MAIN ENGINE LOOP START*/
    int running = 1;
    while (running) {
        CDY_FPSEnd(fps);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
                break;
            }
        }
        CDY_UpdateInput(input_manager);
        if (CDY_IsKeyHeld(input_manager, SDL_SCANCODE_W)) {
            printf("W KEY HELD\n");
        }

        CDY_ColorRenderer(simple_window, 100, 0, 0, 255);   // bg
        CDY_WipeRenderer(simple_window);                    // clear screen

        CDY_ColorRenderer(simple_window, 0, 0, 255, 255);   // rect colour
        CDY_DrawEntity(simple_window, entity1);             // draw it

        CDY_ArmRenderer(simple_window);

        CDY_FPSEnd(fps);
    }

    /* MAIN ENGINE LOOP END */

    CDY_Close();

    return 0;
}
