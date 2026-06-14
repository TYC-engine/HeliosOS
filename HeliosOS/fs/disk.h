#ifndef DISK_H
#define DISK_H

#include <stdint.h>

int disk_read_sector(
    uint32_t lba,
    void* buffer
);

#endif
