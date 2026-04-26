#ifndef MISC_H
#define MISC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>

void CDY_Pause(float time);
void CDY_Close();


/* FPS MANAGEMENT */
typedef struct {
    int frame_counter;
    Uint64 fps_timer;
    Uint64 frame_start;
    float target_frame_time;
} CDY_FPSManager;

CDY_FPSManager *CDY_FPSManagerCreate(int target_fps);
void CDY_FPSBegin(CDY_FPSManager *fps);
void CDY_FPSEnd(CDY_FPSManager *fps);

/* WARN
 *
 * CODE HERE WILL BE MOVED OUT OF MISC
 * DUE TO SHIT DESIGN
 * WHEN WILL IT BE MOVED?
 * WHO KNOWS
 *
 */

#endif
