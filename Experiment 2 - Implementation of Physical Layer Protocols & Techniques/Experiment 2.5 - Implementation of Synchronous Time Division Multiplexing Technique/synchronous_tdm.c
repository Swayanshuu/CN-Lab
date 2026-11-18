#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numChannels, frameSize;

    printf("Enter number of channels: ");
    if (scanf("%d", &numChannels) != 1 || numChannels <= 0) return 1;

    printf("Enter frame size (max chars per channel): ");
    if (scanf("%d", &frameSize) != 1 || frameSize <= 0) return 1;

    char **data = (char **)malloc(numChannels * sizeof(char *));
    for (int i = 0; i < numChannels; i++) {
        data[i] = (char *)malloc((frameSize + 1) * sizeof(char));
    }

    printf("\nInput Phase:\n");
    for (int i = 0; i < numChannels; i++) {
        printf("Enter data for channel %d (or '-' for empty): ", i + 1);
        scanf("%s", data[i]);
        data[i][frameSize] = '\0';
    }

    printf("\nTransmitting Frames (Round-Robin):\n");
    printf("Time Slot Order: ");
    for (int i = 0; i < numChannels; i++) {
        printf("CH%d ", i + 1);
    }
    printf("\n\n");

    for (int f = 0; f < frameSize; f++) {
        printf("Frame %d: ", f + 1);
        for (int c = 0; c < numChannels; c++) {
            if (f < strlen(data[c]) && data[c][0] != '-') {
                printf("%c  ", data[c][f]);
            } else {
                printf("-  "); // Empty slot placeholder
            }
        }
        printf("\n");
    }

    for (int i = 0; i < numChannels; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}

/*
Example Output:

Enter number of channels: 4
Enter frame size (max chars per channel): 7

Input Phase:
Enter data for channel 1 (or '-' for empty): India
Enter data for channel 2 (or '-' for empty): -
Enter data for channel 3 (or '-' for empty): America
Enter data for channel 4 (or '-' for empty): Network

Transmitting Frames (Round-Robin):
Time Slot Order: CH1 CH2 CH3 CH4 

Frame 1: I  -  A  N  
Frame 2: n  -  m  e  
Frame 3: d  -  e  t  
Frame 4: i  -  r  w  
Frame 5: a  -  i  o  
Frame 6: -  -  c  r  
Frame 7: -  -  a  k  
*/
