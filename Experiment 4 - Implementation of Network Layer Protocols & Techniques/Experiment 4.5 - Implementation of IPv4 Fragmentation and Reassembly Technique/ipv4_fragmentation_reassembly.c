#include <stdio.h>
#include <string.h>

#define HEADER_SIZE 20

// Structure representing an IPv4 fragment
struct Fragment {
    int id;
    int offset;
    int mf;       // More Fragments flag (1 = more fragments follow, 0 = last fragment)
    int total_len;
    char data[100];
};

int main() {
    char message[500];
    int mtu;
    struct Fragment frags[20];
    int num_frags = 0;

    printf("Enter message to fragment: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return 1;
    message[strcspn(message, "\r\n")] = '\0';

    printf("Enter MTU size (e.g. 50): ");
    if (scanf("%d", &mtu) != 1) return 1;

    int max_payload = mtu - HEADER_SIZE;
    if (max_payload <= 0) {
        printf("MTU too small for 20-byte IP header.\n");
        return 1;
    }

    // Round payload size to multiple of 8 (IPv4 offset standard)
    int payload_size = (max_payload / 8) * 8;
    if (payload_size <= 0) payload_size = max_payload;

    int msg_len = strlen(message);
    int offset = 0, index = 0;

    // Fragmenting the message
    while (index < msg_len) {
        int copy_len = (msg_len - index > payload_size) ? payload_size : (msg_len - index);

        frags[num_frags].id = 12345;
        frags[num_frags].offset = offset / 8; // Offset in 8-byte units
        strncpy(frags[num_frags].data, message + index, copy_len);
        frags[num_frags].data[copy_len] = '\0';

        index += copy_len;
        offset += copy_len;

        frags[num_frags].mf = (index < msg_len) ? 1 : 0;
        frags[num_frags].total_len = HEADER_SIZE + copy_len;

        num_frags++;
    }

    printf("\nGenerated %d Fragments:\n", num_frags);
    for (int i = 0; i < num_frags; i++) {
        printf("Fragment %d: Total Length = %d, Offset = %d (Bytes: %d), MF = %d, Data = \"%s\"\n",
               i + 1, frags[i].total_len, frags[i].offset, frags[i].offset * 8, frags[i].mf, frags[i].data);
    }

    // Reassembling at receiver
    char reassembled[500] = {0};
    for (int i = 0; i < num_frags; i++) {
        strcat(reassembled, frags[i].data);
    }

    printf("\nReassembled Message:\n\"%s\"\n", reassembled);

    return 0;
}

/*
Example Output:

Enter message to fragment: Indira Gandhi Institute of Technology
Enter MTU size (e.g. 50): 50

Generated 2 Fragments:
Fragment 1: Total Length = 44, Offset = 0 (Bytes: 0), MF = 1, Data = "Indira Gandhi Institute "
Fragment 2: Total Length = 34, Offset = 3 (Bytes: 24), MF = 0, Data = "of Technology"

Reassembled Message:
"Indira Gandhi Institute of Technology"
*/
