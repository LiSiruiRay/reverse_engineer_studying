#Author : @Ray Li
#Date : 2025 - 09 - 13
#Description : Tiny XOR demo mirroring the ARM64 encrypt_decrypt loop; compile and run to see behavior.

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// XOR cipher: in-place, byte-wise, same function for encrypt and decrypt
static void encrypt_decrypt(uint8_t *s, uint8_t key)
{
    // index i is like [sp,#0x10] in the assembly
    for (size_t i = 0; i < strlen((char *)s); i++)
    {
        // This line corresponds to: ldrsb w8,[x9]; eor w8,w8,w10; strb w8,[x9]
        s[i] ^= key; // XOR per byte
    }
}

int main(void)
{
    // Match the message seen in the assembly
    uint8_t msg[] = "Hello, Reverse Engineer!";
    uint8_t key = 0x58; // from mov w8,#0x58 in _main

    printf("Original Message: %s\n", (char *)msg);

    encrypt_decrypt(msg, key); // first call → encrypt
    printf("Encrypted Message: %s\n", (char *)msg);

    encrypt_decrypt(msg, key); // second call → decrypt (XOR is self-inverse)
    printf("Decrypted Message: %s\n", (char *)msg);

    return 0;
}
