#include "../../include/systems/physics.h"

// SysPhysicsUpdate requires both transform and velocity to read from and write to
// It reads the velocity component and updates the entity transform by that much * dt

void CDY_SysPhysicsUpdate(CDY_World *world, float dt) {
    for (int i = 0; i < world->entity_count; i++)
    {
        // i used as internal ID here
        if (CDY_WldCheckComponent(world, i, COMPONENT_VELOCITY) && CDY_WldCheckComponent(world, i, COMPONENT_TRANSFORM) )
        {
            world->transforms[i].x += world->velocities[i].vx * dt;
            world->transforms[i].y += world->velocities[i].vy * dt;
        }
    }
}
