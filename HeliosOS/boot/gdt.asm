[BITS 16]

gdt_start:

dq 0

dq 0x00CF9A000000FFFF

dq 0x00CF92000000FFFF

gdt_end:

gdt_descriptor:
    dw gdt_end-gdt_start-1
    dd gdt_start

load_gdt:
    lgdt [gdt_descriptor]
    ret
