#include "gdi.h"

void gdi_clear(Surface* s, uint32_t color)
{
    for(int y = 0; y < s->height; y++)
    {
        for(int x = 0; x < s->width; x++)
        {
            surface_setpixel(s, x, y, color);
        }
    }
}

void gdi_rect(Surface* s, int x, int y, int w, int h, uint32_t color)
{
    for(int j = y; j < y + h; j++)
    {
        for(int i = x; i < x + w; i++)
        {
            surface_setpixel(s, i, j, color);
        }
    }
}
