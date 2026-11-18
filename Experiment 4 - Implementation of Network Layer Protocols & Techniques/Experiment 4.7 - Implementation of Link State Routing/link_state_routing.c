#include <stdio.h>

#define INF 999

int main() {
    int n, cost[10][10], dist[10], visited[10], src;

    printf("Enter number of routers: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter cost matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source router (0 to %d): ", n - 1);
    scanf("%d", &src);

    // Dijkstra initialization
    for (int i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra main relaxation loop
    for (int count = 1; count < n; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest Distances from Router %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("  To Router %d = %d\n", i, dist[i]);
    }

    return 0;
}

/*
Example Output:

Enter number of routers: 4
Enter cost matrix (use 999 for infinity):
0 1 999 3
1 0 1 999
999 1 0 2
3 999 2 0
Enter source router (0 to 3): 0

Shortest Distances from Router 0:
  To Router 0 = 0
  To Router 1 = 1
  To Router 2 = 2
  To Router 3 = 3
*/
