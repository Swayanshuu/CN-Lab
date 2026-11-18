#include <stdio.h>
#include <string.h>

#define FLAG '#'
#define ESC '\\'

int main() {
    char data[100], stuffed[200], destuffed[100];

    printf("Enter string data (e.g. IGIT#Sar\\ang): ");
    scanf("%99s", data);

    // Stuffing: add FLAG at start and end; prepend ESC before any FLAG or ESC
    int j = 0;
    stuffed[j++] = FLAG;
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == FLAG || data[i] == ESC) {
            stuffed[j++] = ESC;
        }
        stuffed[j++] = data[i];
    }
    stuffed[j++] = FLAG;
    stuffed[j] = '\0';

    printf("\nStuffed Frame : %s\n", stuffed);

    // Destuffing: strip outer flags and remove ESC
    int k = 0;
    int len = strlen(stuffed);
    for (int i = 1; i < len - 1; i++) {
        if (stuffed[i] == ESC) {
            i++; // skip ESC and take literal char
        }
        destuffed[k++] = stuffed[i];
    }
    destuffed[k] = '\0';

    printf("Destuffed Data: %s\n", destuffed);

    return 0;
}

/*
Example Output:

Run 1:
Enter string data (e.g. IGIT#Sar\ang): IGITSarang

Stuffed Frame : #IGITSarang#
Destuffed Data: IGITSarang

Run 2:
Enter string data (e.g. IGIT#Sar\ang): IGIT#Sar\ang

Stuffed Frame : #IGIT\#Sar\\ang#
Destuffed Data: IGIT#Sar\ang
*/
