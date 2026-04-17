#include <stdio.h>

int n;
int visited[201];

void dfs(int city, int isConnected[201][201]) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i])
            dfs(i, isConnected);
    }
}

int main() {
    scanf("%d", &n);

    int isConnected[201][201];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &isConnected[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, isConnected);
            provinces++;
        }
    }

    printf("%d", provinces);
    return 0;
}