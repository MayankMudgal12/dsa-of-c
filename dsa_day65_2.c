#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node** adj;

void addEdge(int u, int v) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->v = v;
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->v = u;
    n2->next = adj[v];
    adj[v] = n2;
}

int dfs(int v, int parent, int visited[]) {
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp) {
        int x = temp->v;
        if (!visited[x]) {
            if (dfs(x, v, visited))
                return 1;
        } else if (x != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int* visited = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited)) {
                printf("true");
                return 0;
            }
        }
    }

    printf("false");
    return 0;
}