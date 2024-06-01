#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, W;
    scanf("%d %d", &n, &W);

    int weight[n], value[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    // Initialize DP table
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or weight limit is 0
            } else if (weight[i - 1] <= w) {
                // Consider including or excluding the current item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            } else {
                // Current item's weight exceeds the current weight limit
                dp[i][w] = dp[i - 1][w]; // Exclude the current item
            }
        }
    }

    printf("%d\n", dp[n][W]);

    return 0;
}
