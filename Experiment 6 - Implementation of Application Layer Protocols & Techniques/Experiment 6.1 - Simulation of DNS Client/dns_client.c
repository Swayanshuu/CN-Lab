#include <stdio.h>

#ifdef _WIN32
  #include <winsock2.h>
#else
  #include <netdb.h>
  #include <arpa/inet.h>
#endif

int main() {
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif

    char domain[100];
    struct hostent *host;

    printf("Enter domain name (e.g. google.com): ");
    if (scanf("%99s", domain) != 1) return 1;

    host = gethostbyname(domain);

    if (host == NULL) {
        printf("DNS lookup failed!\n");
        return 1;
    }

    printf("\nDNS Response:\n");
    printf("IP Address: %s\n", inet_ntoa(*((struct in_addr *)host->h_addr_list[0])));

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}

/*
Example Output:

Run 1:
Enter domain name (e.g. google.com): google.com

DNS Response:
IP Address: 142.250.183.14

Run 2:
Enter domain name (e.g. google.com): invalid.xyz
DNS lookup failed!
*/
