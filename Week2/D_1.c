#include <stdio.h>
//Babylonian Method
int main(void){
   float n,guess=1;
   scanf("%f",&n);
   for(int i=0;i<32;i++) guess=(guess+n/guess)/2;
   printf("%.6f\n",guess);
}