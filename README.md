# ☀️ HeliosOS

<div align="center">

# HeliosOS

**Experimental Operating System Written From Scratch**

![Version](https://img.shields.io/badge/version-0.1.0-blue)
![Status](https://img.shields.io/badge/status-development-orange)
![Architecture](https://img.shields.io/badge/architecture-x86-lightgrey)
![Language](https://img.shields.io/badge/language-C%20%7C%20Assembly-green)
![License](https://img.shields.io/badge/license-MIT-purple)

*Building an operating system from the boot sector to the kernel.*

</div>

---

## 📖 About

HeliosOS is an educational operating system project focused on understanding:

* Operating System Development
* Computer Architecture
* Bootloaders
* x86 Assembly
* Kernel Design
* Memory Management
* Graphics Programming

The project aims to create a complete operating system using custom technologies and components.

---

## ✨ Features

### Current

* [x] Custom Bootloader
* [x] Kernel Entry Point
* [x] VGA Text Output
* [x] Basic Console
* [x] Keyboard Input

### Planned

* [ ] Protected Mode
* [ ] Memory Manager
* [ ] Framebuffer Graphics
* [ ] File System
* [ ] User Applications
* [ ] Networking
* [ ] GUI
* [ ] Helios Package Manager

---

## 📸 Screenshots

### Boot Process

```text
[BOOT] Loading HeliosOS...
[BOOT] Initializing hardware...
[BOOT] Loading kernel...
[ OK ] Kernel loaded.

HeliosOS booted successfully.
```

### Terminal

```text
HeliosOS v0.1

helios> help

Available commands:

help
clear
info
reboot

helios>
```

---

## 🏗 Architecture

```text
+-----------------------+
|      Applications     |
+-----------------------+
|      Helios Shell     |
+-----------------------+
|        Kernel         |
+-----------------------+
|      Bootloader       |
+-----------------------+
|       BIOS/UEFI       |
+-----------------------+
|       Hardware        |
+-----------------------+
```

---

## 📂 Project Structure

```text
HeliosOS
│
├── boot/
│   ├── boot.asm
│   ├── gdt.asm
│   └── protected.asm
│
├── kernel/
│   ├── kernel.c
│   ├── screen.c
│   ├── keyboard.c
│   └── memory.c
│
├── include/
│   ├── kernel.h
│   ├── screen.h
│   └── keyboard.h
│
├── tools/
│   └── build
│
├── docs/
│   └── specifications
│
├── Makefile
│
└── README.md
```

---

## ⚙️ Requirements

| Tool               | Purpose            |
| ------------------ | ------------------ |
| NASM               | Assembler          |
| GCC Cross Compiler | Kernel Compilation |
| Make               | Build System       |
| QEMU               | Emulation          |
| Git                | Version Control    |

---

## 🚀 Build

### Compile

```bash
make
```

### Run

```bash
qemu-system-i386 -drive format=raw,file=helios.img
```

### Debug

```bash
qemu-system-i386 -s -S -drive format=raw,file=helios.img
```

---

## 🧠 Boot Flow

```text
Power On
    │
    ▼
BIOS
    │
    ▼
Bootloader
    │
    ▼
Kernel Loader
    │
    ▼
Kernel Initialization
    │
    ▼
Drivers
    │
    ▼
Helios Shell
```

---

## 🛣 Roadmap

| Feature         | Status         |
| --------------- | -------------- |
| Bootloader      | ✅ Complete     |
| Kernel Entry    | ✅ Complete     |
| VGA Driver      | ✅ Complete     |
| Keyboard Driver | 🟡 In Progress |
| Protected Mode  | 🟡 In Progress |
| Memory Manager  | 🔲 Planned     |
| Interrupts      | 🔲 Planned     |
| File System     | 🔲 Planned     |
| Multitasking    | 🔲 Planned     |
| Networking      | 🔲 Planned     |
| GUI             | 🔲 Planned     |
| HASM Compiler   | 🔲 Planned     |
| Package Manager | 🔲 Planned     |

---

## 🔧 Helios Technologies

### HASM

Helios Assembly Language.

Example:

```asm
section .text

start:
    print "Hello HeliosOS"
    halt
```

### HA Executable Format

```text
program.ha
```

Future executable format designed for HeliosOS.

---

## 🎯 Long-Term Goals

* Custom Bootloader
* Custom Kernel
* Custom Executable Format
* Custom Programming Language
* Custom GUI
* Custom Package Manager
* Educational Documentation

---

## 📊 Development Status

```text
Bootloader        ██████████ 100%
Kernel            ████░░░░░░ 40%
Drivers           ██░░░░░░░░ 20%
Memory Manager    ░░░░░░░░░░  0%
File System       ░░░░░░░░░░  0%
GUI               ░░░░░░░░░░  0%
```

---

## 🤝 Contributing

Contributions, bug reports, ideas, and documentation improvements are welcome.

1. Fork repository
2. Create branch
3. Commit changes
4. Open pull request

---

## 📜 License

Apache 2.0 License

Copyright (c) HeliosOS Project

---

<div align="center">

### ☀️ HeliosOS

*"From Boot Sector to Operating System."*

</div>
