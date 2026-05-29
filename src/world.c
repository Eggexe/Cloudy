#include "../include/world.h"
#include <string.h>

// Sets CDY_World to 0, clears the world for use
// Has to be run at the start of program!
void CDY_WldInit(CDY_World *world) {
    memset(world, 0, sizeof(CDY_World));
}

int CDY_WldCreateEntity(CDY_World *world) {
    if (world->entity_count >= CDY_MAX_ENTITIES) return -1;

    CDY_Entity id = world->entity_count;
    world->entities[id] = id;
    world->entity_count++;
    return id;
}

int CDY_WldDestroyEntity(CDY_World *world, int id) {
    if (id >= world->entity_count || id < 0) return -1;
    else { world->component_mask[id] = 0; return 0;}
}
