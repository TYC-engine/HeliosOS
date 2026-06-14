#include "fat32.h"
#include "disk.h"

static FAT32_BPB bpb;

static uint32_t fat_start;
static uint32_t data_start;

int fat32_init(void)
{
    if(disk_read_sector(0, &bpb) != 0)
        return -1;

    fat_start = bpb.reserved_sectors;

    data_start =
        bpb.reserved_sectors +
        (bpb.fat_count * bpb.fat_size32);

    return 0;
}

uint32_t fat32_cluster_to_lba(uint32_t cluster)
{
    return data_start +
        ((cluster - 2) *
        bpb.sectors_per_cluster);
}
