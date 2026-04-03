#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int preIndex;

struct TreeNode* create(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int find(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int start, int end) {
    if (start > end)
        return NULL;

    int val = preorder[preIndex++];
    struct TreeNode* root = create(val);

    if (start == end)
        return root;

    int index = find(inorder, start, end, val);

    root->left = build(preorder, inorder, start, index - 1);
    root->right = build(preorder, inorder, index + 1, end);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}