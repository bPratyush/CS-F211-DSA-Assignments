#include <stdio.h>
// 0/1 Knapsack : Bottom Up DP - Memoization
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxRating(int n, int k, int ratings[], int times[]) {
    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
        if (i == 0 || j == 0) dp[i][j] = 0;
        else if (times[i - 1] <= j) dp[i][j] = max(ratings[i - 1] + dp[i - 1][j - times[i - 1]],dp[i-1][j]);
        else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][k];
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
