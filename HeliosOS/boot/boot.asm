[BITS 16]
[ORG 0x7C00]

STAGE2_SEG equ 0x1000
STAGE2_OFF equ 0x0000

start:
    cli

    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    sti

    mov [boot_drive], dl

    mov ah, 0x02
    mov al, 8
    mov ch, 0
    mov cl, 2
    mov dh, 0

    mov bx, STAGE2_OFF
    mov ax, STAGE2_SEG
    mov es, ax

    int 0x13

    jc disk_error

    jmp STAGE2_SEG:STAGE2_OFF

disk_error:
    mov si, msg
.print:
    lodsb
    or al, al
    jz $
    mov ah, 0x0E
    int 0x10
    jmp .print

boot_drive db 0

msg db "Disk Error",0

times 510-($-$$) db 0
dw 0xAA55
