#ifndef PHYSICS_H
#define PHYSICS_H

#include "../../src/registry.c"

// SysPhysicsUpdate requires both transform and velocity to read from and write to
// It reads the velocity component and updates the entity transform by that much * dt
void CDY_SysPhysicsUpdate(CDY_Registry *registry, float dt);

#endif
