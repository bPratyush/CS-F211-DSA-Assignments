#include <stdio.h>

const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

void printNumber(long long n) {
    if (n >= 1000000000000) {
        printNumber(n / 1000000000000);
        printf(" trillion ");
        n %= 1000000000000;
        if (n == 0) return;
    }
    if (n >= 1000000000) {
        printNumber(n / 1000000000);
        printf(" billion ");
        n %= 1000000000;
        if (n == 0) return;
    }
    if (n >= 1000000) {
        printNumber(n / 1000000);
        printf(" million ");
        n %= 1000000;
        if (n == 0) return;
    }
    if (n >= 1000) {
        printNumber(n / 1000);
        printf(" thousand ");
        n %= 1000;
        if (n == 0) return;
    }
    if (n >= 100) {
        printNumber(n / 100);
        printf(" hundred ");
        n %= 100;
        if (n == 0) return;
    }
    if (n >= 20) {
        printf("%s", tens[n / 10]);
        if (n % 10) printf(" ");
        n %= 10;
    }
    if (n >= 10) printf("%s", teens[n - 10]);
    else if (n > 0) printf("%s", ones[n]);
    else printf("zero");
}

int main() {
    long long n;
    scanf("%lld", &n);
    printNumber(n);
    printf("\n");
    return 0;
}