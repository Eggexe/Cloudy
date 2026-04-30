# Cloudy Documentation: How to use

---

## Window creation
Creates a window and a renderer.    
`CDY_Simple_Window *simple_window = CDY_SimpleWindowCreate("Title", 640, 480);`  
  
- Title: Name of the window as a string
- Width/Height in pixels
- Returns NULL if fails

### Extra Window Functions

Clear the renderer each frame. 
- Typically used to clear the currently drawn frame and sets up a clean render for a new one. 

`CDY_WipeRenderer(simple_window)`    

Set the draw colour for the next draw call.
- Must be called before `CDY_WipeRenderer` to set the background colour, and before any draw call to set the colour of what is being drawn.
- r, g, b, a are values from 0-255

`CDY_ColorRenderer(simple_window, r, g, b, a)`

Present the current frame to the screen.
- Call this at the end of every frame after all drawing is done.

`CDY_ArmRenderer(simple_window)`

Destroy the window and clean up SDL and SDL_ttf.
- Call this when the game exits.

`CDY_SimpleWindowDestroy(simple_window)`

---

## Entity System
Entities are game objects that live inside an Entity Manager. The manager holds a fixed pool of 16 entities in memory. Entities are not individually allocated, they occupy pre-allocated slots.

Create an Entity Manager before creating any entities. All entities belong to a manager.

`CDY_EntityManager *entity_manager = CDY_EntityManagerCreate();`

- Allocates a manager and a pool of 16 entity slots
- Returns NULL if fails

### Creating Entities

`CDY_Entity *player = CDY_EntityCreate(entity_manager);`

- Grabs the next free slot in the manager's pool
- Assigns a unique ID and sets awake to 1
- All position, scale and rotation values default to 0
- Returns NULL if the manager is full

### Entity Fields

After creating an entity, set its fields directly:

```c
player->posX = 100;      // x position
player->posY = 200;      // y position
player->scaleX = 50;     // width
player->scaleY = 50;     // height
player->rotation = 0;    // rotation in degrees
```

### Destroying Entities

Marks an entity as inactive by awake state. This does not free memory however, the slot remains in use.

`CDY_EntityDestroy(entity_manager, player->id);`

- search_id: the ID of the entity to deactivate
- Returns 1 if found, 0 if not found

---

## Drawing Entities

Draw an entity to the screen as a filled rectangle. Must be called between `CDY_WipeRenderer` and `CDY_ArmRenderer`.
- Set the draw colour with `CDY_ColorRenderer` before calling this.
- Uses the entity's posX, posY, scaleX and scaleY fields for position and size.

`CDY_DrawEntity(simple_window, player);`

---

## Input Manager
The input manager tracks the state of the keyboard every frame. Create it once before the game loop.

`CDY_InputManager *input_manager = CDY_InputManagerCreate();`

### Updating Input

Call this every frame inside the game loop before checking any key states.

`CDY_UpdateInput(input_manager);`

### Checking Key State

Returns 1 if the key is currently held down, 0 if not.

`CDY_IsKeyHeld(input_manager, CDY_KEY_W);`

### Available Keys

| Key Constant | Key |
|---|---|
| `CDY_KEY_W` | W |
| `CDY_KEY_S` | S |
| `CDY_KEY_UP` | Up arrow |
| `CDY_KEY_DOWN` | Down arrow |
| `CDY_KEY_SPACE` | Space |
| `CDY_KEY_ESCAPE` | Escape |

---

## Event System
The event system abstracts SDL events so game code never touches SDL directly. Poll for events inside the game loop.

```c
CDY_Event event;
while (CDY_PollEvent(&event)) {
    if (event.type == CDY_EVENT_QUIT) running = 0;
}
```

### Available Event Types

| Event Constant | Description |
|---|---|
| `CDY_EVENT_QUIT` | Window close button pressed |
| `CDY_EVENT_KEYDOWN` | A key was pressed |
| `CDY_EVENT_KEYUP` | A key was released |
| `CDY_EVENT_NONE` | No recognised event |

---

## Physics

### Translation
Moves an entity by a given amount each time it is called. Use inside the game loop to move entities each frame.

`CDY_TranslateEntity(entity, x, y);`

- x: amount to move on the x axis (negative moves left)
- y: amount to move on the y axis (negative moves up)

### AABB Collision
Checks if two entities overlap using Axis-Aligned Bounding Box detection. Returns 1 if colliding, 0 if not.

`CDY_AABBCollide(entity1, entity2);`

- Compares the bounding boxes of both entities using their posX, posY, scaleX and scaleY fields
- Typically used inside the game loop each frame

Example usage:
```c
if (CDY_AABBCollide(ball, paddle)) {
    ballSpeedX *= -1; // reverse ball direction
}
```

---

## FPS Manager
Controls the frame rate of the game loop. Create once before the loop and call begin and end each frame.

`CDY_FPSManager *fps = CDY_FPSManagerCreate(60);`

- target_fps: the desired frames per second

Call at the very start of each frame:

`CDY_FPSBegin(fps);`

Call at the very end of each frame:

`CDY_FPSEnd(fps);`

- Calculates how long the frame took and delays the remainder to hit the target frame time
- Prints FPS to the console once per second

---

## UI / Text Rendering
Text rendering uses SDL_ttf under the hood. Load a font once before the game loop and draw text each frame.

### Loading a Font

Load the built-in Cloudy default font (Press Start 2P) at a given size:

`CDY_Font *font = CDY_FontLoadDefault(32);`

- size: point size of the font
- Returns NULL if the font file cannot be found

Load a custom font from a file path:

`CDY_Font *font = CDY_FontLoadCustom("path/to/font.ttf", 32);`

### Drawing Text

Draw a string at a given position and colour. Call inside the render section of the game loop.

`CDY_DrawText(simple_window, font, "Hello", x, y, r, g, b);`

- text: the string to display
- x, y: position on screen in pixels
- r, g, b: text colour (0-255 each)

To display dynamic values like a score, convert integers to strings first:
```c
char score_text[16];
sprintf(score_text, "%d", score);
CDY_DrawText(simple_window, font, score_text, 100, 10, 255, 255, 255);
```

### Destroying a Font

Free the font when the game exits:

`CDY_FontDestroy(font);`

---

## Misc / Utility

Pause execution for a given number of milliseconds:

`CDY_Pause(2000);`

Quit SDL and clean up. Call at the end of the program:

`CDY_Close();`

---

## Full Game Loop Template

```c
#include "Cloudy/Entity/entity.h"
#include "Cloudy/Input/input_man.h"
#include "Cloudy/Ext/misc.h"
#include "Cloudy/Events/events.h"
#include "Cloudy/Render/simple_window.h"
#include "Cloudy/Render/drawing.h"
#include "Cloudy/Physics/physics.h"
#include "Cloudy/UI/ui.h"

int main(int argc, char *argv[]) {
    /* ENGINE INSTANCES */
    CDY_Simple_Window *window   = CDY_SimpleWindowCreate("My Game", 640, 480);
    CDY_InputManager  *input    = CDY_InputManagerCreate();
    CDY_EntityManager *entities = CDY_EntityManagerCreate();
    CDY_FPSManager    *fps      = CDY_FPSManagerCreate(60);
    CDY_Font          *font     = CDY_FontLoadDefault(24);

    /* CREATE ENTITIES */
    CDY_Entity *player = CDY_EntityCreate(entities);
    player->posX   = 100;
    player->posY   = 100;
    player->scaleX = 50;
    player->scaleY = 50;

    /* GAME LOOP */
    int running = 1;
    while (running) {
        CDY_FPSBegin(fps);

        /* EVENTS */
        CDY_Event event;
        while (CDY_PollEvent(&event)) {
            if (event.type == CDY_EVENT_QUIT) running = 0;
        }

        /* INPUT */
        CDY_UpdateInput(input);
        if (CDY_IsKeyHeld(input, CDY_KEY_W)) CDY_TranslateEntity(player, 0, -5);
        if (CDY_IsKeyHeld(input, CDY_KEY_S)) CDY_TranslateEntity(player, 0,  5);

        /* RENDER */
        CDY_ColorRenderer(window, 0, 0, 0, 255);
        CDY_WipeRenderer(window);
        CDY_ColorRenderer(window, 255, 255, 255, 255);
        CDY_DrawEntity(window, player);
        CDY_DrawText(window, font, "My Game", 10, 10, 255, 255, 255);
        CDY_ArmRenderer(window);

        CDY_FPSEnd(fps);
    }

    CDY_SimpleWindowDestroy(window);
    CDY_FontDestroy(font);
    CDY_Close();
    return 0;
}
```
