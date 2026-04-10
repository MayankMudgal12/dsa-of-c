#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node** adj;
int* visited;
int* rec;
int* stack;
int top = -1;

void addEdge(int u, int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->next = adj[u];
    adj[u] = n;
}

int dfs(int v) {
    visited[v] = 1;
    rec[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        int x = temp->v;
        if (!visited[x]) {
            if (!dfs(x))
                return 0;
        } else if (rec[x]) {
            return 0;
        }
        temp = temp->next;
    }

    rec[v] = 0;
    stack[++top] = v;
    return 1;
}

int main() {
    int numCourses, p;
    scanf("%d %d", &numCourses, &p);

    adj = (Node**)malloc(numCourses * sizeof(Node*));
    visited = (int*)calloc(numCourses, sizeof(int));
    rec = (int*)calloc(numCourses, sizeof(int));
    stack = (int*)malloc(numCourses * sizeof(int));

    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    for (int i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(b, a);
    }

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (!dfs(i)) {
                printf("[]");
                return 0;
            }
        }
    }

    printf("[");
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(",");
    }
    printf("]");

    return 0;
}