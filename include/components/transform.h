#ifndef TRANSFORM_H
#define TRANSFORM_H

// Stores position and size of entity in a 2D environment
// Mostly read only, see velocity.h for movement (potentially changes)
typedef struct {
    float x, y, w, h;
} CDY_TransformComponent;

#endif
