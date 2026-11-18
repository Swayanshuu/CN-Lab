#include <stdio.h>

int main() {
    int n, w, i = 0, j;

    printf("Enter total number of frames: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter window size: ");
    if (scanf("%d", &w) != 1 || w <= 0) return 1;

    while (i < n) {
        printf("\nSending frames: ");
        for (j = i; j < i + w && j < n; j++) {
            printf("%d ", j);
        }
        printf("\n");

        int lost;
        printf("Enter lost frame index (-1 if all received): ");
        scanf("%d", &lost);

        if (lost >= i && lost < j) {
            printf("Frame %d lost! Go-Back-N: Retransmitting from frame %d\n", lost, lost);
            i = lost; // Go back to lost frame
        } else {
            printf("Frames in window received and acknowledged.\n");
            i = j; // Slide window forward
        }
    }

    printf("\nAll frames sent and acknowledged successfully!\n");
    return 0;
}

/*
Example Output:

Enter total number of frames: 6
Enter window size: 4

Sending frames: 0 1 2 3 
Enter lost frame index (-1 if all received): 2
Frame 2 lost! Go-Back-N: Retransmitting from frame 2

Sending frames: 2 3 4 5 
Enter lost frame index (-1 if all received): -1
Frames in window received and acknowledged.

All frames sent and acknowledged successfully!
*/
