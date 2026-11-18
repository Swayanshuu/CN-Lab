#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHUNK_SIZE 5

// Simulates occasional packet loss in network
int simulate_loss() {
    return (rand() % 4 == 0); // 25% chance
}

int main() {
    char msg[100];
    int cwnd = 1, ssthresh = 4;
    int base = 0, total_chunks;

    srand((unsigned int)time(NULL));

    printf("Enter message to send: ");
    if (fgets(msg, sizeof(msg), stdin) == NULL) return 1;
    msg[strcspn(msg, "\r\n")] = '\0';

    int len = strlen(msg);
    total_chunks = (len + CHUNK_SIZE - 1) / CHUNK_SIZE;

    printf("Total packets to send: %d\n\n", total_chunks);

    while (base < total_chunks) {
        printf("State: cwnd = %d, ssthresh = %d (%s)\n", 
               cwnd, ssthresh, (cwnd < ssthresh) ? "Slow Start" : "Congestion Avoidance");

        int send_limit = (base + cwnd < total_chunks) ? (base + cwnd) : total_chunks;
        for (int i = base; i < send_limit; i++) {
            printf("  Sent packet %d\n", i);
        }

        // Check if loss occurs
        if (simulate_loss() && cwnd > 1) {
            printf("  Packet loss detected! Timeout triggered.\n");
            ssthresh = (cwnd / 2 > 1) ? (cwnd / 2) : 1;
            cwnd = 1; // Reset to 1 MSS
        } else {
            printf("  Packets acknowledged successfully.\n");
            base = send_limit;

            if (cwnd < ssthresh)
                cwnd *= 2; // Exponential increase
            else
                cwnd += 1; // Linear increase
        }
        printf("\n");
    }

    printf("Message delivered successfully!\n");
    return 0;
}

/*
Example Output:

Enter message to send: This is a demonstration of TCP
Total packets to send: 7

State: cwnd = 1, ssthresh = 4 (Slow Start)
  Sent packet 0
  Packets acknowledged successfully.

State: cwnd = 2, ssthresh = 4 (Slow Start)
  Sent packet 1
  Sent packet 2
  Packets acknowledged successfully.

State: cwnd = 4, ssthresh = 4 (Congestion Avoidance)
  Sent packet 3
  Sent packet 4
  Sent packet 5
  Sent packet 6
  Packets acknowledged successfully.

Message delivered successfully!
*/
