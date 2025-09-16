Author: @Ray Li
Date: 2025-09-13
Description: Guide to XOR demo and how it maps to the annotated ARM64 assembly.

## What this shows
- The encrypt/decrypt function is an in-place XOR on each byte using a single-byte key (0x58).
- Calling the same function twice with the same key returns the original string.

## How to run
- macOS (Clang):
```
cc -O0 -g xor_demo.c -o xor_demo && ./xor_demo
```
- Linux (gcc):
```
gcc -O0 -g xor_demo.c -o xor_demo && ./xor_demo
```

## Mapping to assembly (annotated file)
- Key load: `mov w8,#0x58` then stored at `[sp,#0x1b]` → `key = 0x58`.
- Buffer pointer in `x0` (arg0), key in `w1` (arg1) → `encrypt_decrypt(msg, key)`.
- Loop index `[sp,#0x10]` → `for (size_t i = 0; i < strlen(s); i++)`.
- Core step:
  - `ldrsb w8,[x9]` (load byte)
  - `eor w8,w8,w10` (XOR with key)
  - `strb w8,[x9]` (store back)
  - C: `s[i] ^= key;`

## Next
- Change `key` and re-run.
- Try printing hex bytes before/after to see XOR numerically.
- Bonus: comment out the second call to see only encrypted output.
