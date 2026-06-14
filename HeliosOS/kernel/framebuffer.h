#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

typedef struct
{
    uint32_t* address;
    int width;
    int height;
    int pitch;
    int bpp;
} Framebuffer;

void fb_init(uint32_t* addr, int w, int h, int pitch, int bpp);

Framebuffer* fb_get();

void fb_putpixel(int x, int y, uint32_t color);
void fb_clear(uint32_t color);

#endif
