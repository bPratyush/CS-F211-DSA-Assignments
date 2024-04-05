#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (wt[i - 1] <= j) dp[i][j] = max(wt[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int weights[n];
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    int totalWeight = 0;
    for (int i = 0; i < n; i++) totalWeight += weights[i];
    int targetWeight = totalWeight / k;
    int result = knapsack(targetWeight, weights, n);
    printf("%d", result+1);
}
