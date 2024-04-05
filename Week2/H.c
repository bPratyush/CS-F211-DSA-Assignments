#include <stdio.h>
#include <limits.h>

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int max(int a, int b){
    if(a<b) return b;
    else return a;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int buy = INT_MAX;
    int sell = INT_MIN;
    for (int i = 0; i < n; i++) {
        buy = min(buy,a[i]);
        sell = max(sell,a[i]-buy);
    }
    printf("%d\n", sell);
    return 0;
}