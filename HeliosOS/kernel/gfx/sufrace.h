#ifndef SURFACE_H
#define SURFACE_H

#include <stdint.h>

typedef struct
{
    int width;
    int height;
    uint32_t* buffer;
} Surface;

Surface surface_create(int w, int h);
void surface_setpixel(Surface* s, int x, int y, uint32_t color);

#endif
