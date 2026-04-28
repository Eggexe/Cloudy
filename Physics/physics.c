#include "physics.h"
#include "../Entity/entity.h"

void CDY_TranslateEntity(CDY_Entity *entity, float x, float y){
    entity->posX += x;
    entity->posY += y;
}

int CDY_AABBCollide(CDY_Entity *entity1, CDY_Entity *entity2){
    if (entity1->posX < entity2->posX + entity2->scaleX &&
        entity1->posX + entity1->scaleX > entity2->posX &&
        entity1->posY < entity2->posY + entity2->scaleY &&
        entity1->posY + entity1->scaleY > entity2->posY)
    {
        return 1;
    }
    else{
        return 0;
    }
}
