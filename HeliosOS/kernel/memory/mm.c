#include "mm.h"

static memory_region_t* g_regions = 0;
static uint32_t g_count = 0;

static uint32_t largest_base = 0;
static uint32_t largest_size = 0;

void mm_init(memory_region_t* regions, uint32_t count)
{
    g_regions = regions;
    g_count = count;

    largest_base = 0;
    largest_size = 0;

    for(uint32_t i = 0; i < count; i++)
    {
        if(regions[i].type == MM_USABLE)
        {
            if(regions[i].length > largest_size)
            {
                largest_size = regions[i].length;
                largest_base = regions[i].base;
            }
        }
    }
}

uint32_t mm_get_largest_usable()
{
    return largest_base;
}

uint32_t mm_get_largest_size()
{
    return largest_size;
}

uint32_t mm_get_total_usable()
{
    uint32_t total = 0;

    for(uint32_t i = 0; i < g_count; i++)
    {
        if(g_regions[i].type == MM_USABLE)
            total += g_regions[i].length;
    }

    return total;
}

memory_region_t* mm_get_regions()
{
    return g_regions;
}

uint32_t mm_get_region_count()
{
    return g_count;
}
