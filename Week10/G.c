#include <stdio.h>
#include <limits.h>
#define MAXN 100

int adjmat[MAXN][MAXN] = {0};
int dist[MAXN];
int visited[MAXN] = {0};

void addedge(int u, int v, int w) {
    //Multiple edges addition
    if (adjmat[u][v] == 0 || w < adjmat[u][v]) {
        adjmat[u][v] = w;
        adjmat[v][u] = w; // Assuming undirected graph
    }
}

void dijkstra(int n) {
    // Initialize dist[] to infinity except the source
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[0] = 0; // Distance from source to source is 0
    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum distance
        int min_dist = INT_MAX;
        int min_index;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                min_index = i;
            }
        }
        // Mark the selected vertex as visited
        visited[min_index] = 1;
        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adjmat[min_index][v] && dist[min_index] != INT_MAX &&
                    dist[min_index] + adjmat[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + adjmat[min_index][v];
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addedge(a - 1, b - 1, c);
    }
    dijkstra(n);
}
