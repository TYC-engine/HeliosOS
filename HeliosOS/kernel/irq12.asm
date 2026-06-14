global irq12
extern mouse_irq_handler

irq12:
    pusha

    ; прочитать байт от мыши
    in al, 0x60
    movzx eax, al

    push eax
    call mouse_irq_handler
    add esp, 4

    ; EOI (ВАЖНО: slave сначала)
    mov al, 0x20
    out 0xA0, al
    out 0x20, al

    popa
    iretd
