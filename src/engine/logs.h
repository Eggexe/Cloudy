#ifndef LOGS_H
#define LOGS_H

typedef enum {
    // --- WARN (1000s) ---
    CDY_WARN_MISSING_COMPONENT          = 1001,
    CDY_WARN_INVALID_ENTITY_ID          = 1002,
    CDY_WARN_COMPONENT_ALREADY_SET      = 1003,
    CDY_WARN_COMPONENT_NOT_SET          = 1004,
    CDY_WARN_ENTITY_ALREADY_DESTROYED   = 1005,
    CDY_WARN_ENTITY_NO_COMPONENTS       = 1006,

    // --- ERROR (2000s) ---
    CDY_ERR_ENTITY_LIMIT_REACHED        = 2001,
    CDY_ERR_TEXTURE_LOAD_FAILED         = 2002,
    CDY_ERR_FONT_LOAD_FAILED            = 2003,
    CDY_ERR_NULL_POINTER                = 2004,

    // --- FATAL (3000s) ---
    CDY_FATAL_SDL_INIT_FAILED           = 3001,
    CDY_FATAL_WINDOW_INIT_FAILED        = 3002,
    CDY_FATAL_RENDERER_INIT_FAILED      = 3003,
    CDY_FATAL_REGISTRY_INIT_FAILED      = 3004,
} CDY_LogCode;

void CDY_LogCodeToNormalString(CDY_LogCode code);

#endif
