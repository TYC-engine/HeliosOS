#include "screen.h"
#include "idt.h"
#include "pit.h"
#include "keyboard.h"
#include "memory/mm.h"
#include "memory/pmm.h"
#include "memory/heap.h"
#include "input/mouse.h"
#include "gfx/framebuffer.h"

extern uint32_t kernel_end;

static int mouse_x = 320;
static int mouse_y = 240;

static void draw_cursor(int x, int y)
{
    // простой крестик
    put_pixel(x, y, 0xFFFFFF);
    put_pixel(x+1, y, 0xFFFFFF);
    put_pixel(x-1, y, 0xFFFFFF);
    put_pixel(x, y+1, 0xFFFFFF);
    put_pixel(x, y-1, 0xFFFFFF);
}

void mouse_handler(int dx, int dy, int buttons)
{
    mouse_x += dx;
    mouse_y -= dy;

    if(mouse_x < 0) mouse_x = 0;
    if(mouse_y < 0) mouse_y = 0;
    if(mouse_x > 639) mouse_x = 639;
    if(mouse_y > 479) mouse_y = 479;
}

void kernel_main()
{
    clear_screen();

    print("HeliosOS starting GUI...\n");

    // =========================
    // MEMORY INIT (MM + PMM)
    // =========================
    // fake memory map (bootloader должен передавать)
    memory_region_t regions[1];
    regions[0].base = 0x100000;
    regions[0].length = 32 * 1024 * 1024;
    regions[0].type = 1;

    mm_init(regions, 1);

    pmm_init(32 * 1024 * 1024);
    pmm_mark_region(0, 0x100000, 1); // kernel reserved
    pmm_mark_region(0x100000, 32 * 1024 * 1024, 0);

    // =========================
    // PAGING (identity map)
    // =========================
    paging_init();

    // =========================
    // HEAP
    // =========================
    heap_init(
        (uint32_t)&kernel_end,
        4 * 1024 * 1024
    );

    // =========================
    // INTERRUPTS
    // =========================
    idt_init();
    pit_init();

    mouse_init();

    __asm__ volatile("sti");

    print("GUI running...\n");

    // =========================
    // MAIN LOOP
    // =========================
    while(1)
    {
        clear_screen();

        draw_cursor(mouse_x, mouse_y);

        __asm__ volatile("hlt");
    }
}
