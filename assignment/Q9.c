#include <stdio.h>
#define MAX 20
int main() {
    int g[MAX][MAX], visited[MAX] = {0};
    int q[MAX], n, start, front = 0, rear = 0;
    int i, j, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    if (start < 0 || start >= n) {
        printf("Invalid starting vertex");
        return 0;
    }
    visited[start] = 1;
    q[rear++] = start;
    printf("BFS traversal: ");
    while (front < rear) {
        v = q[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (g[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
    return 0;
}
