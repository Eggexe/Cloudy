#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

// CDY_Entity cast as a 32 bit integer
// Each bit of an entity will be a component
// Masks can be applied to toggle or view components
typedef uint32_t CDY_Entity;

#endif
