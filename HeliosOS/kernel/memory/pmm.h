#ifndef PMM_H
#define PMM_H

#include <stdint.h>

#define PAGE_SIZE 4096

void pmm_init(uint32_t memory_size);
void pmm_mark_region(uint32_t base, uint32_t size, uint8_t used);

uint32_t pmm_alloc_page();
void pmm_free_page(uint32_t page);

uint32_t pmm_get_total_pages();
uint32_t pmm_get_used_pages();

#endif
