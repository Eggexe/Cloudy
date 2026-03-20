#include "Render/misc.h"
#include "Render/simple_window.h"
#include "Render/drawing.h"

int main(void) {

    CDY_Simple_Window *simple_window = CDY_SimpleWindowCreate("yes", 250, 250);

    CDY_ColorRenderer(simple_window->renderer, 100, 0, 0, 255);
    CDY_WipeRenderer(simple_window->renderer);
    CDY_ArmRenderer(simple_window->renderer);

    CDY_Pause(2000);
    CDY_Close();

    return 0;
}
