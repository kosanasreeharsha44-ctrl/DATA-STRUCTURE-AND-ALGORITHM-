#include <stdio.h>
#define MAX 20
#define INF 999999
int main() {
    int cost[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int n, source, i, j, u, min;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weighted adjacency matrix (0 = no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    if (source < 0 || source >= n) {
        printf("Invalid source vertex");
        return 0;
    }
    for (i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;
    for (i = 0; i < n; i++) {
        min = INF;
        u = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF &&
                dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }
    printf("Shortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
    return 0;
}
