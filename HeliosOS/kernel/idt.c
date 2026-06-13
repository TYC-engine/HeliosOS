#include "idt.h"

extern void isr0();
extern void irq0();
extern void irq1();

static idt_entry_t idt[256];
static idt_ptr_t idtp;

static void idt_set_gate(
    int num,
    uint32_t base,
    uint16_t sel,
    uint8_t flags)
{
    idt[num].offset_low = base & 0xFFFF;
    idt[num].selector = sel;
    idt[num].zero = 0;
    idt[num].flags = flags;
    idt[num].offset_high = base >> 16;
}

void idt_init()
{
    idtp.limit = sizeof(idt)-1;
    idtp.base = (uint32_t)&idt;

    idt_set_gate(0,(uint32_t)isr0,0x08,0x8E);

    idt_set_gate(32,(uint32_t)irq0,0x08,0x8E);
    idt_set_gate(33,(uint32_t)irq1,0x08,0x8E);

    __asm__ volatile("lidt %0" : : "m"(idtp));
}
