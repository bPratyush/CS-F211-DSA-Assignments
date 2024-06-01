#include <stdio.h>
int adjmat[100][100]={{0}};

void dfs(int n, int m, int u, int v) {
    if(u < 0 || u >= n || v < 0 || v >= m || adjmat[u][v] == 0) return;
    adjmat[u][v] = 0;
    dfs(n, m, u + 1, v);
    dfs(n, m, u - 1, v);
    dfs(n, m, u, v + 1);
    dfs(n, m, u, v - 1);
}

int numislands(int n, int m) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(adjmat[i][j] == 1) {
                cnt++;
                dfs(n, m, i, j);
            }
        }
    }
    return cnt;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    initgraph(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &adjmat[i][j]);
        }
    }
    printf("%d", numislands(n, m));
}


