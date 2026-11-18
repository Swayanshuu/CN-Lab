#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK_SIZE 16

// Simulated UDP packet with header fields
struct UDP_Packet {
    int src_port;
    int dest_port;
    int length;
    char data[CHUNK_SIZE + 1];
};

int main() {
    char message[256];
    char received[256] = {0};

    printf("Enter message to send over UDP: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return 1;
    message[strcspn(message, "\r\n")] = '\0';

    int len = strlen(message);
    int total_packets = (len + CHUNK_SIZE - 1) / CHUNK_SIZE;

    printf("\n--- UDP Transmission ---\n");

    for (int i = 0; i < total_packets; i++) {
        struct UDP_Packet pkt;
        pkt.src_port = 4000;
        pkt.dest_port = 5000;

        int offset = i * CHUNK_SIZE;
        int chunk_len = (len - offset > CHUNK_SIZE) ? CHUNK_SIZE : (len - offset);

        strncpy(pkt.data, message + offset, chunk_len);
        pkt.data[chunk_len] = '\0';
        pkt.length = 8 + chunk_len; // 8 bytes UDP header + data

        printf("[Sender] Packet %d: Port %d -> %d | Length: %d bytes | Data: \"%s\"\n",
               i + 1, pkt.src_port, pkt.dest_port, pkt.length, pkt.data);

        // Receiver receives packet
        printf("[Receiver] Accepted Packet %d: \"%s\"\n", i + 1, pkt.data);
        strcat(received, pkt.data);
    }

    printf("\nReconstructed Message at Receiver:\n\"%s\"\n", received);

    return 0;
}

/*
Example Output:

Enter message to send over UDP: This program demonstrates UDP data transfer.

--- UDP Transmission ---
[Sender] Packet 1: Port 4000 -> 5000 | Length: 24 bytes | Data: "This program dem"
[Receiver] Accepted Packet 1: "This program dem"
[Sender] Packet 2: Port 4000 -> 5000 | Length: 24 bytes | Data: "onstrates UDP da"
[Receiver] Accepted Packet 2: "onstrates UDP da"
[Sender] Packet 3: Port 4000 -> 5000 | Length: 20 bytes | Data: "ta transfer."
[Receiver] Accepted Packet 3: "ta transfer."

Reconstructed Message at Receiver:
"This program demonstrates UDP data transfer."
*/
