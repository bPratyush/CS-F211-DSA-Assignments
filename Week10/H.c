#include <stdio.h>
#include <limits.h>
int adjmat[100][100]={0};

void addedge(int u,int v,int w){
    adjmat[u][v]=w;
}

int bellmanford(int V, int E, int source) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[source] = 0;
    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (adjmat[u][v]) { // If there is an edge from u to v
                    if (dist[u] != INT_MAX && dist[u] + adjmat[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjmat[u][v];
                    }
                }
            }
        }
    }
    // Check for negative cycles
    //Relax all the edges one more time i.e. the Nth time
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adjmat[u][v]) { // If there is an edge from u to v
                if (dist[u] != INT_MAX && dist[u] + adjmat[u][v] < dist[v]) {
                    // Negative cycle found
                    return 1;
                }
            }
        }
    }
}

int main() {
    int V,E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addedge(a-1,b-1,c);
    }
    int negative_cycle_exists = 0;
    for (int i = 0; i < V; i++) {
        if (bellmanford(V,E,i)) {
            negative_cycle_exists = 1;
            printf("YES");
            break;
        }
    }
    if (!negative_cycle_exists) printf("NO\n");
}
