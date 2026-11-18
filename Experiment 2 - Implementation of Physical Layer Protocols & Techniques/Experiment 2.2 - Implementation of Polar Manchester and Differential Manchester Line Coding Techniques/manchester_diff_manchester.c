#include <stdio.h>

int main() {
    int n, data[50];

    printf("Enter number of data bits: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter data bits (0 or 1) separated by space: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Polar Manchester: 0 -> High to Low (+ to -), 1 -> Low to High (- to +)
    printf("\nPolar Manchester Encoding: ");
    for (int i = 0; i < n; i++) {
        if (data[i] == 0)
            printf("| + to - ");
        else
            printf("| - to + ");
    }
    printf("|\n");

    // Differential Manchester:
    // 0 -> no transition at start, transition in middle
    // 1 -> transition at start, transition in middle
    printf("Differential Manchester Encoding: ");
    int level = 1; // start assumption: high
    for (int i = 0; i < n; i++) {
        if (data[i] == 0) {
            // Keep previous level at start, transition in middle
            if (level == 1) {
                printf("| + to - ");
                level = 0;
            } else {
                printf("| - to + ");
                level = 1;
            }
        } else {
            // Invert level at start, transition in middle
            if (level == 1) {
                printf("| - to + ");
                level = 0;
            } else {
                printf("| + to - ");
                level = 1;
            }
        }
    }
    printf("|\n");

    return 0;
}

/*
Example Output:

Enter number of data bits: 8
Enter data bits (0 or 1) separated by space: 1 0 0 1 1 1 0 1

Polar Manchester Encoding: | - to + | + to - | + to - | - to + | - to + | - to + | + to - | - to + |
Differential Manchester Encoding: | - to + | + to - | + to - | - to + | + to - | - to + | + to - | - to + |
*/
