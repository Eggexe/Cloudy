#include "../include/world.h"
#include <string.h>

// Sets CDY_World to 0, clears the world for use
// Has to be run at the start of program!
void CDY_WldInit(CDY_World *world) {
    memset(world, 0, sizeof(CDY_World));
}
