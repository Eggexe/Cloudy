#ifndef MISC_H
#define MISC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>

// Pauses the current loop with time in ms
void CDY_Pause(float time);

// Closes the engine, good to have at the end of the main function
void CDY_Close();


/* FPS MANAGEMENT */

// Holds information regarding FPS tracking
typedef struct {
    int frame_counter;
    Uint64 fps_timer;
    Uint64 frame_start;
    float target_frame_time;
} CDY_FPSManager;

// Does fancy maths with the integer passed to reach that target FPS
CDY_FPSManager *CDY_FPSManagerCreate(int target_fps);


// FPSBegin and FPSEnd is not required to be used
// These are tracking functions, FPSManger is the only key function
// Starts FPS tracking
void CDY_FPSBegin(CDY_FPSManager *fps);
// Ends FPS tracking
void CDY_FPSEnd(CDY_FPSManager *fps);

// Code within this file will be moved to a more specialised
// location at some point

#endif
