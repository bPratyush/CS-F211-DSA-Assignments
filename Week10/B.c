#include <stdio.h>
#include <limits.h>
#define N_MAX 100

int adjmat[N_MAX][N_MAX]={0};

void addedge(int u, int v, int w){
    adjmat[u][v] = w;
    adjmat[v][u] = w;
}

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int prim(int N) {
    int parent[N_MAX];
    int key[N_MAX];
    int mstSet[N_MAX];
    // Initialize all keys as INFINITE
    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX, mstSet[i] = 0;
    }
    // Always include first 0th vertex in MST.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
    // The MST will have N vertices
    for (int count = 0; count < N - 1; count++) {
        int u = minKey(key, mstSet, N);
        mstSet[u] = 1;
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < N; v++) {
            if (adjmat[u][v] && mstSet[v] == 0 && adjmat[u][v] < key[v]) {
                parent[v] = u, key[v] = adjmat[u][v];
            }
        }
    }
    // Calculate the total cost of MST
    int mstCost = 0;
    for (int i = 1; i < N; i++) mstCost += adjmat[i][parent[i]];
    return mstCost;
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addedge(u - 1, v - 1, w);
    }
    printf("%d", prim(n));
}

