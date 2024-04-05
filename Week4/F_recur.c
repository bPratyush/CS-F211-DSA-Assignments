#include <stdio.h>

int F(int a[],int n,int k){
    if(k==0) return 1;
    if(n==0) return 0;
    if(a[n-1]<=k) return F(a,n-1,k)+F(a,n,k-a[n-1]);
    else return F(a,n-1,k);
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int result = maxRating(n, k, a);
    printf("%d", result);
}