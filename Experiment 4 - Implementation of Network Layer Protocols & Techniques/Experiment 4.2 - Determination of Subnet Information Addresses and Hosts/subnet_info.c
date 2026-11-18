#include <stdio.h>

int main() {
    int a, b, c, d;
    int m1, m2, m3, m4;

    printf("Enter IP address: ");
    if (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != 4) return 1;

    printf("Enter Subnet Mask: ");
    if (scanf("%d.%d.%d.%d", &m1, &m2, &m3, &m4) != 4) return 1;

    // Convert dotted decimal octets to 32-bit integers
    unsigned int ip = ((unsigned int)a << 24) | ((unsigned int)b << 16) | ((unsigned int)c << 8) | d;
    unsigned int mask = ((unsigned int)m1 << 24) | ((unsigned int)m2 << 16) | ((unsigned int)m3 << 8) | m4;

    unsigned int net = ip & mask;
    unsigned int bc = net | (~mask);
    unsigned int first = net + 1;
    unsigned int last = bc - 1;

    // Count 1s in mask to find prefix length
    int ones = 0;
    unsigned int temp = mask;
    while (temp) {
        ones += (temp & 1);
        temp >>= 1;
    }

    int usable = (ones < 31) ? ((1 << (32 - ones)) - 2) : 0;

    printf("\nNetwork Address  : %u.%u.%u.%u\n", (net >> 24) & 255, (net >> 16) & 255, (net >> 8) & 255, net & 255);
    printf("Broadcast Address: %u.%u.%u.%u\n", (bc >> 24) & 255, (bc >> 16) & 255, (bc >> 8) & 255, bc & 255);
    printf("First Host       : %u.%u.%u.%u\n", (first >> 24) & 255, (first >> 16) & 255, (first >> 8) & 255, first & 255);
    printf("Last Host        : %u.%u.%u.%u\n", (last >> 24) & 255, (last >> 16) & 255, (last >> 8) & 255, last & 255);
    printf("Usable Hosts     : %d\n", usable);

    return 0;
}

/*
Example Output:

Enter IP address: 192.168.4.8
Enter Subnet Mask: 255.255.255.0

Network Address  : 192.168.4.0
Broadcast Address: 192.168.4.255
First Host       : 192.168.4.1
Last Host        : 192.168.4.254
Usable Hosts     : 254
*/
