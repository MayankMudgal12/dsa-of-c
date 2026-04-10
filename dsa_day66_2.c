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

int dfs(int v, int visited[], int rec[]) {
    visited[v] = 1;
    rec[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        int x = temp->v;
        if (!visited[x]) {
            if (dfs(x, visited, rec))
                return 1;
        } else if (rec[x]) {
            return 1;
        }
        temp = temp->next;
    }

    rec[v] = 0;
    return 0;
}

int main() {
    int numCourses, p;
    scanf("%d %d", &numCourses, &p);

    adj = (Node**)malloc(numCourses * sizeof(Node*));
    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    for (int i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(b, a);
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* rec = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, rec)) {
                printf("false");
                return 0;
            }
        }
    }

    printf("true");
    return 0;
}