#ifndef VELOCITY_H
#define VELOCITY_H

// CDY_VelocityComponent is used in conjunction with CDY_TransformComponent to allow for movement.
// Ensure both components are applied to an entity before moving.
typedef struct {
    float vx, vy;
} CDY_VelocityComponent;

#endif
