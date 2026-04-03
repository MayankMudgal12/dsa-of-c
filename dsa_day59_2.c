#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int postIndex;

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

struct TreeNode* build(int* inorder, int* postorder, int start, int end) {
    if (start > end)
        return NULL;

    int val = postorder[postIndex--];
    struct TreeNode* root = create(val);

    if (start == end)
        return root;

    int index = find(inorder, start, end, val);

    root->right = build(inorder, postorder, index + 1, end);
    root->left = build(inorder, postorder, start, index - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1);
}