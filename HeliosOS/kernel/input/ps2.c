#include "ps2.h"
#include "../ports.h"

#define PS2_CMD 0x64
#define PS2_DATA 0x60

void ps2_wait_in()
{
    while(inb(PS2_CMD) & 0x02);
}

void ps2_wait_out()
{
    while(!(inb(PS2_CMD) & 0x01));
}

void ps2_write(uint8_t data)
{
    ps2_wait_in();
    outb(PS2_DATA, data);
}

uint8_t ps2_read()
{
    ps2_wait_out();
    return inb(PS2_DATA);
}

void ps2_init()
{
    // disable devices
    ps2_wait_in();
    outb(PS2_CMD, 0xAD);

    ps2_wait_in();
    outb(PS2_CMD, 0xA7);

    // flush buffer
    ps2_read();

    // enable interrupts
    ps2_wait_in();
    outb(PS2_CMD, 0x20);

    uint8_t status = ps2_read();
    status |= 0x02;

    ps2_wait_in();
    outb(PS2_CMD, 0x60);
    ps2_write(status);

    // enable mouse
    ps2_wait_in();
    outb(PS2_CMD, 0xA8);

    // set defaults
    ps2_wait_in();
    outb(PS2_CMD, 0xD4);
    ps2_write(0xF6);

    ps2_read(); // ACK

    // enable streaming
    ps2_wait_in();
    outb(PS2_CMD, 0xD4);
    ps2_write(0xF4);

    ps2_read(); // ACK
}
