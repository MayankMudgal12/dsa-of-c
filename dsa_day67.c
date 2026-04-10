#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node** adj;
int* visited;
int* stack;
int top = -1;

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->next = adj[u];
    adj[u] = n;
}

void dfs(int v) {
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->v])
            dfs(temp->v);
        temp = temp->next;
    }
    stack[++top] = v;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    adj = (Node**)malloc(V * sizeof(Node*));
    visited = (int*)calloc(V, sizeof(int));
    stack = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}