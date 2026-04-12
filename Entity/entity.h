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
    int CDY_maximumEntities;
} CDY_EntityManager;

void CDY_EntityManagerCreate();                             // init entman
CDY_Entity *CDY_EntityCreate(CDY_EntityManager *manager);   // Adds an entity
void CDY_EntityDestroy(CDY_EntityManager *manager);         // Destroys an entity
void CDY_EntityManagerDestroy();                            // Destroys entman, frees memory
void CDY_EntityManagerUpdate();                             // Updates live list of entities

// Ref NULL returns no point, C_EntCreate needs ref to pointer
// to return the pointer to that new entity

#endif
