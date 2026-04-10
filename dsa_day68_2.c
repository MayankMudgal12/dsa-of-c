#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int main() {
    int n;
    scanf("%d", &n);

    char words[505][105];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int len1 = strlen(words[i]);
        int len2 = strlen(words[i + 1]);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (words[i][j] != words[i + 1][j]) {
                int u = words[i][j] - 'a';
                int v = words[i + 1][j] - 'a';
                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        if (!found && len1 > len2) {
            printf("");
            return 0;
        }
    }

    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    char result[MAX];
    int idx = 0;

    while (front < rear) {
        int u = queue[front++];
        result[idx++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    if (idx != total) {
        printf("");
        return 0;
    }

    result[idx] = '\0';
    printf("%s", result);

    return 0;
}