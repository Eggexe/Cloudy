#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
typedef struct CDY_World CDY_World;
// Struct above tells compiler CDY_World exists somewhere
// Cannot include due to circular dependency

// CDY_Entity cast as a 32 bit integer
// Each bit of an entity will be a component
// Masks can be applied to toggle or view components
typedef uint32_t CDY_Entity;

void CDY_EntityInit(CDY_World *world);

#endif
