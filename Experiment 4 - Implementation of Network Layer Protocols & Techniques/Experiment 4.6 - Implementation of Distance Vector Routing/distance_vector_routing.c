#include <stdio.h>

#define INF 999

int main() {
    int n, cost[10][10], dist[10][10];

    printf("Enter number of routers: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter cost matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }

    // Bellman-Ford algorithm: exchange distance vectors until shortest paths found
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > cost[i][k] + dist[k][j]) {
                    dist[i][j] = cost[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nFinal Routing Tables:\n");
    for (int i = 0; i < n; i++) {
        printf("\nRouter %d:\n", i);
        for (int j = 0; j < n; j++) {
            printf("  To %d -> Cost = %d\n", j, dist[i][j]);
        }
    }

    return 0;
}

/*
Example Output:

Enter number of routers: 4
Enter cost matrix (use 999 for infinity):
0 5 7 9
5 0 11 22
7 11 0 34
9 22 34 0

Final Routing Tables:

Router 0:
  To 0 -> Cost = 0
  To 1 -> Cost = 5
  To 2 -> Cost = 7
  To 3 -> Cost = 9

Router 1:
  To 0 -> Cost = 5
  To 1 -> Cost = 0
  To 2 -> Cost = 11
  To 3 -> Cost = 14

Router 2:
  To 0 -> Cost = 7
  To 1 -> Cost = 11
  To 2 -> Cost = 0
  To 3 -> Cost = 16

Router 3:
  To 0 -> Cost = 9
  To 1 -> Cost = 14
  To 2 -> Cost = 16
  To 3 -> Cost = 0
*/
