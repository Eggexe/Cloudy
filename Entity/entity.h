#ifndef ENTITY_H
#define ENTITY_H

typedef struct{
    int id;     // Numeric ID
    int awake;  // Awake or not, used for future time saving
    float posX, // Used to save the position and scale of said CDY_Entity
          posY,
          scaleX,
          scaleY;
    float rotation; // -360 to +360
} CDY_Entity;

typedef struct{
    CDY_Entity *entities;
    int CDY_totalEntityCount;
    int CDY_entityMaximum;
} CDY_EntityManager;

#endif
