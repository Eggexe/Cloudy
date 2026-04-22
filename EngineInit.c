#include "Entity/entity.h"
#include "Input/input_man.h"
#include "Ext/misc.h"
#include "Render/simple_window.h"
#include "Render/drawing.h"

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

    /* USER VARIABLES */
    CDY_Entity *entity1 = CDY_EntityCreate(entity_manager);
    CDY_Rectangle rect = CDY_CreateRectangle(100, 100, 100, 100);

    int frame_counter = 0;
    Uint64 fps_timer = SDL_GetTicks64();

    /* MAIN ENGINE LOOP START*/
    int running = 1;
    while (running) {
        float target_frame_time = 1000.0f / 60.0f;
        frame_counter++;

        int frame_start_point = SDL_GetTicks64();

        if (SDL_GetTicks64() - fps_timer >= 1000)
        {
            printf("FPS: %d\n", frame_counter);
            frame_counter = 0;
            fps_timer = SDL_GetTicks64();
        }
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
        CDY_DrawRectangle(simple_window, rect);             // draw it
        SDL_RenderFillRect(simple_window->renderer, &rect.rectangle);//present

        CDY_ArmRenderer(simple_window);

        int curr_frame_time = SDL_GetTicks64() - frame_start_point;

        if (curr_frame_time < target_frame_time)
        {
            CDY_Pause(target_frame_time - curr_frame_time);
        }
    }

    /* MAIN ENGINE LOOP END */

    CDY_Close();

    return 0;
}
