#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node** adj;

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->next = adj[u];
    adj[u] = n;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) adj[i] = NULL;

    int* indegree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        indegree[v]++;
    }

    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        Node* temp = adj[node];
        while (temp) {
            indegree[temp->v]--;
            if (indegree[temp->v] == 0)
                queue[rear++] = temp->v;
            temp = temp->next;
        }
    }

    if (count != V) {
        printf("\nCycle detected");
    }

    return 0;
}