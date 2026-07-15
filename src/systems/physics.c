#include "../../include/systems/physics.h"

void CDY_SysPhysicsUpdate(CDY_Registry *registry, float dt) {
    for (int i = 0; i < registry->entity_count; i++)
    {
        // i used as internal ID here
        if (CDY_RegCheckComponent(registry, i, COMPONENT_VELOCITY) && CDY_RegCheckComponent(registry, i, COMPONENT_TRANSFORM) )
        {
            registry->transforms[i].x += registry->velocities[i].vx * dt;
            registry->transforms[i].y += registry->velocities[i].vy * dt;
        }
    }
}
