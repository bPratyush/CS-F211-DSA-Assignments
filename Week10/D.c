#include <stdio.h>
#include <limits.h>
#define N_MAX 100

int adjmat[N_MAX][N_MAX]={0};

void addedge(int u, int v, int w){
    adjmat[u][v] = w;
    adjmat[v][u] = w;
}

int minDistance(int dist[], int mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int V, int src, int dest) {
    int dist[V];
    int mstSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        mstSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, mstSet, V);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && adjmat[u][v] && dist[u] != INT_MAX && dist[u] + adjmat[u][v] < dist[v]) {
                dist[v] = dist[u] + adjmat[u][v];
            }
        }
    }
    printf("%d ", dist[dest]);
}

int main(void){
    int V, E, S, D;
    scanf("%d %d %d %d", &V, &E, &S, &D);
    for(int i = 0; i < E; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addedge(u, v, w); 
    }
    dijkstra(V, S, D);
}
