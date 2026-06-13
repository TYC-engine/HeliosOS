#include "screen.h"
#include "idt.h"

extern void pic_remap();

void kernel_main()
{
    clear_screen();

    print("HeliosOS\n");

    pic_remap();

    idt_init();

    __asm__ volatile("sti");

    print("Interrupts enabled\n");

    while(1)
    {
        __asm__ volatile("hlt");
    }
}
