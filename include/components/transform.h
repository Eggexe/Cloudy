#ifndef TRANSFORM_H
#define TRANSFORM_H

// Stores position, size and rotation of an entity in 2D space.
// CDY_TransformComponent acts as a global position store for entities. This component is typically required for entities to make them move.
typedef struct {
    float x, y;
    float w, h;
    float rotation;
} CDY_TransformComponent;

#endif
