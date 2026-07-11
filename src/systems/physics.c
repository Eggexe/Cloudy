#include "../../include/systems/physics.h"

void CDY_SysPhysicsUpdate(CDY_World *world, float dt) {
    for (int i = 0; i < world->entity_count; i++)
    {
        // i used as internal ID here
        if (CDY_WldCheckComponent(world, i, COMPONENT_VELOCITY) == 0
            && CDY_WldCheckComponent(world, i, COMPONENT_TRANSFORM) == 0)
        {
            world->transforms[i].x += world->velocities[i].vx * dt;
            world->transforms[i].y += world->velocities[i].vy * dt;
        }
    }
}
