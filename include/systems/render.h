#ifndef RENDER_H
#define RENDER_H

#include "../../src/registry.c"

typedef struct CDY_Renderer CDY_Renderer;

// SysRenderUpdate will be the primary method for rendering the current frame
// How exactly rendering works will differ in the future, will be updated in the future with more accurate information
void CDY_SysRenderUpdate(CDY_Registry *registry, CDY_Renderer *renderer);

#endif
