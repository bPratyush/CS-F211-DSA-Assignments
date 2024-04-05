#include <stdio.h>
#include <gmp.h>

int main(void) {
    mpz_t N, M, pass, temp;
    mpz_inits(N, M, pass, temp, NULL);
    gmp_scanf("%Zd", N);
    gmp_scanf("%Zd", M);
    mpz_gcdext(temp, pass, NULL, N, M);
    mpz_mod(pass, pass, M);
    if (mpz_sgn(pass) == -1) {
        mpz_add(pass, pass, M);
    }
    gmp_printf("%Zd",pass);
    mpz_clears(N, M, pass, temp);
    return 0;
}
