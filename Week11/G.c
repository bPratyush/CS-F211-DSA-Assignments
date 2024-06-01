#include <stdio.h>

double A, B, C, D;

double f(double x) {
    return A*x*x*x + B*x*x + C*x + D;
}

double ternary_search(double l, double r) {
    for(int i=0; i<200; i++) {
        double l_third = l + (r - l) / 3;
        double r_third = r - (r - l) / 3;
        if(f(l_third) < f(r_third))
            l = l_third;
        else
            r = r_third;
    }
    return (l + r) / 2;
}

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
    printf("%.6lf\n", ternary_search(a, b));
    return 0;
}