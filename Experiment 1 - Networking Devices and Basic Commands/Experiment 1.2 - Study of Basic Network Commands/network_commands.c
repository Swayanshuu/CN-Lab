#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char target[100];
    char cmd[150];

    while (1) {
        printf("\nBasic Network Commands Menu:\n");
        printf("1. ipconfig (View IP details)\n");
        printf("2. ping (Check connectivity)\n");
        printf("3. tracert (Trace route to host)\n");
        printf("4. netstat (View active connections)\n");
        printf("5. nslookup (Query DNS for domain IP)\n");
        printf("6. arp -a (View ARP cache table)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1 || choice == 7) {
            break;
        }

        if (choice == 1) {
            system("ipconfig");
        } else if (choice == 2) {
            printf("Enter host to ping (e.g. google.com): ");
            scanf("%99s", target);
            snprintf(cmd, sizeof(cmd), "ping -n 4 %s", target);
            system(cmd);
        } else if (choice == 3) {
            printf("Enter host for tracert: ");
            scanf("%99s", target);
            snprintf(cmd, sizeof(cmd), "tracert -d -h 5 %s", target);
            system(cmd);
        } else if (choice == 4) {
            system("netstat -an | more");
        } else if (choice == 5) {
            printf("Enter domain name: ");
            scanf("%99s", target);
            snprintf(cmd, sizeof(cmd), "nslookup %s", target);
            system(cmd);
        } else if (choice == 6) {
            system("arp -a");
        }
    }

    return 0;
}

/*
Example Output:

Basic Network Commands Menu:
1. ipconfig (View IP details)
2. ping (Check connectivity)
3. tracert (Trace route to host)
4. netstat (View active connections)
5. nslookup (Query DNS for domain IP)
6. arp -a (View ARP cache table)
7. Exit
Enter your choice: 2
Enter host to ping (e.g. google.com): 127.0.0.1

Pinging 127.0.0.1 with 32 bytes of data:
Reply from 127.0.0.1: bytes=32 time<1ms TTL=128
Reply from 127.0.0.1: bytes=32 time<1ms TTL=128
Reply from 127.0.0.1: bytes=32 time<1ms TTL=128
Reply from 127.0.0.1: bytes=32 time<1ms TTL=128

Ping statistics for 127.0.0.1:
    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)
*/
