#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    // Initialize prefix sum array
    long long prefixSum[n+1][n+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            prefixSum[i][j] = 0;
        }
    }
    
    // Read matrix values and calculate prefix sum
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int value;
            scanf("%d", &value);
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + value;
        }
    }
    
    // Process queries
    for (int i = 0; i < q; ++i) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        long long sum = prefixSum[y2][x2] - prefixSum[y1-1][x2] - prefixSum[y2][x1-1] + prefixSum[y1-1][x1-1];
        printf("%lld\n", sum);
    }
    
    return 0;
}
