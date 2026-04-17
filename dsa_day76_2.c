#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* visited[101];

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = 0;
    node->neighbors = NULL;
    return node;
}

struct Node* cloneGraph(struct Node* node) {
    if (!node) return NULL;

    if (visited[node->val])
        return visited[node->val];

    struct Node* clone = createNode(node->val);
    visited[node->val] = clone;

    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}