#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Adjacency Matrix
int adj_matrix[MAX_NODES][MAX_NODES];

// Adjacency List Node
typedef struct ListNode {
    int vertex;
    struct ListNode* next;
} ListNode;

// Adjacency List
ListNode* adj_list[MAX_NODES];

// Function to initialize adjacency matrix and adjacency list
void initializeGraph(int n) {
    // Initialize adjacency matrix with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Initialize adjacency list as NULL
    for (int i = 0; i < n; i++) {
        adj_list[i] = NULL;
    }
}

// Function to add an edge to the graph (both matrix and list)
void addEdge(int u, int v) {
    // Add edge to adjacency matrix
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // Assuming undirected graph

    // Add edge to adjacency list
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->vertex = v;
    newNode->next = adj_list[u];
    adj_list[u] = newNode;

    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->vertex = u;
    newNode->next = adj_list[v];
    adj_list[v] = newNode;
}

// Function to print adjacency matrix
void printAdjMatrix(int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print adjacency list
void printAdjList(int n) {
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        ListNode* temp = adj_list[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m; // Number of nodes and edges
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    initializeGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printAdjMatrix(n);
    printAdjList(n);

    return 0;
}
