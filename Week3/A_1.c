#include <stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int LPS(char s[], int n) {
    int dp[n + 1][n + 1];
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <=n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=n; j++) {
            if (s[i - 1] == s[n - j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main(void) {
    int n;
    scanf("%d", &n); 
    char s[n+1];
    scanf("%s", s);
    int res = LPS(s, n);
    printf("%d\n", res);
    return 0;
}
