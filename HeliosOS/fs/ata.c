#include "ata.h"
#include "../ports.h"

#define ATA_DATA       0x1F0
#define ATA_SECTORCNT  0x1F2
#define ATA_LBA_LOW    0x1F3
#define ATA_LBA_MID    0x1F4
#define ATA_LBA_HIGH   0x1F5
#define ATA_DRIVE      0x1F6
#define ATA_COMMAND    0x1F7
#define ATA_STATUS     0x1F7

#define ATA_CMD_READ   0x20

static void ata_wait()
{
    while(inb(ATA_STATUS) & 0x80);
}

int ata_read28(uint32_t lba, uint8_t* buffer)
{
    ata_wait();

    outb(ATA_DRIVE,
        0xE0 | ((lba >> 24) & 0x0F));

    outb(ATA_SECTORCNT, 1);

    outb(ATA_LBA_LOW,
        (uint8_t)(lba));

    outb(ATA_LBA_MID,
        (uint8_t)(lba >> 8));

    outb(ATA_LBA_HIGH,
        (uint8_t)(lba >> 16));

    outb(ATA_COMMAND, ATA_CMD_READ);

    while(!(inb(ATA_STATUS) & 0x08));

    uint16_t* ptr = (uint16_t*)buffer;

    for(int i = 0; i < 256; i++)
    {
        uint16_t data;

        __asm__ volatile(
            "inw %1, %0"
            : "=a"(data)
            : "Nd"(ATA_DATA)
        );

        ptr[i] = data;
    }

    return 0;
}
