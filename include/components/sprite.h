#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>
#include <stdint.h>

typedef struct {
    uint32_t tex_id;
    int src_x, src_y,
    src_w, src_h;
} CDY_SpriteComponent;

#endif
