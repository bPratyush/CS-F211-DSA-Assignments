#include <stdio.h>

#define MAXN 100005

int parent[MAXN];
int rank[MAXN];

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b]) parent[a] = b;
        else {
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) make_set(i);
    int components = n;
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
            components--;
        }
        printf("%d ", components);
    }
}