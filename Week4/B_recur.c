#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int n) {
    if (n == 0 || W == 0) return 0;
    if(wt[n-1]<=W) return max(wt[n-1] + knapsack(W - wt[n-1], wt, n-1), knapsack(W, wt, n-1));
    else return knapsack(W, wt, n-1);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int weights[n];
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    int totalWeight = 0;
    for (int i = 0; i < n; i++) totalWeight += weights[i];
    int av = ((totalWeight%k)==0)?(totalWeight/k):((int)(totalWeight/k) + 1);
    int result = knapsack(av, weights, n);
    printf("%d", result);
} 