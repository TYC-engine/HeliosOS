#include "fat32.h"
#include "disk.h"

static FAT32_BPB bpb;

uint32_t fat_start;
uint32_t data_start;

int fat32_init()
{
    if(disk_read_sector(
        0,
        &bpb
    ) != 0)
    {
        return -1;
    }

    fat_start =
        bpb.reserved_sectors;

    data_start =
        bpb.reserved_sectors +
        (
            bpb.fat_count *
            bpb.fat_size32
        );

    return 0;
}
