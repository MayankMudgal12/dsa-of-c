#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n;
    scanf("%d", &n);

    int points[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i][0], &points[i][1]);

    int key[n], mstSet[n];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    int totalCost = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        totalCost += key[u];

        for (int v = 0; v < n; v++) {
            if (!mstSet[v]) {
                int dist = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);
                if (dist < key[v])
                    key[v] = dist;
            }
        }
    }

    printf("%d", totalCost);
    return 0;
}