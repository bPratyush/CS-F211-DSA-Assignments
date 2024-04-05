#include <stdio.h>

int sum(int b[], int l, int r){
    int sum = 0;
    for(int i = l; i <= r; i++) sum += b[i];
    return sum;
}

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n + 1]; // Increase array size to accommodate 1-based indexing
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int rev[q][2];
    for(int i = 0; i < q; i++) scanf("%d %d", &rev[i][0], &rev[i][1]);
    for(int i = 0; i < q; i++) printf("%d\n",sum(a, rev[i][0], rev[i][1])); 
    return 0;
}
