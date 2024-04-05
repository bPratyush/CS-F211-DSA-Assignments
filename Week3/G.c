#include <stdio.h>

int maxPeanutButter(int n, int a[]) {
    int left = 0, right = n - 1;
    int maxWeight = 0, nomWeight = 0, psyWeight = 0;
    while (left <= right) {
        if (nomWeight <= psyWeight) nomWeight += a[left++];
        else psyWeight += a[right--];
        if (nomWeight == psyWeight) maxWeight = nomWeight;
    }
    return maxWeight;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int maxWeight = maxPeanutButter(n, a);
    printf("%d\n", maxWeight);
}
