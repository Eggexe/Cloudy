#include "entity.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

CDY_EntityManager *CDY_EntityManagerCreate() {
    CDY_EntityManager *entMan = malloc(sizeof(CDY_EntityManager));
    // create entity manager (entman) and allocate some memory for it to use
    entMan -> CDY_maximumEntities = 16; // inside of CDY_EntityManager, set entMan's max entity count to 16
    entMan -> CDY_totalEntityCount = 0; // as above, no current entities yet

    entMan -> entities = malloc(sizeof(CDY_Entity) * entMan->CDY_maximumEntities);
    // allocate a lot more memory for entities themselves
    // little bunch for entMan creation
    // more memory for entities
    return entMan;
}

CDY_Entity *CDY_EntityCreate(CDY_EntityManager *manager) {
    if (manager->CDY_totalEntityCount >= manager->CDY_maximumEntities){
        return NULL;
    }

    CDY_Entity *entity = &manager->entities[manager->CDY_totalEntityCount];
    entity->id = manager->CDY_totalEntityCount;
    manager->CDY_totalEntityCount++;
    return entity;

    // USAGE
    // CDY_Entity *entityName = CDY_EntityCreate(manager);
}

int CDY_EntityDestroy(CDY_EntityManager *manager, int search_id){
    printf("Discontinued");
}
