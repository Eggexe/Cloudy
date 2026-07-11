#ifndef RENDER_H
#define RENDER_H

#include "../../src/world.c"

typedef struct CDY_Renderer CDY_Renderer;

void CDY_SysRenderUpdate(CDY_World *world, CDY_Renderer *renderer);

#endif RENDER_H
