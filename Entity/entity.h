#ifndef ENTITY_H
#define ENTITY_H
typedef struct{
    int id;         // Numeric ID
    int awake;      // Awake or not, used for future time saving
    float posX,     // X position
          posY,     // Y position
          scaleX,   // Width
          scaleY;   // Height
} CDY_Entity;

typedef struct{
    CDY_Entity *entities;       // Stores pointer of all entities
    int CDY_totalEntityCount;   // Current amount of entities
    int CDY_maximumEntities;    // Maximum entity capacity
} CDY_EntityManager;

/* Creates and initialises a new entity manager with a base capacity of 16 entities.
   Either returns a pointer to the manager or returns NULL upon failure */
CDY_EntityManager *CDY_EntityManagerCreate();                                             // init entman

/* Creates a new entity with default values (0) with the manager
 * *manager: Variable name of the created entity manager
 * Will return a pointer to the entity or NULL if manager is full */
CDY_Entity *CDY_EntityCreate(CDY_EntityManager *manager);                   // Adds an entity

/* Marks an entities awake field as 0, inactive.
 * *manager: Variable name of the created entity manager
 * search_id: The ID of the entity to destroy
 * Will return 1 if found and destroyed, 0 if not found. */
int CDY_EntityDestroy(CDY_EntityManager *manager, int search_id);           // Destroys an entity

// Ref NULL returns no point, C_EntCreate needs ref to pointer
// to return the pointer to that new entity

#endif
