#include <stdio.h>

int main() {
    int n, data[20], lost;

    printf("Enter number of frames: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter data for frame %d: ", i);
        scanf("%d", &data[i]);
    }

    printf("\nTransmitting frames:\n");
    for (int i = 0; i < n; i++) {
        printf("Frame %d sent (Data: %d)\n", i, data[i]);
    }

    printf("\nEnter lost frame index (-1 if none): ");
    scanf("%d", &lost);

    if (lost >= 0 && lost < n) {
        // Selective Repeat retransmits ONLY the lost frame
        printf("\nSelective Repeat triggered: Retransmitting ONLY Frame %d (Data: %d)\n", lost, data[lost]);
        printf("Frame %d acknowledged.\n", lost);
    } else {
        printf("\nAll frames acknowledged without loss.\n");
    }

    printf("\nAll frames successfully transmitted!\n");
    return 0;
}

/*
Example Output:

Enter number of frames: 5
Enter data for frame 0: 11
Enter data for frame 1: 22
Enter data for frame 2: 33
Enter data for frame 3: 44
Enter data for frame 4: 55

Transmitting frames:
Frame 0 sent (Data: 11)
Frame 1 sent (Data: 22)
Frame 2 sent (Data: 33)
Frame 3 sent (Data: 44)
Frame 4 sent (Data: 55)

Enter lost frame index (-1 if none): 2

Selective Repeat triggered: Retransmitting ONLY Frame 2 (Data: 33)
Frame 2 acknowledged.

All frames successfully transmitted!
*/
