[BITS 32]

KERNEL_ADDR equ 0x20000

protected_mode:

    mov ax,0x10

    mov ds,ax
    mov es,ax
    mov fs,ax
    mov gs,ax
    mov ss,ax

    mov esp,0x90000

    jmp KERNEL_ADDR
