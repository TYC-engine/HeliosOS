[BITS 32]

extern kernel_main
extern gdt_flush
extern tss_flush

global _start

; =========================
; STACK
; =========================
section .bss
align 16

stack_bottom:
    resb 16384
stack_top:

; =========================
; ENTRY
; =========================
section .text
align 4

_start:

    ; stack setup
    mov esp, stack_top
    mov ebp, esp

    cld
    cli

    ; -------------------------
    ; GDT reload (important for TSS)
    ; -------------------------
    call gdt_flush

    ; -------------------------
    ; TSS load
    ; -------------------------
    call tss_flush

    ; -------------------------
    ; jump to kernel C entry
    ; -------------------------
    call kernel_main

.hang:
    hlt
    jmp .hang
