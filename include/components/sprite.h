#ifndef SPRITE_H
#define SPRITE_H

#include <stdint.h>

// Ensure to add a definition for this later, I havent used it yet as im focusing on rectangles atm so ill add instructions in a bit
typedef struct {
    uint32_t tex_id;
    int src_x, src_y,
    src_w, src_h;
} CDY_SpriteComponent;

#endif
