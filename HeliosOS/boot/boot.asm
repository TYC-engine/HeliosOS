[BITS 16]
[ORG 0x7C00]

extern load_gdt
extern protected_mode

start:
    cli

    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    call load_gdt

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp 0x08:protected_mode

times 510-($-$$) db 0
dw 0xAA55
