#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[200], destuffed[100];
    int count = 0, j = 0;

    printf("Enter binary data (e.g. 0111111010): ");
    scanf("%99s", data);

    // Bit Stuffing: after 5 consecutive 1s, insert a '0'
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        stuffed[j++] = data[i];

        if (count == 5) {
            stuffed[j++] = '0'; // Stuffed bit
            count = 0;
        }
    }
    stuffed[j] = '\0';

    printf("\nStuffed Data  : %s\n", stuffed);

    // Bit Destuffing: after 5 consecutive 1s, skip the following '0'
    count = 0;
    int k = 0;
    for (int i = 0; i < strlen(stuffed); i++) {
        if (stuffed[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        destuffed[k++] = stuffed[i];

        if (count == 5) {
            if (stuffed[i + 1] == '0') {
                i++; // Skip the stuffed '0'
            }
            count = 0;
        }
    }
    destuffed[k] = '\0';

    printf("Destuffed Data: %s\n", destuffed);

    return 0;
}

/*
Example Output:

Run 1:
Enter binary data (e.g. 0111111010): 100100001101

Stuffed Data  : 100100001101
Destuffed Data: 100100001101

Run 2 (With Five 1s in Sequence):
Enter binary data (e.g. 0111111010): 01101111111001010

Stuffed Data  : 011011111011001010
Destuffed Data: 01101111111001010
*/
