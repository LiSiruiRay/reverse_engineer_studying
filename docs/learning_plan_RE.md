Author: @Ray Li
Date: 2025-09-12
Description: Reverse Engineering learning plan with resources, projects, and non-linear tracks.

## Reverse Engineering (RE) Learning Plan

Designed for your background (algorithms, CSO, some C/C++, compilers) and learning style (non-linear, hands-on). Pick a track to start, then weave across.

### Tracks (choose-your-path)
- **Core RE Skills**: Assembly, calling conventions, binaries, tooling.
- **Systems & Compilers**: Compilers/IR, linkers/loaders, OS/ABI internals.
- **Applied Security**: Crackmes, CTF pwn, reversing protections, instrumentation.

### Weekly cadence (flexible)
- **2x Focus Blocks (90–120 min)**: One theory, one tooling/project.
- **1x Challenge (60–90 min)**: Crackme/CTF or micro-lab.
- **1x Reflection (15–30 min)**: Notes on what you understood, what to probe next.

---

## Environment setup (macOS Apple Silicon, ARM64)
- **Disassemblers/Decompilers**
  - Ghidra (free), Cutter/rizin (free), IDA Free, Hopper (macOS-focused, paid trial), Binary Ninja (paid).
- **Debuggers/Runtime**
  - lldb (Xcode Command Line Tools), `pwndbg`-like flow via lldb/`lldbinit`, `frida`, `dyld_info`, `otool`, `jtool2`, `nm`, `codesign`.
- **Binary formats/Tooling**
  - Mach-O (macOS), ELF (Linux in Docker), PE (optional later).
- **Containers/VMs**
  - Docker for Linux x86_64 targets; optional Ubuntu VM.

Install hints (Homebrew):
- `brew install --cask ghidra hopper-disassembler`
- `brew install cutter radare2 rizin llvm frida coreutils binutils qemu`
- `xcode-select --install` (Command Line Tools)
- Optional Docker Desktop for macOS.

---

## Immediate 2-week plan (fast start)
- **Week 1**
  - Setup tools above; verify `lldb`, `otool`, `nm`, `strings` on a sample Mach-O (`/bin/ls`).
  - Write 3 tiny C programs (math, string ops, struct). Compile with `-O0/-O2`, inspect in Ghidra and with `otool -tvV`.
  - Read: Apple Mach-O docs (overview), x86-64 vs ARM64 calling conv cheat sheet (skim).
- **Week 2**
  - Solve 3 crackmes (ARM64 or cross-compile to Linux x86_64 in Docker). Aim: identify main, find comparison logic, patch.
  - Dynamic instrumentation: write one simple Frida script to hook `strcmp`/`strncmp` in your crackme.
  - Reflection: capture patterns you used (string refs, xrefs, decompiler pitfalls).

---

## Core concepts (layered)
- **Assembly & ABI**
  - ARM64 registers, stack, prologue/epilogue; x86-64 basics for contrast.
  - Calling conventions (SysV AMD64, AAPCS64), variadics, struct passing.
- **Binary anatomy**
  - Mach-O vs ELF sections, symbols, relocations, PLT/GOT (ELF), dyld stubs (Mach-O), PIE/ASLR.
- **Compiler/optimizer impact**
  - -O levels, inlining, tail calls, loop opts, SROA; how patterns appear in decompiler vs disassembly.
- **Defenses**
  - NX, ASLR, stack canaries, relro, codesigning, hardened runtime, ptr auth (PAC) on Apple Silicon.
- **Dynamic analysis**
  - Breakpoints, watchpoints, memory maps, syscall tracing; Frida hooks and stalkers.

---

## Projects (progressive, mix-and-match)
- **P0. Tool warm-up (2–3 hrs)**
  - Reverse `/bin/ls` function boundaries; map 5 functions with arguments/returns.
- **P1. Crackme trio (4–6 hrs)**
  - Three binaries escalating from string compare → simple crypto → state machine.
- **P2. Mach-O deep dive (4 hrs)**
  - Parse a Mach-O file: list segments/sections, symbol table, imports. Output a JSON summary.
- **P3. Docker x86_64 stack overflow (6–8 hrs)**
  - Build a vulnerable C program in Docker (no PIE, no canary), gain RIP control, craft shellcode or ret2libc.
- **P4. Frida mini-deobfuscator (6–8 hrs)**
  - Hook selected functions to log params/returns; reconstruct hidden control flow.
- **P5. LLVM IR reconnaissance (6 hrs)**
  - Compile C with `-S -emit-llvm`, study IR patterns; write a tiny `opt` pass to count indirect calls.
- **P6. RISC-V firmware snippet (8–10 hrs)**
  - Take a bare-metal RISC-V binary, identify init, UART prints, simple loop.
- **P7. Basic decompiler pipeline (12–16 hrs)**
  - Using angr or rizin, lift to IR, build a simple struct/array recovery heuristic on toy binaries.
- **P8. Anti-debug/packers (10–14 hrs)**
  - Identify macOS anti-debug tricks (`ptrace`, sysctl), bypass via patch or Frida; unpack a UPX sample.

Each project should include: goals, constraints, writeup, and a checklist of techniques used.

---

## Resources (curated)
- **Books**
  - Reversing: Secrets of Reverse Engineering (Eilam)
  - Practical Binary Analysis (Cohen)
  - Hacking: The Art of Exploitation (Erickson)
  - Linkers and Loaders (Levine)
  - LLVM Language Reference + Writing an LLVM Pass (docs)
- **Courses/Tracks**
  - pwn.college (binary exploitation, CTF-style)
  - NSA Ghidra training materials
  - OpenSecurityTraining2 (OST2) – x86/x64, ARM, RE classes
- **References**
  - Apple Mach-O File Format Reference; dyld & codesigning docs
  - System V AMD64 ABI; AAPCS64
  - radare2/rizin, Frida, Ghidra user guides
- **Communities**
  - CTFtime, crackmes.one, r/ReverseEngineering, Malware Unicorn labs

---

## Assessment and habit loop
- Maintain a lab notebook (markdown) with: binary, toolchain, key xrefs, strategy, pitfalls.
- After every 2 projects: attempt one CTF pwn or crackme above your comfort.
- Monthly: one deep-dive reading (Linkers & Loaders chapter or Mach-O internals) + a replication task.

---

## Suggested non-linear path examples
- Security-first: P1 → P3 → P8 → P4 → P7
- Systems-first: P2 → P5 → P6 → P7
- Balanced: P0 → P1 → P2 → P4 → P5 → P3

---

## Next actions (today)
- Install tools via Homebrew and verify on `/bin/ls`.
- Create a `practice/` subfolder for Week 1 programs; commit binaries with `-O0/-O2`.
- Start P0 and record observations.

---

## Appendix: quick cheats
- ARM64 call conv (AAPCS64): x0–x7 args, x8 indirect result, x29 fp, x30 lr, sp aligned 16.
- x86-64 SysV: rdi, rsi, rdx, rcx, r8, r9 args, stack 16B aligned at call.
- Common patterns: strcmp key path; loop unrolling at -O3; prologue elision with frame pointer omission.
