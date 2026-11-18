#include <stdio.h>
#include <string.h>

int main() {
    char data[100];

    // Phase 1: 3-way handshake connection establishment
    printf("--- Connection Establishment (3-Way Handshake) ---\n");
    printf("Client -> SYN      [SEQ: 100, ACK: 0]\n");
    printf("Server -> SYN-ACK  [SEQ: 300, ACK: 101]\n");
    printf("Client -> ACK      [SEQ: 101, ACK: 301]\n");
    printf("Connection Established Successfully!\n");

    // Phase 2: Data transmission
    printf("\n--- Data Transfer ---\n");
    printf("Enter message to send: ");
    if (fgets(data, sizeof(data), stdin) == NULL) return 1;
    data[strcspn(data, "\r\n")] = '\0';

    printf("Client -> DATA     [SEQ: 101, Data: \"%s\"]\n", data);
    printf("Server -> ACK      [ACK: %d, Data acknowledged]\n", 101 + (int)strlen(data));

    // Phase 3: 4-way handshake connection teardown
    printf("\n--- Connection Termination (4-Way Handshake) ---\n");
    printf("Client -> FIN      [SEQ: 200]\n");
    printf("Server -> ACK      [ACK: 201]\n");
    printf("Server -> FIN      [SEQ: 400]\n");
    printf("Client -> ACK      [ACK: 401]\n");
    printf("Connection Terminated Successfully!\n");

    return 0;
}

/*
Example Output:

--- Connection Establishment (3-Way Handshake) ---
Client -> SYN      [SEQ: 100, ACK: 0]
Server -> SYN-ACK  [SEQ: 300, ACK: 101]
Client -> ACK      [SEQ: 101, ACK: 301]
Connection Established Successfully!

--- Data Transfer ---
Enter message to send: Hello Server
Client -> DATA     [SEQ: 101, Data: "Hello Server"]
Server -> ACK      [ACK: 113, Data acknowledged]

--- Connection Termination (4-Way Handshake) ---
Client -> FIN      [SEQ: 200]
Server -> ACK      [ACK: 201]
Server -> FIN      [SEQ: 400]
Client -> ACK      [ACK: 401]
Connection Terminated Successfully!
*/
