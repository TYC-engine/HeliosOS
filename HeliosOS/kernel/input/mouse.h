#ifndef MOUSE_H
#define MOUSE_H

#include <stdint.h>

typedef struct
{
    int x;
    int y;

    int left;
    int right;
    int middle;

    int dx;
    int dy;

    int packet_phase;
    uint8_t packet[3];

} MouseState;

void mouse_init();
void mouse_irq_handler(uint8_t data);

MouseState* mouse_get();

#endif
