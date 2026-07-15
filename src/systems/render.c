#include "../../include/systems/render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

// Reminder for future use SDL only found internally (in /src) hence the struct in render.h to abstract SDL stuff

typedef struct CDY_Renderer{
    SDL_Renderer *renderer;
} CDY_Renderer;

void CDY_SysRenderUpdate(CDY_Registry *registry, CDY_Renderer *renderer) {
    for (uint32_t i = 0; i < registry->entity_count; i++)
    {
        // BOTH CDY_RectComponent and CDY_TransformComponent are required to do this specific operation
        // Ensure that the entity has both these components
        // Fear not if they don't, they will be skipped over by this check and the game (should) proceed without errors
        // yo why am i typing notes for developers ur not supposed to see this js go read the documentation whenever i get to writing it

        if (CDY_RegCheckComponent(registry, i, COMPONENT_TRANSFORM) && CDY_RegCheckComponent(registry, i, COMPONENT_RECTANGLE))
        {
            SDL_Rect r;
            // Transforms hold positions
            r.x = registry->transforms[i].x;
            r.y = registry->transforms[i].y;

            // Rect holds the width and height
            r.h = registry->rectangles[i].h;
            r.w = registry->rectangles[i].w;
        }
        // TODO: give rect colours
    }
}
