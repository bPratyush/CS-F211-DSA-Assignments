#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxRating(int n, int k, int ratings[], int times[]) {
    if (n == 0 || k == 0) return 0;
    if(times[n-1]<=k) return max(ratings[n-1] + maxRating(n-1, k - times[n-1], ratings, times), maxRating(n-1, k, ratings, times));
    else return maxRating(n-1, k, ratings, times);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ratings[n];
    int times[n];
    for (int i = 0; i < n; i++) scanf("%d", &ratings[i]);
    for (int i = 0; i < n; i++) scanf("%d", &times[i]);
    int result = maxRating(n, k, ratings, times);
    printf("%d", result);
}