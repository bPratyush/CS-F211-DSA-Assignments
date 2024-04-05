#include <stdio.h>

int maxRating(int n, int k, int a[]) {
    int dp[k + 1];
    for(int i=0;i<=k;i++) dp[i]=0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            dp[j] += dp[j - a[i]];
        }
    }
    return dp[k];
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int result = maxRating(n, k, a);
    printf("%d", result);
    return 0;
}
