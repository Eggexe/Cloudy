#ifndef UI_H
#define UI_H
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_ttf.h>
#include "../Render/simple_window.h"

typedef struct {
    TTF_Font *font;
} CDY_Font;

CDY_Font *CDY_FontLoadCustom(const char *path, int size);
CDY_Font *CDY_FontLoadDefault(int size);

void CDY_DrawText(CDY_Simple_Window *window, CDY_Font *font,
                const char *text, int x, int y,
                Uint8 r, Uint8 g, Uint8 b);
void CDY_FontDestroy(CDY_Font *font);

#endif
