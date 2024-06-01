#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100005

// Structure to represent a node in the binary tree
struct TreeNode {
    int label;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int label) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform DFS traversal and count nodes at distance x
void dfs(struct TreeNode* root, int k, int x, int depth, int* count) {
    if (root == NULL) return;
    if (depth == x) {
        (*count)++;
        return;
    }
    dfs(root->left, k, x, depth + 1, count);
    dfs(root->right, k, x, depth + 1, count);
}

// Function to find the node with label k and start DFS traversal from it
void findNodeAndCount(struct TreeNode* root, int k, int x, int* count) {
    if (root == NULL) return;
    if (root->label == k) {
        dfs(root, k, x, 0, count);
        return;
    }
    findNodeAndCount(root->left, k, x, count);
    findNodeAndCount(root->right, k, x, count);
}

int main() {
    int N, k, x;
    scanf("%d %d %d", &N, &k, &x);

    int labels[MAX_NODES];
    for (int i = 0; i < N; i++) {
        scanf("%d", &labels[i]);
    }

    // Construct the binary tree
    struct TreeNode* nodes[MAX_NODES];
    for (int i = 1; i <= N; i++) {
        nodes[i] = createNode(labels[i - 1]);
    }
    for (int i = 1; i <= N / 2; i++) {
        nodes[i]->left = nodes[2 * i];
        if (2 * i + 1 <= N) {
            nodes[i]->right = nodes[2 * i + 1];
        }
    }

    int count = 0;
    findNodeAndCount(nodes[1], k, x, &count);
    
    printf("%d\n", count);

    return 0;
}
