#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int hd;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    node->hd = 0;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    free(queue);
    return root;
}

void findMinMax(struct Node* root, int hd, int* min, int* max) {
    if (!root) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, hd - 1, min, max);
    findMinMax(root->right, hd + 1, min, max);
}

void printVertical(struct Node* root, int line, int hd) {
    if (!root) return;
    if (hd == line) printf("%d ", root->val);
    printVertical(root->left, line, hd - 1);
    printVertical(root->right, line, hd + 1);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int min = 0, max = 0;
    findMinMax(root, 0, &min, &max);

    for (int i = min; i <= max; i++) {
        printVertical(root, i, 0);
        printf("\n");
    }

    return 0;
}