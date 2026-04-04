#include "entity.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

void CDY_EntityManagerCreate() {
    CDY_EntityManager *entMan = malloc(sizeof(CDY_EntityManager));
    // create entity manager (entman) and allocate some memory for it to use
    entMan -> CDY_maximumEntities = 16; // inside of CDY_EntityManager, set entMan's max entity count to 16
    entMan -> CDY_totalEntityCount = 0; // as above, no current entities yet

    entMan -> entities = malloc(sizeof(CDY_Entity) * entMan->CDY_totalEntityCount);
    // allocate a lot more memory for entities themselves
    // little bunch for entMan creation
    // more memory for entities
}
