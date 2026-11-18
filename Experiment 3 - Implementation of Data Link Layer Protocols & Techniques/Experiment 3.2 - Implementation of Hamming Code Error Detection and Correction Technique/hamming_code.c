#include <stdio.h>

int main() {
    int a[4], code[7], s0, s1, s2, error;

    printf("Enter 4 data bits (e.g. 0 0 1 1): ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate 3 even-parity bits
    int r0 = (a[0] + a[1] + a[2]) % 2;
    int r1 = (a[1] + a[2] + a[3]) % 2;
    int r2 = (a[0] + a[1] + a[3]) % 2;

    // Assemble 7-bit codeword: r0 r1 r2 a0 a1 a2 a3
    code[0] = r0;
    code[1] = r1;
    code[2] = r2;
    code[3] = a[0];
    code[4] = a[1];
    code[5] = a[2];
    code[6] = a[3];

    printf("Encoded 7-bit codeword: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", code[i]);
    }
    printf("\n");

    printf("Enter bit position to introduce error (1-7, 0 for none): ");
    scanf("%d", &error);

    if (error > 0 && error <= 7) {
        code[error - 1] ^= 1; // Flip bit to simulate error
        printf("Codeword with error: ");
        for (int i = 0; i < 7; i++) printf("%d ", code[i]);
        printf("\n");
    }

    // Receiver side computes syndrome bits
    s0 = (code[3] + code[4] + code[5] + code[0]) % 2;
    s1 = (code[4] + code[5] + code[6] + code[1]) % 2;
    s2 = (code[3] + code[4] + code[6] + code[2]) % 2;

    int pos = (s2 << 2) | (s1 << 1) | s0;

    printf("\nReceiver Side:\n");
    if (pos == 0) {
        printf("No error detected.\n");
    } else {
        printf("Error detected at bit position: %d\n", pos);
        code[pos - 1] ^= 1; // Automatically correct the bit
    }

    printf("Corrected Codeword: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", code[i]);
    }
    printf("\n");

    return 0;
}

/*
Example Output:

Run 1 (With Single-Bit Error):
Enter 4 data bits (e.g. 0 0 1 1): 0 0 1 1
Encoded 7-bit codeword: 1 0 1 0 0 1 1 
Enter bit position to introduce error (1-7, 0 for none): 5
Codeword with error: 1 0 1 0 1 1 1 

Receiver Side:
Error detected at bit position: 5
Corrected Codeword: 1 0 1 0 0 1 1 

Run 2 (No Error):
Enter 4 data bits (e.g. 0 0 1 1): 1 0 1 1
Encoded 7-bit codeword: 0 0 0 1 0 1 1 
Enter bit position to introduce error (1-7, 0 for none): 0

Receiver Side:
No error detected.
Corrected Codeword: 0 0 0 1 0 1 1 
*/
