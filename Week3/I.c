#include <stdio.h>
#include <stdbool.h>
#define MOD 1000000007
//Sieve of Erasthonesus
bool sieve(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(void){
    int n;
    scanf("%d",&n);
    long long prod=1;
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<n;i++) if(!sieve(a[i])) prod=(prod*a[i])%MOD;
    if(prod==1) printf("-1");
    else printf("%lld",prod);
}
