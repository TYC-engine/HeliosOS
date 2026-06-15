#ifndef MM_H
#define MM_H

#include <stdint.h>

#define MM_USABLE   1
#define MM_RESERVED 2

typedef struct
{
    uint32_t base;
    uint32_t length;
    uint32_t type;
} memory_region_t;

void mm_init(memory_region_t* regions, uint32_t count);

uint32_t mm_get_largest_usable();
uint32_t mm_get_largest_size();
uint32_t mm_get_total_usable();

memory_region_t* mm_get_regions();
uint32_t mm_get_region_count();

#endif
