#include "ports.h"

static unsigned int ticks = 0;

void pit_irq()
{
    ticks++;
}

unsigned int pit_get_ticks()
{
    return ticks;
}

void pit_init()
{
    unsigned int divisor = 1193180 / 100;

    outb(0x43, 0x36);

    outb(0x40, divisor & 0xFF);
    outb(0x40, (divisor >> 8) & 0xFF);
}
