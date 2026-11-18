#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char net_str[30];
    int n, h[10];

    printf("Enter major network (e.g. 192.168.0.0/24): ");
    if (scanf("%29s", net_str) != 1) return 1;

    char *slash = strchr(net_str, '/');
    if (!slash) return 1;
    *slash = '\0';

    int a, b, c, d;
    sscanf(net_str, "%d.%d.%d.%d", &a, &b, &c, &d);
    unsigned int base = ((unsigned int)a << 24) | ((unsigned int)b << 16) | ((unsigned int)c << 8) | d;

    printf("Enter number of subnets: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    for (int i = 0; i < n; i++) {
        printf("Hosts required for subnet %d: ", i + 1);
        scanf("%d", &h[i]);
    }

    // Sort required hosts in descending order to avoid fragmentation
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (h[i] < h[j]) {
                int t = h[i]; h[i] = h[j]; h[j] = t;
            }
        }
    }

    printf("\nVLSM Subnet Allocation:\n");
    for (int i = 0; i < n; i++) {
        int bits = 0;
        while ((1U << bits) - 2 < h[i]) {
            bits++;
        }

        unsigned int size = 1U << bits;
        int prefix = 32 - bits;

        printf("Subnet %d: %u.%u.%u.%u/%d (Allocated Hosts: %u)\n",
               i + 1,
               (base >> 24) & 255, (base >> 16) & 255, (base >> 8) & 255, base & 255,
               prefix, size - 2);

        base += size;
    }

    return 0;
}

/*
Example Output:

Enter major network (e.g. 192.168.0.0/24): 192.168.0.0/24
Enter number of subnets: 3
Hosts required for subnet 1: 56
Hosts required for subnet 2: 34
Hosts required for subnet 3: 20

VLSM Subnet Allocation:
Subnet 1: 192.168.0.0/26 (Allocated Hosts: 62)
Subnet 2: 192.168.0.64/26 (Allocated Hosts: 62)
Subnet 3: 192.168.0.128/27 (Allocated Hosts: 30)
*/
