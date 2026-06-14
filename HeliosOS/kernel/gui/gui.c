#include "gui.h"
#include "../gfx/compositor.h"
#include <stdlib.h>

#define MAX_WINDOWS 32

static Window* windows[MAX_WINDOWS];
static int window_count = 0;

void gui_init()
{
    window_count = 0;
}

void gui_add_window(Window* win)
{
    if(window_count < MAX_WINDOWS)
        windows[window_count++] = win;
}

void gui_render()
{
    Surface desktop = surface_create(1024, 768);

    gdi_clear(&desktop, 0x101010);

    for(int i = 0; i < window_count; i++)
    {
        Window* w = windows[i];

        window_draw(w);

        for(int y = 0; y < w->h; y++)
        {
            for(int x = 0; x < w->w; x++)
            {
                int dx = w->x + x;
                int dy = w->y + y;

                surface_setpixel(
                    &desktop,
                    dx, dy,
                    w->buffer[y * w->w + x]
                );
            }
        }
    }

    compositor_present(&desktop);
}
