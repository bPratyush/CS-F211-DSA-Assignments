#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findPair(int arr[], int n, int k) {
    int freq[n+1];
    for(int i=0;i<=n;i++) freq[i]=0;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            int j = k - i;
            if (j > 0 && j <= n && freq[j] == 0) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if (findPair(arr, n, k)) printf("yes");
    else printf("no");
}