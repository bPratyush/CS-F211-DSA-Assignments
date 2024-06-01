#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TreeNode* buildTree(int* arr, int size) {
    if (size == 0) return NULL;

    TreeNode** nodes = malloc(size * sizeof(TreeNode*));
    for (int i = 0; i < size; ++i) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = createNode(arr[i]);
    }

    int parentIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (nodes[i] != NULL) {
            if (2 * parentIndex + 1 < size) nodes[i]->left = nodes[2 * parentIndex + 1];
            if (2 * parentIndex + 2 < size) nodes[i]->right = nodes[2 * parentIndex + 2];
            ++parentIndex;
        }
    }
    TreeNode* root = nodes[0];
    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, -1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = buildTree(arr, size);
    printf("Inorder traversal of the binary tree: ");
    inorder(root);
}
