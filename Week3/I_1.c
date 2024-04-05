#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000009

int maxfinder(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
        {scanf("%d", &a[i]);
          a[i] = a[i]%MOD;
        }
    int max = maxfinder(a, n);
    int pro = 1;

    // Sieve of Eratosthenes to mark primes up to sqrt(max)
   long long int isPrime[max + 1];
    for (int i = 2; i <= max; i++)
        isPrime[i] = 1;

    for (int p = 2; p * p <= max; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= max; i += p)
                isPrime[i] = 0;
        }
    }

    // Multiply non-prime elements
    for (int i = 0; i < n; i++) {
        bool prime = 1;
        for (int p = 2; p * p <= a[i]; p++) {
            if (isPrime[p] && a[i] % p == 0) {
                prime = 0;
                break;
            }
        }
        if (!prime) {
            pro = (pro * (a[i] % MOD)) % MOD;
        }
    }

    if (pro == 1)
        printf("-1");
    else
        printf("%d", pro);

    return 0;
}