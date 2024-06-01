#include <stdio.h>

int adjmat[100][100]={0};

void addedge(int u,int v){
    adjmat[u][v]=1;
    adjmat[v][u]=1;
}

void dfs(int n, int u, int visited[]) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adjmat[u][v] && !visited[v]) { 
            visited[v]=1;
            dfs(n, v, visited);
        }
    }
}

int numConnectedComponents(int n) {
    int visited[100] = {0}; 
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i]=1; 
            dfs(n, i, visited); 
            count++;
        }
    }
    return count;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    initgraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u-1, v-1);
    }
    printf("%d", numConnectedComponents(n));
}