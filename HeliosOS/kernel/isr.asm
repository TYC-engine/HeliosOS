[BITS 32]

global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15

global irq0
global irq1
global irq12

extern isr_handler
extern irq_handler

; =========================
; CPU EXCEPTIONS
; =========================

%macro ISR_NOERR 1
isr%1:
    cli
    push dword 0
    push dword %1
    call isr_handler
    add esp, 8
    sti
    iretd
%endmacro

ISR_NOERR 0
ISR_NOERR 1
ISR_NOERR 2
ISR_NOERR 3
ISR_NOERR 4
ISR_NOERR 5
ISR_NOERR 6
ISR_NOERR 7
ISR_NOERR 8
ISR_NOERR 9
ISR_NOERR 10
ISR_NOERR 11
ISR_NOERR 12
ISR_NOERR 13
ISR_NOERR 14
ISR_NOERR 15

; =========================
; IRQ WRAPPER
; =========================

irq0:
    pusha
    push dword 32
    call irq_handler
    add esp, 4
    popa
    iretd

irq1:
    pusha
    push dword 33
    call irq_handler
    add esp, 4
    popa
    iretd

irq12:
    pusha

    in al, 0x60
    push eax
    push dword 44
    call irq_handler
    add esp, 8

    popa
    iretd
