#include "ui.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

CDY_Font *CDY_FontLoadDefault(int size) {
    return CDY_FontLoadCustom("Cloudy/Assets/Font/CloudyDefaultPS2P.ttf", size);
}

CDY_Font *CDY_FontLoadCustom(const char *path, int size) {
    // Give CDY_Font memory, useful to free memory for destruction
    CDY_Font *font = malloc(sizeof(CDY_Font));
    font->font = TTF_OpenFont(path, size);// TTF thing to open font
    // check if there is no font and throw error
    if (font->font == NULL)
    {
        printf("Font loading error: %s\n", TTF_GetError());
        return NULL;
    }
    return font;
}

void CDY_DrawText(CDY_Simple_Window *window,
                  CDY_Font *font, const char *text,
                  int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Color colour = {r, g, b, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font->font, text, colour);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(window->renderer, surface);
    SDL_Rect dst = {x,y, surface->w, surface->h};
    // TTF's weird ass pipeline
    // Surface -> Texture -> Draw the thing -> Destroy the thing

    SDL_RenderCopy(window->renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void CDY_FontDestroy(CDY_Font *font)
{
    TTF_CloseFont(font->font);
    free(font);
}
