#include <stdio.h>
#include <stdlib.h>

int hasCycle(int v, int parent, int visited[], int **adj, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycle(i, v, visited, adj, n))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int *visited = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1, visited, adj, n)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}