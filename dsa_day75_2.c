#include <stdio.h>

int graph[100][100];
int size[100];
int color[100];

int queue[100];

int isBipartite(int n) {
    for (int i = 0; i < n; i++)
        color[i] = -1;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            int front = 0, rear = 0;
            queue[rear++] = i;
            color[i] = 0;

            while (front < rear) {
                int node = queue[front++];

                for (int j = 0; j < size[node]; j++) {
                    int adj = graph[node][j];

                    if (color[adj] == -1) {
                        color[adj] = 1 - color[node];
                        queue[rear++] = adj;
                    } else if (color[adj] == color[node]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++)
            scanf("%d", &graph[i][j]);
    }

    if (isBipartite(n))
        printf("true");
    else
        printf("false");

    return 0;
}