#ifndef PHYSICS_H
#define PHYSICS_H

#include "../Entity/entity.h"

void CDY_TranslateEntity(CDY_Entity *entity, float x, float y);
int CDY_AABBCollide(CDY_Entity *entity1, CDY_Entity *entity2);
/* TODO: Collision will change at a later date
 * This is specifically for pong's design
 */

#endif
