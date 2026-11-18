#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    char prev = '+'; // Initial level assumed positive (+)

    printf("Enter binary string (even length): ");
    scanf("%99s", data);

    int len = strlen(data);
    if (len % 2 != 0) {
        printf("Error: Length must be even for 2B1Q encoding.\n");
        return 1;
    }

    printf("2B1Q Encoded Output: ");
    for (int i = 0; i < len; i += 2) {
        char b1 = data[i], b2 = data[i + 1];
        int out = 0;

        if (prev == '+') {
            if (b1 == '0' && b2 == '0') { out = +1; prev = '+'; }
            else if (b1 == '0' && b2 == '1') { out = +3; prev = '+'; }
            else if (b1 == '1' && b2 == '0') { out = -1; prev = '-'; }
            else if (b1 == '1' && b2 == '1') { out = -3; prev = '-'; }
        } else {
            if (b1 == '0' && b2 == '0') { out = -1; prev = '-'; }
            else if (b1 == '0' && b2 == '1') { out = -3; prev = '-'; }
            else if (b1 == '1' && b2 == '0') { out = +1; prev = '+'; }
            else if (b1 == '1' && b2 == '1') { out = +3; prev = '+'; }
        }
        printf("| %+d ", out);
    }
    printf("|\n");

    return 0;
}

/*
Example Output:

Run 1:
Enter binary string (even length): 0011011001
2B1Q Encoded Output: | +1 | -3 | -3 | +1 | +3 |

Run 2:
Enter binary string (even length): 01011
Error: Length must be even for 2B1Q encoding.
*/
