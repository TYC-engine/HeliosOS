#include "idt.h"

extern void isr0();
extern void isr1();
extern void irq0();
extern void irq1();

static idt_entry_t idt[256];
static idt_ptr_t idtp;

static void set_gate(int n, uint32_t handler)
{
    idt[n].low = handler & 0xFFFF;
    idt[n].sel = 0x08;
    idt[n].zero = 0;
    idt[n].flags = 0x8E;
    idt[n].high = handler >> 16;
}

void idt_init()
{
    set_gate(32, (uint32_t)irq0);  // timer
    set_gate(33, (uint32_t)irq1);  // keyboard
    set_gate(44, (uint32_t)irq12); // mouse
}
