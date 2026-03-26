 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->val && n2 < root->val)
            root = root->left;
        else if (n1 > root->val && n2 > root->val)
            root = root->right;
        else
            return root->val;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int values[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("%d", findLCA(root, n1, n2));

    return 0;
}