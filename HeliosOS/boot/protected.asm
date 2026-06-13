[BITS 32]

global protected_mode

protected_mode:

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov esp, 0x90000

    mov dword [0xB8000], 0x0F650F48
    mov dword [0xB8004], 0x0F690F6C
    mov dword [0xB8008], 0x0F730F6F

.hang:
    hlt
    jmp .hang
