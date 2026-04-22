#include "physics.h"
#include "../Entity/entity.h"

void CDY_TranslateEntity(CDY_Entity *entity, float x, float y){
    entity->posX += x;
    entity->posY += y;
}
