#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005

int adjmat[MAXN][MAXN] = {{0}};
int in_degree[MAXN] = {0};
int visited[MAXN] = {0};
int result[MAXN];
int idx = 0; 

void addedge(int a, int b) {
    adjmat[a][b] = 1;
    in_degree[b]++;
}

void topological_sort(int n) {
    int queue[MAXN];
    int front = 0, rear = -1;
    // Enqueue nodes with in-degree 0
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) queue[++rear] = i;
    }
    while (front <= rear) {
        int u = queue[front++]; // Dequeue vertex u
        result[idx++] = u; // Store the vertex in the result array
        // Visit all adjacent vertices of u
        for (int v = 1; v <= n; v++) {
            if (adjmat[u][v] == 1) {
                in_degree[v]--; // Decrement in-degree of adjacent vertex
                if (in_degree[v] == 0) queue[++rear] = v; // Enqueue vertex if its in-degree becomes 0
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addedge(a, b);
    }
    topological_sort(n);
    if (idx < n) printf("IMPOSSIBLE\n"); // Graph has a cycle, not possible to complete all courses
    else {
        for (int i = 0; i < n; i++) printf("%d ", result[i]);
    }
}

