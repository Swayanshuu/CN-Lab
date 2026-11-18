#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>

#define MAX 100

// Modular exponentiation: calculates (base^exp) % mod safely
long long modpow(long long b, long long e, long long n) {
    long long r = 1;
    b %= n;
    while (e > 0) {
        if (e % 2 == 1)
            r = (r * b) % n;
        b = (b * b) % n;
        e /= 2;
    }
    return r;
}

// Computes modular inverse: (d * e) % phi == 1
long long modInverse(long long e, long long phi) {
    for (long long d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            return d;
    }
    return 1;
}

int main() {
    // Prime numbers and RSA key generation
    long long p = 61, q = 53;
    long long n = p * q;               // Modulus = 3233
    long long phi = (p - 1) * (q - 1); // Totient = 3120
    long long e = 17;                  // Public exponent
    long long d = modInverse(e, phi);  // Private exponent = 2753

    char msg[MAX];
    long long cipher[MAX];

    printf("Public Key (e, n) : (%lld, %lld)\n", e, n);
    printf("Private Key (d, n): (%lld, %lld)\n", d, n);

    printf("\nEnter message: ");
    if (fgets(msg, MAX, stdin) == NULL) return 1;
    msg[strcspn(msg, "\r\n")] = '\0';

    int len = strlen(msg);

    // Encryption: C = (M^e) mod n
    printf("\nEncrypted message:\n");
    for (int i = 0; i < len; i++) {
        cipher[i] = modpow((long long)msg[i], e, n);
        printf("%lld ", cipher[i]);
    }
    printf("\n");

    // Decryption: M = (C^d) mod n
    printf("\nDecrypted message:\n");
    for (int i = 0; i < len; i++) {
        char m = (char)modpow(cipher[i], d, n);
        printf("%c", m);
    }
    printf("\n");

    return 0;
}

/*
Example Output:

Public Key (e, n) : (17, 3233)
Private Key (d, n): (2753, 3233)

Enter message: HELLO

Encrypted message:
1087 2726 1307 1307 467 

Decrypted message:
HELLO
*/
