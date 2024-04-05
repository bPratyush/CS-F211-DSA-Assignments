#include <stdio.h>
#include <gmp.h>

int main(void) {
    mpz_t num1, num2, res;
    mpz_inits(num1,num2,res);
    gmp_scanf("%Zd", num1);
    gmp_scanf("%Zd", num2);
    mpz_mul(res, num1, num2);
    gmp_printf("%Zd\n", res);
    mpz_clears(num1,num2,res)
    return 0;
}
