#include "ports.h"

extern void keyboard_irq();

void isr_handler()
{
    for(;;);
}

void irq_handler()
{
    unsigned int irq;

    __asm__ volatile("mov 4(%%esp), %0"
        : "=r"(irq));

    if(irq==33)
        keyboard_irq();

    outb(0x20,0x20);
}
