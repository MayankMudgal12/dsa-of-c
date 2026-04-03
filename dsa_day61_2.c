#include <stdio.h>

void dfs(int** isConnected, int n, int* visited, int i) {
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            visited[j] = 1;
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(isConnected, n, visited, i);
            count++;
        }
    }

    return count;
}