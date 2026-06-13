[BITS 16]

enable_a20:

.wait1:
    in al,0x64
    test al,2
    jnz .wait1

    mov al,0xD1
    out 0x64,al

.wait2:
    in al,0x64
    test al,2
    jnz .wait2

    mov al,0xDF
    out 0x60,al

    ret
