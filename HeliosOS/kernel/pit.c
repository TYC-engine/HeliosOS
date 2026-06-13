#include "ports.h"

static unsigned int ticks = 0;

void pit_handler()
{
    ticks++;
}

unsigned int pit_ticks()
{
    return ticks;
}

void pit_init()
{
    unsigned short divisor = 11931;

    outb(0x43, 0x36);

    outb(0x40, divisor & 0xFF);
    outb(0x40, divisor >> 8);
}
