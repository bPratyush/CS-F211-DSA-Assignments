//A
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* createTree(int a[], int cur_idx, int n) {
    if (cur_idx >= n || a[cur_idx] == -1) return NULL;
    Node* node = malloc(sizeof(Node));
    node->val = a[cur_idx];
    node->left = createTree(a, 2 * cur_idx + 1, n);
    node->right = createTree(a, 2 * cur_idx + 2, n);
    return node;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int max(int a , int b){
    return a>b?a:b;
}

int dp(Node* root, int *res){
        if(!root) return 0;
        int leftSum = dp(root->left, res);
        int rightSum = dp(root->right, res);
        int pathSum = max(root->val + max(leftSum, rightSum), root->val);
        int totalSum = max(pathSum, root->val + leftSum + rightSum);
        *res = max(*res, totalSum);
        return pathSum;
    }
int maxPathSum(Node* root) {
        int res = INT8_MIN;
        dp(root, res);
        return res;
    }

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    Node* root = createTree(a, 0, n);
    solution(root);
    printf("%d" , answer);
}


//B
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* createTree(int a[] , int cur , int n){
    if(cur >= n || a[cur] == -1) return NULL;
    Node* root = malloc(sizeof(Node));
    root->val = a[cur];
    root->left = createTree(a , 2*cur+1 , n);
    root->right = createTree(a , 2*cur+2 , n);
    return root;
}
bool flag = true;
Node* findNode(Node* root , int value){
    if(!root) return NULL;
    if(root->val == value) return root;
    findNode(root->left , value);
    findNode(root->right , value);
}
 void simultaneousDfs(Node* root1 , Node* root2){
    if(!root1 && !root2) return;
    if(!root1 || !root2) {
        flag = false;
        return;
    }
    if(root1->val != root2->val) flag = false;
     simultaneousDfs(root1->left ,  root2->left);
     simultaneousDfs(root2->right , root2->right);
 }
int main(){
    int n1 , n2;
    scanf("%d %d" , &n1 , &n2);
    int a[n1] , b[n2];
    for(int i=0;i<n1;i++) scanf("%d" , &a[i]);
    for(int i=0;i<n2;i++) scanf("%d" , &b[i]);
    Node* root = createTree(a,0,n1);
    Node* sub_root = createTree(b,0,n2);
    Node* at = findNode(root , sub_root->val);
    if(at)
    simultaneousDfs(at , sub_root);
    if(flag && at)
    printf("WIN");
    else
    printf("LOSS");
}

//C
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef long long ll;
typedef struct Node{
    int val;
   struct Node* left;
   struct Node* right;
}Node;
int flag = -1;
Node* findParent(Node* root , Node* parent , int k){
    if(!root) return NULL;
    if(root->val == k) {
       if(parent->left == root) flag = 0;
       else if(parent->right == root) flag = 1;
        return parent;
    }
    findParent(root->left , root , k);
    findParent(root->right , root , k);
}
Node* createTree(int a[] , int cur , int n){
    if(cur >= n || a[cur] == -1)return NULL;
    Node* root = (Node*)malloc(sizeof(Node));
      root->val = a[cur];
      root->left = createTree(a , 2*cur+1 , n);
      root->right = createTree(a , 2*cur+2 , n);
     return root;
}
int maxDepth(Node* root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        int h = max(l,r)+1;
        return h;
    }
int main(){
    int n , k;
    scanf("%d %d" , &n , &k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d" , &a[i]);
    Node* root = createTree(a , 0 , n);
    Node* parent = findParent(root , NULL , k); 
    if(!flag) parent->left = NULL;
    else parent->right = NULL;
    printf("%d" , findHeight(root));
}

//D
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct Queue{
    Node **a;
    int  f;
    int  r;
    int fals;
}Queue;
Node* front(Queue* qt){
    return  qt->a[qt->f];
}
void pop(Queue* qt){
    qt->f++;
}
void push(Queue* qt , Node* node){
    qt->a[qt->r++] = node;
}
int empty(Queue* qt){
    return qt->r == qt->f;
}
int size(Queue* qt){
    return qt->r-qt->f;
}
int cur = 0;
Node* createTree(int inorder[] , int preorder[] , int low , int high , int n){
    if(cur >= n || low>high) return NULL;
    Node* root = (Node*)malloc(sizeof(Node));
    root->val = preorder[cur++];
    int idx;
    for(int i=low;i<=high;i++){ 
        if(inorder[i] == root->val)
         idx = i;
    }
    root->left = createTree(inorder , preorder , low , idx-1 , n);
    root->right = createTree(inorder , preorder , idx+1 , high , n);
    return root;
}
void levelorder(Node* root , int n){
   Queue* qt = (Queue*)malloc(sizeof(Queue));
   qt->a = (Node**)malloc(sizeof(Node)*n);
   qt->f = 0;
     push(qt , root);
   while(!empty(qt)){
       int sz = size(qt);
      for(int i=0;i<sz;i++){ 
       Node* a = front(qt);
       pop(qt);
       printf("%d " , a->val);
       if(a->left) push(qt , a->left);
       if(a->right) push(qt , a->right);
      }
   }
}
int main(){
    int n;
    scanf("%d" , &n);
    int preorder[n];
    int inorder[n];
    for(int i=0;i<n;i++) scanf("%d" , &inorder[i]);
    for(int i=0;i<n;i++) scanf("%d" , &preorder[i]);
    Node* root = createTree(inorder , preorder  , 0 , n-1 , n);
    levelorder(root  ,n);
    return 0;
}

//F
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
  int val;
  struct Node* left;
  struct Node* right;
}Node;
Node* createTree(int a[] , int cur , int n){
    if(cur >= n || a[cur] == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = a[cur];
    node->left = createTree(a , 2*cur+1 , n);
    node->right = createTree(a , 2*cur+2 , n);
    return node;
}
int x=0;
void findKthLargest(Node* root, int k){
    if(root){
     findKthLargest(root->right, k);
       printf("%d " , root->val);
      findKthLargest(root->left , k); 
    }
}
int main(){
    int n , k;
    scanf("%d %d" , &n , &k);
    int a[n];
    for(int i=0;i<n;i++)
     scanf("%d" , &a[i]);
    Node* root = createTree(a ,0 , n);
    findKthLargest(root , k);
}

//G
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* createTree(int a[] , int cur , int n)
{  if(a[cur] == -1 || cur >= n)  return NULL;
   Node* root = malloc(sizeof(Node));
   root->val = a[cur];
   root->left = createTree(a , 2*cur+1 , n);
   root->right = createTree(a , 2*cur+2 , n);
   return root;
}
Node*  findLCA(Node* root , int p , int q){
    if(!root) return NULL;
        else if(root == p || root == q) return root;
        Node* lft = findLCA(root->left,p,q);
        Node* rgt = findLCA(root->right,p,q);
        if(!lft) return rgt;
        if(!rgt) return lft;
        return root;
}
int main(){
    int n , a , b;
    scanf("%d %d %d" , &n , &a , &b);
    int ar[n];
    for(int i=0;i<n;i++) scanf("%d" , &ar[i]);
    Node* root = createTree(ar , 0 , n);
    Node* p = findLCA(root , a , b);
    printf("%d" , p->val);
}

//H
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* buildBinaryTree(int arr[], int n) {
    if (n == 0) return NULL; 
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0, i = 1;
    queue[rear++] = root;
    while (front < rear && i < n) {
        struct TreeNode* node = queue[front++];
        if (arr[i] != -1) {
            node->left = createNode(arr[i]);
            queue[rear++] = node->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            node->right = createNode(arr[i]);
            queue[rear++] = node->right;
        }
        i++;
    }
    return root;
}

void dfs(struct TreeNode* node, int depth, int* total_distance) {
    if (node == NULL) return;
    *total_distance += depth;
    dfs(node->left, depth + 1, total_distance);
    dfs(node->right, depth + 1, total_distance);
}

int sumOfDistances(struct TreeNode* root) {
    int total_distance = 0;
    dfs(root, 0, &total_distance);
    return total_distance;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct TreeNode* root = buildBinaryTree(arr, n);
    printf("%d\n", sumOfDistances(root));
}

//I
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Red-Black Tree Node Structure
typedef enum {RED, BLACK} Color;

typedef struct TreeNode {
    int val;
    Color color;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (node) {
        node->val = val;
        node->color = RED; // New node is always red
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
    }
    return node;
}

// Function prototypes
void leftRotate(TreeNode** root, TreeNode* x);
void rightRotate(TreeNode** root, TreeNode* x);
void fixViolation(TreeNode** root, TreeNode* pt);
void insert(TreeNode** root, int val);
void levelOrderTraversal(TreeNode* root);

// Left Rotation
void leftRotate(TreeNode** root, TreeNode* x) {
    TreeNode* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Right Rotation
void rightRotate(TreeNode** root, TreeNode* y) {
    TreeNode* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

// Fix Red-Black Tree Violations
void fixViolation(TreeNode** root, TreeNode* pt) {
    TreeNode* parent_pt = NULL;
    TreeNode* grand_parent_pt = NULL;

    while ((pt != *root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        // Case : Parent of pt is left child of Grand-parent of pt
        if (parent_pt == grand_parent_pt->left) {
            TreeNode* uncle_pt = grand_parent_pt->right;

            // Case : The uncle of pt is also red
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Case : pt is right child of its parent
                if (pt == parent_pt->right) {
                    leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Case : pt is left child of its parent
                rightRotate(root, grand_parent_pt);
                Color temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        } else {
            // Case : Parent of pt is right child of Grand-parent of pt
            TreeNode* uncle_pt = grand_parent_pt->left;

            // Case : The uncle of pt is also red
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Case : pt is left child of its parent
                if (pt == parent_pt->left) {
                    rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Case : pt is right child of its parent
                leftRotate(root, grand_parent_pt);
                Color temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        }
    }
    (*root)->color = BLACK;
}

// Insertion
void insert(TreeNode** root, int val) {
    // Ordinary Binary Search Insertion
    TreeNode* new_node = createNode(val);
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    TreeNode* pt = *root;
    TreeNode* parent = NULL;
    while (pt != NULL) {
        parent = pt;
        if (val < pt->val) {
            pt = pt->left;
        } else {
            pt = pt->right;
        }
    }
    new_node->parent = parent;
    if (parent == NULL) {
        *root = new_node;
    } else if (val < parent->val) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    // Fix Red-Black Tree Violations
    fixViolation(root, new_node);
}

// Level-order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    // Create a queue for level order traversal
    TreeNode* queue[1000000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        TreeNode* temp = queue[front++];
        printf("%d ", temp->val);
        if (temp->left != NULL) queue[rear++] = temp->left;
        if (temp->right != NULL) queue[rear++] = temp->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) insert(&root, arr[i]);
    levelOrderTraversal(root);
}

//J
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int answer=0;
typedef struct Node{
    int val;
   struct  Node* right;
    struct Node* left;
}Node;
Node* createTree(int a[] , int cur , int n){
    if(cur >= n || a[cur] == -1)
      return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = a[cur];
    node->right = createTree(a , cur*2+2 , n);
    node->left = createTree(a , cur*2+1 , n);
    return node;
}
int max(int  a , int b){
    return a>b?a:b;
}
int height(Node* root, int* ans)
    {
        if(!root) return 0;
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        *ans = max(*ans, 1 + left + right);
        return 1 + max(left, right);  
    }
    int diameterOfBinaryTree(Node* root) {
        int ans = 0;
        if(!root) return 0;
        height(root, ans);
        return ans - 1;
    }
int main(){
    int n;
    scanf("%d" , &n);
    int a[n];
    for(int i=0;i<n;i++)
      scanf("%d" , &a[i]);
    Node* root = createTree(a ,0 ,  n);
    diameter(root);
    printf("%d" , answer);
    return 0;   
}