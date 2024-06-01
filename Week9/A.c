#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int max(int a,int b){
    if(a>b) return a;
    return b;
}

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
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

int dp(TreeNode* root, int *res){
        if(!root) return 0;
        int leftSum = dp(root->left, res);
        int rightSum = dp(root->right, res);
        int pathSum = max(root->val + max(leftSum, rightSum), root->val);
        int totalSum = max(pathSum, root->val + leftSum + rightSum);
        *res = max(*res, totalSum);
        return pathSum;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dp(root, &res);
        return res;
    }

void printTree(TreeNode* root){
    if(!root) return;
    printTree(root->left);
    printf("%d ",root->val);
    printTree(root->right);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    TreeNode** queue = malloc(sizeof(TreeNode*) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        TreeNode* temp = queue[front++];
        printf("%d ", temp->val);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    TreeNode* root = buildTree(a,n);
    printTree(root);
    printf("\n");
    printLevelOrder(root);
    printf("%d\n", maxPathSum(root));
}

