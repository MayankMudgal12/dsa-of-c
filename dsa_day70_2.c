#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[n];
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < temp[v])
                temp[v] = dist[u] + w;
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    if (dist[dst] == INT_MAX)
        printf("-1");
    else
        printf("%d", dist[dst]);

    return 0;
}