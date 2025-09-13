# Background:
My friend was teaching me how to do reverse engineer.

# Conversation happened between us

result from `❯ otool -tV practice_2_rengr`:

```
❯ otool -tV practice_2_rengr
practice_2_rengr:
(__TEXT,__text) section
_encrypt_decrypt:
0000000100003cfc        sub     sp, sp, #0x30
0000000100003d00        stp     x29, x30, [sp, #0x20]
0000000100003d04        add     x29, sp, #0x20
0000000100003d08        stur    x0, [x29, #-0x8]
0000000100003d0c        sturb   w1, [x29, #-0x9]
0000000100003d10        str     wzr, [sp, #0x10]
0000000100003d14        b       0x100003d18
0000000100003d18        ldrsw   x8, [sp, #0x10]
0000000100003d1c        str     x8, [sp, #0x8]
0000000100003d20        ldur    x0, [x29, #-0x8]
0000000100003d24        bl      0x100003ee0 ; symbol stub for: _strlen
0000000100003d28        ldr     x8, [sp, #0x8]
0000000100003d2c        subs    x8, x8, x0
0000000100003d30        cset    w8, hs
0000000100003d34        tbnz    w8, #0x0, 0x100003d6c
0000000100003d38        b       0x100003d3c
0000000100003d3c        ldursb  w10, [x29, #-0x9]
0000000100003d40        ldur    x8, [x29, #-0x8]
0000000100003d44        ldrsw   x9, [sp, #0x10]
0000000100003d48        add     x9, x8, x9
0000000100003d4c        ldrsb   w8, [x9]
0000000100003d50        eor     w8, w8, w10
0000000100003d54        strb    w8, [x9]
0000000100003d58        b       0x100003d5c
0000000100003d5c        ldr     w8, [sp, #0x10]
0000000100003d60        add     w8, w8, #0x1
0000000100003d64        str     w8, [sp, #0x10]
0000000100003d68        b       0x100003d18
0000000100003d6c        ldp     x29, x30, [sp, #0x20]
0000000100003d70        add     sp, sp, #0x30
0000000100003d74        ret
_secret_function:
0000000100003d78        stp     x29, x30, [sp, #-0x10]!
0000000100003d7c        mov     x29, sp
0000000100003d80        adrp    x0, 0 ; 0x100003000
0000000100003d84        add     x0, x0, #0xeec ; literal pool for: "\n[+] You have successfully reversed the binary!\n"
0000000100003d88        bl      0x100003ec8 ; symbol stub for: _printf
0000000100003d8c        ldp     x29, x30, [sp], #0x10
0000000100003d90        ret
_main:
0000000100003d94        sub     sp, sp, #0x60
0000000100003d98        stp     x29, x30, [sp, #0x50]
0000000100003d9c        add     x29, sp, #0x50
0000000100003da0        adrp    x8, 1 ; 0x100004000
0000000100003da4        ldr     x8, [x8, #0x8] ; literal pool symbol address: ___stack_chk_guard
0000000100003da8        ldr     x8, [x8]
0000000100003dac        stur    x8, [x29, #-0x8]
0000000100003db0        str     wzr, [sp, #0x1c]
0000000100003db4        mov     w8, #0x58
0000000100003db8        strb    w8, [sp, #0x1b]
0000000100003dbc        adrp    x9, 0 ; 0x100003000
0000000100003dc0        add     x9, x9, #0xf1d ; literal pool for: "Hello, Reverse Engineer!"
0000000100003dc4        ldr     q0, [x9]
0000000100003dc8        add     x8, sp, #0x20
0000000100003dcc        str     x8, [sp, #0x8]
0000000100003dd0        str     q0, [sp, #0x20]
0000000100003dd4        ldur    q0, [x9, #0x9]
0000000100003dd8        stur    q0, [x8, #0x9]
0000000100003ddc        mov     x9, sp
0000000100003de0        str     x8, [x9]
0000000100003de4        adrp    x0, 0 ; 0x100003000
0000000100003de8        add     x0, x0, #0xf36 ; literal pool for: "Original Message: %s\n"
0000000100003dec        bl      0x100003ec8 ; symbol stub for: _printf
0000000100003df0        ldr     x0, [sp, #0x8]
0000000100003df4        ldrsb   w1, [sp, #0x1b]
0000000100003df8        bl      _encrypt_decrypt
0000000100003dfc        ldr     x8, [sp, #0x8]
0000000100003e00        mov     x9, sp
0000000100003e04        str     x8, [x9]
0000000100003e08        adrp    x0, 0 ; 0x100003000
0000000100003e0c        add     x0, x0, #0xf4c ; literal pool for: "Encrypted Message: %s\n"
0000000100003e10        bl      0x100003ec8 ; symbol stub for: _printf
0000000100003e14        ldr     x0, [sp, #0x8]
0000000100003e18        ldrsb   w1, [sp, #0x1b]
0000000100003e1c        bl      _encrypt_decrypt
0000000100003e20        ldr     x8, [sp, #0x8]
0000000100003e24        mov     x9, sp
0000000100003e28        str     x8, [x9]
0000000100003e2c        adrp    x0, 0 ; 0x100003000
0000000100003e30        add     x0, x0, #0xf63 ; literal pool for: "Decrypted Message: %s\n"
0000000100003e34        bl      0x100003ec8 ; symbol stub for: _printf
0000000100003e38        adrp    x0, 0 ; 0x100003000
0000000100003e3c        add     x0, x0, #0xf7a ; literal pool for: "\nEnter passcode: "
0000000100003e40        bl      0x100003ec8 ; symbol stub for: _printf
0000000100003e44        mov     x9, sp
0000000100003e48        add     x8, sp, #0x14
0000000100003e4c        str     x8, [x9]
0000000100003e50        adrp    x0, 0 ; 0x100003000
0000000100003e54        add     x0, x0, #0xf8c ; literal pool for: "%d"
0000000100003e58        bl      0x100003ed4 ; symbol stub for: _scanf
0000000100003e5c        ldr     w8, [sp, #0x14]
0000000100003e60        subs    w8, w8, #0x539
0000000100003e64        cset    w8, ne
0000000100003e68        tbnz    w8, #0x0, 0x100003e78
0000000100003e6c        b       0x100003e70
0000000100003e70        bl      _secret_function
0000000100003e74        b       0x100003e88
0000000100003e78        adrp    x0, 0 ; 0x100003000
0000000100003e7c        add     x0, x0, #0xf8f ; literal pool for: "\n[-] Wrong passcode!\n"
0000000100003e80        bl      0x100003ec8 ; symbol stub for: _printf
0000000100003e84        b       0x100003e88
0000000100003e88        ldur    x9, [x29, #-0x8]
0000000100003e8c        adrp    x8, 1 ; 0x100004000
0000000100003e90        ldr     x8, [x8, #0x8] ; literal pool symbol address: ___stack_chk_guard
0000000100003e94        ldr     x8, [x8]
0000000100003e98        subs    x8, x8, x9
0000000100003e9c        cset    w8, eq
0000000100003ea0        tbnz    w8, #0x0, 0x100003eac
0000000100003ea4        b       0x100003ea8
0000000100003ea8        bl      0x100003ebc ; symbol stub for: ___stack_chk_fail
0000000100003eac        mov     w0, #0x0
0000000100003eb0        ldp     x29, x30, [sp, #0x50]
0000000100003eb4        add     sp, sp, #0x60
0000000100003eb8        ret
```

- Him: "There should be a password in the program, find it. Then you solved the problem."
- Me: "I never learned this kind of assembly language, is this ARM assembly? It doesn't have the `%rax` thing"
- Him: "Yes this is an ARM assembly. But it's fine, I never learned ARM assembly either but I have found the password"
- Me: "How?"
- Me: "First, you can see that there is a line of `"\nEnter passcode: "`. And, there is a line of ` "\n[-] Wrong passcode!\n"`. I know that the password must be between those lines."
- Him: "That's correct."
- Me: "But that's the only thing I know. I don't understand what the `ldp`, `bl`, etc stuff."
- Him: "Ok, let me analyze it for you. So you can see that the line `0000000100003e68        tbnz    w8, #0x0, 0x100003e78` mentioned `0x100003e78`. You can see that the line of `0000000100003e78` and following lines are printing `Wrong passcode!`. So very likely this is a branching, right?"
- Me: "Ah! I see, so I am guessing that it is comparing `w8` and `#0x0`? So the password is 0!"
- Him: "Nah, let's go further and see what's actually in `w8`."
- Him: "See the line of 
```
0000000100003e54        add     x0, x0, #0xf8c ; literal pool for: "%d"
0000000100003e58        bl      0x100003ed4 ; symbol stub for: _scanf
```
"
- Him: "You can see that there mentioned `_scanf`, right? `printf` is outputing and `scanf` is inputing."
- Him: "Then you see `%d`, what does that stand for? Decimal right? So it is an integer."
- Him: "Then you see `0000000100003e5c        ldr     w8, [sp, #0x14]
0000000100003e60        subs    w8, w8, #0x539`, this finally mentioned `w8`, and then what we found? `subs    w8, w8, #0x539`!"
- Me: "I see, so the password is `#0x539`!"
- Him: "Correct, convert it to decimal and input it and try."

What I want to tell in this example is that althoguh I have no idea what the most of the stuff means he still guided me through the process and took me hacked the program generally. This is a good learning experience for me for several reasons:

- He kept prompting me and hinting me to get closer and closer to the answer.
- He didn't try to make me have a "strong basis" before I start doing it. 
- He made it a game of finding source and crack the program, which is kind of like a detective game. He omitted unnecessary details and jorgons. With the easiest language he walked me through the process and made me understand everything. 

You can tell that even after the program is cracked, I probably didn't learned much about the assembly (but that is find cuz that is not the most important purpose! I have to keep being interested before I started learning!), but I do have a sense of how things works and have a feeling that I cracked a program. 

Same for you, you don't have to make the learning content most accurate and most precise and with high information density. This is purely a project out of interest. Being interesting should be it's top priority.