#include <stdio.h>
#include <gmp.h>

int main(void) {
    mpz_t a;
    mpz_init(a);
    gmp_scanf("%Zd", a);
    unsigned long long int cnt = mpz_popcount(a); 
    gmp_printf("%llu\n", cnt);
    mpz_clear(a);  
    return 0;
}
