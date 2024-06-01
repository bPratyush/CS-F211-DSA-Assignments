#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int adjmat[MAX_NODES][MAX_NODES]={0};
int max_length = 0;

void dfs(int u, int parent, int length) {
    if (length > max_length) max_length = length;
    for (int v = 0; v < MAX_NODES; ++v) {
        if (adjmat[u][v] && v != parent) {
            dfs(v, u, length + 1);
        }
    }
}

void addedge(int u,int v){
    adjmat[u][v] = 1;
    adjmat[v][u] = 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u,v);
    }
    for (int i = 0; i < MAX_NODES; ++i) dfs(i, -1, 0);
    printf("%d\n", max_length);
}

