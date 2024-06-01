#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int val){
    TreeNode* node=malloc(sizeof(TreeNode));
    if(!node) return NULL;
    node->left=NULL;
    node->right=NULL;
    node->val=val;
    return node;
}

TreeNode* createTree(int a[] , int cur , int n){
    if(cur >= n || a[cur] == -1)
      return NULL;
    TreeNode* root = malloc(sizeof(TreeNode));
      root->val = a[cur];
      root->left = createTree(a , 2*cur+1 , n);
      root->right = createTree(a , 2*cur+2 , n);
     return root;
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int main(){
    TreeNode* n1=createNode(10);
    TreeNode* n2=createNode(12);
    TreeNode* n3=createNode(11);
    TreeNode* n4=createNode(13);
    n1->left=n2;
    n2->right=n3;
    n1->right=n4;
    inorder(n1);
}