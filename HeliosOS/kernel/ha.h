#ifndef HA_H
#define HA_H

typedef struct
{
    char magic[4];
    unsigned int version;
    unsigned int entry;
    unsigned int size;
} HAHeader;

#endif
