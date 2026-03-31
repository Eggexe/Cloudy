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

// TODO:
// Store CDY_Entity as a list of entities with a pointer towards the entities
// prolly have a current count of entities
// with an upper bound for rate limits

#endif
