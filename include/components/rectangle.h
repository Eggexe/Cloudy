#ifndef RECTANGLE_H
#define RECTANGLE_H

// Solid colour rectangle data
#include <stdint.h>

// CDY_RectComponent holds only a local width and height for the rectangle
// with an RGBA value too.
// GLOBAL position for the rectangle should be found in a CDY_TransformComponent.
// Ensure both are applied to an entity to allow it to move.
typedef struct {
    int w, h;
    int8_t r, g, b, a; // Red Green Blue Alpha
} CDY_RectComponent;

#endif
