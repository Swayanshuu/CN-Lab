#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, attempt;
    char data[5][20];

    srand((unsigned int)time(NULL));

    printf("Enter number of stations (max 5): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 5) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter frame data for Station %d: ", i + 1);
        scanf("%19s", data[i]);
    }

    printf("\nCSMA/CD Simulation:\n");

    for (int i = 0; i < n; i++) {
        printf("\nStation %d attempting to transmit: \"%s\"\n", i + 1, data[i]);
        attempt = 0;

        while (attempt < 5) {
            int idle = rand() % 2; // 0 = busy, 1 = idle

            if (idle) {
                printf("  Medium is idle. Transmitting...\n");
                int collision = (rand() % 4 == 0); // 25% chance of collision

                if (collision) {
                    attempt++;
                    int backoff = rand() % (1 << attempt); // Binary exponential backoff
                    printf("  Collision detected! Backoff: waiting %d time units (Attempt %d)\n", backoff, attempt);
                } else {
                    printf("  Frame \"%s\" transmitted successfully by Station %d!\n", data[i], i + 1);
                    break;
                }
            } else {
                printf("  Medium is busy. Sensing again...\n");
            }
        }

        if (attempt == 5) {
            printf("  Station %d: Transmission failed after maximum attempts.\n", i + 1);
        }
    }

    printf("\nSimulation complete.\n");
    return 0;
}

/*
Example Output:

Enter number of stations (max 5): 3
Enter frame data for Station 1: FrameA
Enter frame data for Station 2: FrameB
Enter frame data for Station 3: FrameC

CSMA/CD Simulation:

Station 1 attempting to transmit: "FrameA"
  Medium is idle. Transmitting...
  Frame "FrameA" transmitted successfully by Station 1!

Station 2 attempting to transmit: "FrameB"
  Medium is idle. Transmitting...
  Collision detected! Backoff: waiting 1 time units (Attempt 1)
  Medium is idle. Transmitting...
  Frame "FrameB" transmitted successfully by Station 2!

Station 3 attempting to transmit: "FrameC"
  Medium is busy. Sensing again...
  Medium is idle. Transmitting...
  Frame "FrameC" transmitted successfully by Station 3!

Simulation complete.
*/
