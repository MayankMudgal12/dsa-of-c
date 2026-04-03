#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = v;
    node->next = NULL;
    return node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* node1 = createNode(v);
        node1->next = adj[u];
        adj[u] = node1;

        struct Node* node2 = createNode(u);
        node2->next = adj[v];
        adj[v] = node2;
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf(" %d", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}