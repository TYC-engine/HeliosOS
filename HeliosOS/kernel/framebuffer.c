#include "framebuffer.h"

static Framebuffer fb;

void fb_init(uint32_t* addr, int w, int h, int pitch, int bpp)
{
    fb.address = addr;
    fb.width = w;
    fb.height = h;
    fb.pitch = pitch;
    fb.bpp = bpp;
}

Framebuffer* fb_get()
{
    return &fb;
}

void fb_putpixel(int x, int y, uint32_t color)
{
    if(x < 0 || y < 0 || x >= fb.width || y >= fb.height)
        return;

    fb.address[y * fb.width + x] = color;
}

void fb_clear(uint32_t color)
{
    for(int y = 0; y < fb.height; y++)
    {
        for(int x = 0; x < fb.width; x++)
        {
            fb.address[y * fb.width + x] = color;
        }
    }
}
