#include <stdio.h>

int main() {
    char ip[20];
    int a, b, c, d, pos;

    printf("Enter IPv4 address: ");
    if (scanf("%19s", ip) != 1) return 1;

    // Validate 4 octets and boundary range (0 - 255)
    if (sscanf(ip, "%d.%d.%d.%d%n", &a, &b, &c, &d, &pos) != 4 ||
        ip[pos] != '\0' ||
        a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255) {
        printf("Invalid IPv4 address.\n");
        return 0;
    }

    printf("Valid IPv4 address.\n");

    // Determine class based on first octet
    if (a >= 1 && a <= 126)
        printf("Class A\n");
    else if (a >= 128 && a <= 191)
        printf("Class B\n");
    else if (a >= 192 && a <= 223)
        printf("Class C\n");
    else if (a >= 224 && a <= 239)
        printf("Class D (Multicast)\n");
    else if (a >= 240 && a <= 254)
        printf("Class E (Experimental)\n");
    else
        printf("Special / Loopback Address\n");

    return 0;
}

/*
Example Output:

Run 1:
Enter IPv4 address: 192.168.1.10
Valid IPv4 address.
Class C

Run 2:
Enter IPv4 address: 192.168.1.256
Invalid IPv4 address.
*/
