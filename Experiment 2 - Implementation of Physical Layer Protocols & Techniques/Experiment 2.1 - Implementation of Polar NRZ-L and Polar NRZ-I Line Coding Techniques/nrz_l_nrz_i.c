#include <stdio.h>
#include <string.h>

int main() {
    char data[100];

    printf("Enter binary data (e.g. 10011101): ");
    scanf("%99s", data);

    // Validate binary input
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] != '0' && data[i] != '1') {
            printf("Invalid character in binary input.\n");
            return 1;
        }
    }

    // NRZ-L: '0' is positive (+), '1' is negative (-)
    printf("\nNRZ-L Encoding: ");
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '0')
            printf("| + ");
        else
            printf("| - ");
    }
    printf("|\n");

    // NRZ-I: '1' inverts voltage level, '0' stays the same
    printf("NRZ-I Encoding: ");
    int level = 0; // 0 = positive (+), 1 = negative (-)
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '1') {
            level = 1 - level; // invert
        }
        if (level == 0)
            printf("| + ");
        else
            printf("| - ");
    }
    printf("|\n");

    return 0;
}

/*
Example Output:

Run 1:
Enter binary data (e.g. 10011101): 10011101

NRZ-L Encoding: | - | + | + | - | - | - | + | - |
NRZ-I Encoding: | - | - | - | + | - | + | + | - |

Run 2:
Enter binary data (e.g. 10011101): 158
Invalid character in binary input.
*/
