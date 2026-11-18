#include <stdio.h>
#include <string.h>

// XOR function for CRC modulo-2 division
void xorOp(char *dividend, const char *divisor, int n) {
    for (int i = 1; i < n; i++) {
        dividend[i - 1] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

// Modulo-2 division returning remainder in 'rem'
void mod2div(char *data, const char *key, char *rem) {
    int keyLen = strlen(key);
    char temp[150];
    strcpy(temp, data);

    for (int i = 0; i <= strlen(data) - keyLen; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < keyLen; j++) {
                temp[i + j] = (temp[i + j] == key[j]) ? '0' : '1';
            }
        }
    }
    // Copy the last (keyLen - 1) bits as remainder
    strncpy(rem, temp + strlen(data) - (keyLen - 1), keyLen - 1);
    rem[keyLen - 1] = '\0';
}

int main() {
    char data[100], key[50], rem[50], codeword[150];

    printf("Enter data to send (binary): ");
    scanf("%99s", data);
    printf("Enter divisor / generator (binary): ");
    scanf("%49s", key);

    int keyLen = strlen(key);

    // Append (keyLen - 1) zeros to data
    strcpy(codeword, data);
    for (int i = 0; i < keyLen - 1; i++) {
        strcat(codeword, "0");
    }

    // Calculate CRC remainder
    mod2div(codeword, key, rem);

    // Form final transmitted codeword: data + remainder
    strcpy(codeword, data);
    strcat(codeword, rem);

    printf("\nSender Side:\n");
    printf("Data: %s\n", data);
    printf("Divisor: %s\n", key);
    printf("Codeword (Data + CRC): %s\n", codeword);

    // Receiver side check on valid codeword
    printf("\nReceiver Side (Original):\n");
    mod2div(codeword, key, rem);
    int error = 0;
    for (int i = 0; i < strlen(rem); i++) {
        if (rem[i] == '1') error = 1;
    }
    if (!error)
        printf("Data is correct (No errors detected)\n");
    else
        printf("Data is incorrect (Error detected)\n");

    // Simulate bit flip error
    printf("\nSimulating error by flipping first bit...\n");
    codeword[0] = (codeword[0] == '0') ? '1' : '0';
    printf("Erroneous Received Data: %s\n", codeword);

    mod2div(codeword, key, rem);
    error = 0;
    for (int i = 0; i < strlen(rem); i++) {
        if (rem[i] == '1') error = 1;
    }
    if (!error)
        printf("Data is correct (No errors detected)\n");
    else
        printf("Data is incorrect (Error detected!)\n");

    return 0;
}

/*
Example Output:

Enter data to send (binary): 1001
Enter divisor / generator (binary): 1011

Sender Side:
Data: 1001
Divisor: 1011
Codeword (Data + CRC): 1001110

Receiver Side (Original):
Data is correct (No errors detected)

Simulating error by flipping first bit...
Erroneous Received Data: 0001110
Data is incorrect (Error detected!)
*/
