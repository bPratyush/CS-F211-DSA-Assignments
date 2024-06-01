#include <stdio.h>
#define ll long long
#define MOD 1000000007
//Binary Exponentiation = a^b
ll binexp(ll a, ll b) {
    ll result = 1;
    while (b) {
        if (b&1) result = (result * 1LL * a) % MOD;
        a = (a * 1LL* a) % MOD;
        b>>=1;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    ll a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    ll product = 1;
    for (int i = 0; i < n; i++) product = (product * binexp(a[i], b[i])) % MOD;
    printf("%lld\n", product);
}
