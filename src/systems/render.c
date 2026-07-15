#include "../../include/systems/render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <sys/types.h>

// Reminder for future use SDL only found internally (in /src) hence the struct in render.h to abstract SDL stuff

typedef struct CDY_Renderer{
    SDL_Renderer *renderer;
} CDY_Renderer;

void CDY_SysRenderUpdate(CDY_Registry *registry, CDY_Renderer *renderer) {

}
