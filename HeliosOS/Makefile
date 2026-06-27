# ======================================================
# HeliosOS Makefile
# ======================================================

# Tools
CC      = i686-elf-gcc
LD      = i686-elf-ld
AS      = nasm

# Flags
CFLAGS  = -m32 -ffreestanding -fno-stack-protector -fno-pic \
          -Wall -Wextra -O2 \
          -Ikernel -Ikernel/gui -Ikernel/gfx -Ikernel/input -Ifs

LDFLAGS = -T linker.ld -nostdlib

ASMFLAGS = -f elf32

# ------------------------------------------------------

BOOT_ASM = \
boot/gdt.asm \
boot/protected.asm \
boot/a20.asm \
boot/kernel_entry.asm \
boot/stage2.asm

KERNEL_ASM = \
kernel/isr.asm \
kernel/irq.asm \
kernel/irq12.asm

BOOT_C =

KERNEL_C = \
kernel/kernel.c \
kernel/framebuffer.c \
kernel/interrupts.c \
kernel/keyboard.c \
kernel/idt.c \
kernel/ports.c \
kernel/pit.c \
kernel/screen.c \
kernel/shell.c \
\
kernel/gui/gui.c \
kernel/gui/window.c \
\
kernel/gfx/compositor.c \
kernel/gfx/gdi.c \
kernel/gfx/surface.c \
\
kernel/input/mouse.c \
kernel/input/ps2.c \
\
fs/ata.c \
fs/disk.c \
fs/fat32.c

# ------------------------------------------------------

ASM_OBJ = $(BOOT_ASM:.asm=.o) $(KERNEL_ASM:.asm=.o)
C_OBJ   = $(KERNEL_C:.c=.o)

OBJ = $(ASM_OBJ) $(C_OBJ)

# ------------------------------------------------------

all: Helios.bin

Helios.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o kernel.elf $(OBJ)
	i686-elf-objcopy -O binary kernel.elf Helios.bin

# ------------------------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $(ASMFLAGS) $< -o $@

# ------------------------------------------------------

run: Helios.bin
	qemu-system-i386 \
	-drive format=raw,file=Helios.bin

debug: Helios.bin
	qemu-system-i386 \
	-s -S \
	-drive format=raw,file=Helios.bin

clean:
	rm -f $(OBJ)
	rm -f kernel.elf
	rm -f Helios.bin

re: clean all

.PHONY: all clean re run debug
