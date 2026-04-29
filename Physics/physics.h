#ifndef PHYSICS_H
#define PHYSICS_H

#include "../Entity/entity.h"

// Takes an entity variable and an x and y coordinate
// Will add to the entity's x and y coordinates and
// Returns the position
void CDY_TranslateEntity(CDY_Entity *entity, float x, float y);

// Checks if entity1 overlaps with entity2
// Returns 1 if overlap
// Returns 0 if no overlap
int CDY_AABBCollide(CDY_Entity *entity1, CDY_Entity *entity2);

#endif
