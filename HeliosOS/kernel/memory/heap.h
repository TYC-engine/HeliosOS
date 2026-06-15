#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

typedef struct heap_block
{
    uint32_t size;
    uint8_t free;

    struct heap_block* next;
    struct heap_block* prev;

} heap_block_t;

void heap_init(uint32_t start, uint32_t size);

void* kmalloc(uint32_t size);
void* kcalloc(uint32_t count, uint32_t size);
void* krealloc(void* ptr, uint32_t size);
void kfree(void* ptr);

uint32_t heap_get_used();
uint32_t heap_get_free();

#endif
