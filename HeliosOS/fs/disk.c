include "disk.h"
#include "ata.h"

int disk_read_sector(
    uint32_t lba,
    void* buffer
)
{
    return ata_read28(
        lba,
        (uint8_t*)buffer
    );
}
