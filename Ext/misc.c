#include "misc.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void CDY_Pause(float time) {
    SDL_Delay(time);
}


void CDY_Close() {
    SDL_Quit();
}

/* Sets target FPS
 * Target FPS converted to ms each frame takes
 */
CDY_FPSManager *CDY_FPSManagerCreate(int target_fps) {
    CDY_FPSManager *fps = malloc(sizeof(CDY_FPSManager));
    fps->target_frame_time = 1000.0f / target_fps;
    fps->frame_counter = 0;
    fps->fps_timer = SDL_GetTicks64();
    fps->frame_start = 0;
    return fps;
}

/* Stamp the start of each frame and start counting */
void CDY_FPSBegin(CDY_FPSManager *fps) {
    fps->frame_start = SDL_GetTicks64();
    fps->frame_counter++;
    if (SDL_GetTicks64() - fps->fps_timer >= 1000) {
        printf("FPS: %d\n", fps->frame_counter);
        fps->frame_counter = 0;
        fps->fps_timer = SDL_GetTicks64();
    }
}

/* Then figure out how long each frame took
 * Delay if we went too fast, don't if we didn't
 */
void CDY_FPSEnd(CDY_FPSManager *fps) {
    int curr_frame_time = SDL_GetTicks64() - fps->frame_start;
    if (curr_frame_time < fps->target_frame_time) {
        SDL_Delay(fps->target_frame_time - curr_frame_time);
    }
}
