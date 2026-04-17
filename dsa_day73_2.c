#include <stdio.h>

int parent[1001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return 0;
    parent[pa] = pb;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int edges[n][2];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &edges[i][0], &edges[i][1]);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int u = -1, v = -1;

    for (int i = 0; i < n; i++) {
        if (!unionSet(edges[i][0], edges[i][1])) {
            u = edges[i][0];
            v = edges[i][1];
        }
    }

    printf("%d %d", u, v);
    return 0;
}