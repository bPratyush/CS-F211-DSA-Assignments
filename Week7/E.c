#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

Pair* sort_pairs(Pair* pairs, int n) {
    //Bucket Initialisation
    Pair** buckets = malloc((n+1) * sizeof(Pair*));
    int bucket_sizes[n+1];
    for (int i = 0; i <= n; ++i) {
        buckets[i] = malloc(n * sizeof(Pair));
        bucket_sizes[i] = 0;
    }
    //Distributing Pairs into Buckets
    for (int i = 0; i < n; ++i) buckets[pairs[i].first][bucket_sizes[pairs[i].first]++] = pairs[i];
    //Collecting Pairs from Buckets
    int index = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            pairs[index++] = buckets[i][j];
        }
    }
    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);
    Pair* pairs = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; ++i) scanf("%d", &(pairs[i].first));
    for (int i = 0; i < n; ++i) scanf("%d", &(pairs[i].second));
    pairs = sort_pairs(pairs, n);
    for (int i = 0; i < n; ++i) printf("%d ", pairs[i].first);
    printf("\n");
    for (int i = 0; i < n; ++i) printf("%d ", pairs[i].second);
    printf("\n");
}