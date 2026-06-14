#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

typedef struct Window
{
    int x, y;
    int w, h;

    uint32_t* buffer;

    char title[32];

    int visible;
} Window;

Window* window_create(int x, int y, int w, int h, const char* title);

void window_draw(Window* win);
void window_move(Window* win, int x, int y);

#endif
