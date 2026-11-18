#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[30];
    int prefix;

    printf("Enter subnet in CIDR format (e.g. 192.168.1.0/29): ");
    if (scanf("%29s", input) != 1) return 1;

    char *slash = strchr(input, '/');
    if (!slash) {
        printf("Error: Missing prefix length '/'\n");
        return 1;
    }

    *slash = '\0';
    prefix = atoi(slash + 1);

    int a, b, c, d;
    if (sscanf(input, "%d.%d.%d.%d", &a, &b, &c, &d) != 4) return 1;

    unsigned int addr = ((unsigned int)a << 24) | ((unsigned int)b << 16) | ((unsigned int)c << 8) | d;
    unsigned int mask = (prefix == 0) ? 0 : (~0U << (32 - prefix));
    unsigned int net = addr & mask;
    unsigned int bc = net | (~mask);

    printf("\nUsable IP addresses:\n");
    for (unsigned int host = net + 1; host < bc; host++) {
        printf("%u.%u.%u.%u\n",
               (host >> 24) & 255, (host >> 16) & 255, (host >> 8) & 255, host & 255);
    }

    return 0;
}

/*
Example Output:

Enter subnet in CIDR format (e.g. 192.168.1.0/29): 192.168.1.0/29

Usable IP addresses:
192.168.1.1
192.168.1.2
192.168.1.3
192.168.1.4
192.168.1.5
192.168.1.6
*/
