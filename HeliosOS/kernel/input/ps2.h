#ifndef PS2_H
#define PS2_H

#include <stdint.h>

void ps2_init();
void ps2_write(uint8_t data);
uint8_t ps2_read();

#endif
