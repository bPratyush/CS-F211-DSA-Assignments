#include <stdio.h>
#include <stdlib.h>

#define MAX 2003
#define INF 9999999

struct Edge {
    int u, v, weight;
};

int parent[MAX];

int find_set(int i) {
    if (i == parent[i]) return i;
    else return find_set(parent[i]);
}

void union_set(int u, int v) {
    parent[find_set(u)] = find_set(v);
}

void bubble_sort(struct Edge edges[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Edge edges[n];
    for (int i = 0; i < n; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    bubble_sort(edges, n);
    for (int i = 0; i < MAX; i++) parent[i] = i;
    int cost = 0;
    for (int i = 0; i < n; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find_set(u) != find_set(v)) {
            cost += edges[i].weight;
            union_set(u, v);
        }
    }
    printf("%d ", cost);
}