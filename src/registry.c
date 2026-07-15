#include "../include/registry.h"
#include <string.h>

// Sets CDY_Registry to 0, clears the registry for use
// Has to be run at the start of program!
void CDY_RegInit(CDY_Registry *registry) {
    memset(registry, 0, sizeof(CDY_Registry));
}

int CDY_RegCreateEntity(CDY_Registry *registry) {
    if (registry->entity_count >= CDY_MAX_ENTITIES) return -1;

    CDY_Entity id = registry->entity_count;
    registry->entities[id] = id;
    registry->entity_count++;
    return id;
}

int CDY_RegDestroyEntity(CDY_Registry *registry, int id) {
    if (id >= registry->entity_count || id < 0) return -1;
    else { registry->component_mask[id] = 0; return 0;}
}

int CDY_RegAddComponent(CDY_Registry *registry, int ent_id, uint32_t component) {
    if (ent_id >= registry->entity_count || ent_id < 0) return -1;
    else {registry->component_mask[ent_id] |= component; return 0;}
}

int CDY_RegCheckComponent(CDY_Registry *registry, int ent_id, uint32_t component) {
    if (ent_id >= registry->entity_count || ent_id < 0) return -1;
    else return registry->component_mask[ent_id] & component;
}

int CDY_RegRemoveComponent(CDY_Registry *registry, int ent_id, uint32_t component) {
    if (ent_id >= registry->entity_count || ent_id < 0) return -1;
    else {registry->component_mask[ent_id] &= ~component; return 0;}
}
