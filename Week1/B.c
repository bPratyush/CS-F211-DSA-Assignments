#include <stdio.h>

#define ll unsigned long long int

ll getsize(ll x) {
    ll n = 0;
    while (x) {
        n++;
        x /= 10;
    }
    return n;
}

ll pwr(ll x, ll n) {
    if (n == 0) return 1;
    ll result = 1;
    while (n--) {
        result *= x;
    }
    return result;
}

ll multkar(ll x, ll y, ll n) {
    if (n == 1) return x * y;
    else {
        ll m = n / 2;
        ll a = x / pwr(10, m);
        ll b = x % pwr(10, m);
        ll c = y / pwr(10, m);
        ll d = y % pwr(10, m);
        ll p = a + b;
        ll q = c + d;
        ll ac = multkar(a, c, m);
        ll bd = multkar(b, d, m);
        ll pq = multkar(p, q, m);
        ll adbc = pq - ac - bd;
        return (pwr(10, n) * ac + pwr(10, n / 2) * adbc + bd);
    }
}

int main(void) {
    ll x, y;
    scanf("%llu %llu", &x, &y);
    ll n = getsize(x);
    ll m = getsize(y);
    if (n != m) printf("-1\n");
    else {
        ll res = multkar(x, y, n);
        printf("%llu\n", res);
    }
    return 0;
}