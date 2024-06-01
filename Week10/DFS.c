#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];

void dfs(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, start;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    scanf("%d", &start);
    dfs(start, n);
}
