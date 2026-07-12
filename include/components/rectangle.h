#ifndef RECTANGLE_H
#define RECTANGLE_H

// Solid colour rectangle data
#include <stdint.h>
typedef struct {
    int w, h;
    int8_t r, g, b, a; // Red Green Blue Alpha
} CDY_RectComponent;

#endif
