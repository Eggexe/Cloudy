#ifndef WORLD_H
#define WORLD_H

#include <stdint.h>
#include <stdint.h>
#include "entity/entity.h"
#include "components/transform.h"
#include "components/rectangle.h"
#include "components/sprite.h"
#include "components/velocity.h"

#define CDY_MAX_ENTITIES 64

// Masks for components
// Components are stored into a 32 bit integer
// 0000 <- component-less entity
// 0001 <- entity now has componentX
// 0011 <- entity now has componentX and Y
// |= give component
// &= remove component
// &  check if has component

#define COMPONENT_TRANSFORM (1 << 0) // 0001
#define COMPONENT_VELOCITY  (1 << 1) // 0010
#define COMPONENT_RECTANGLE (1 << 2) // 0100
#define COMPONENT_SPRITE    (1 << 3) // 1000

// Struct holds every engine state
// Entites
// Components
// Component masks
// Given to every system to allow them to read entity data
typedef struct {
    CDY_Entity entities[CDY_MAX_ENTITIES];
    uint32_t component_mask[CDY_MAX_ENTITIES];
    uint32_t entity_count;

    CDY_TransformComponent  transforms[CDY_MAX_ENTITIES];
    CDY_VelocityComponent   velocities[CDY_MAX_ENTITIES];
    CDY_RectComponent       rectangles[CDY_MAX_ENTITIES];
    CDY_SpriteComponent        sprites[CDY_MAX_ENTITIES];
} CDY_World;

void CDY_WldInit(CDY_World *world);

#endif
