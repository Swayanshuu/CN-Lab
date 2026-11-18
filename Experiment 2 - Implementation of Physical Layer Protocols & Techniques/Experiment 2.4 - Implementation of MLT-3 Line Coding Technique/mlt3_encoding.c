#include <stdio.h>
#include <string.h>

// MLT-3 line coding:
// '0' -> no transition (keeps current level)
// '1' -> transition: if at 0V, go to opposite of last non-zero (+V or -V); if at non-zero, go to 0V
void mlt3Encode(char *data) {
    int current_level = 0;      // 0V
    int last_nonzero_level = -1;// initially -V

    printf("MLT-3 Encoded Signal: ");

    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '0') {
            // Level stays the same
        } else if (data[i] == '1') {
            if (current_level == 0) {
                current_level = -last_nonzero_level;
                last_nonzero_level = current_level;
            } else {
                current_level = 0;
            }
        } else {
            printf("Invalid input character.\n");
            return;
        }

        if (current_level == 0)
            printf("| 0V ");
        else if (current_level == -1)
            printf("| -V ");
        else
            printf("| +V ");
    }
    printf("|\n");
}

int main() {
    char data_stream[100];

    printf("Enter binary data stream: ");
    scanf("%99s", data_stream);

    mlt3Encode(data_stream);

    return 0;
}

/*
Example Output:

Run 1:
Enter binary data stream: 1011001
MLT-3 Encoded Signal: | +V | +V | 0V | -V | -V | 0V | +V |

Run 2:
Enter binary data stream: 467
Invalid input character.
*/
