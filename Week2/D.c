#include <stdio.h>
//PRECISION ISSUE
float squareRoot(int number)
{
    float start = 0, end = number;
    float mid;
    float ans;  
    while (end-start>0.000001) {
        mid = start + (end-start) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
        if (mid * mid < number) {
            start = mid;
            ans = mid;
        }
        else {
            end = mid;
        }
    }
    return ans;  
}

int main()
{
   int n;
   scanf("%d",&n);
   float res=squareRoot(n);
   printf("%.6f\n",res);
    return 0;
}

