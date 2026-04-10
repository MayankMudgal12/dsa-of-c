#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int v, dist;
} HeapNode;

Node** adj;

void addEdge(int u, int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->w = w;
    n->next = adj[u];
    adj[u] = n;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(HeapNode heap[], int i) {
    while (i && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(HeapNode heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(HeapNode heap[], int* size, int v, int dist) {
    heap[*size].v = v;
    heap[*size].dist = dist;
    heapifyUp(heap, *size);
    (*size)++;
}

HeapNode pop(HeapNode heap[], int* size) {
    HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    HeapNode* heap = (HeapNode*)malloc(V * V * sizeof(HeapNode));
    int size = 0;

    push(heap, &size, src, 0);

    while (size > 0) {
        HeapNode top = pop(heap, &size);
        int u = top.v;

        if (top.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(heap, &size, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}