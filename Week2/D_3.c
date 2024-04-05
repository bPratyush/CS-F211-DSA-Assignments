#include<stdio.h>
double absolute(double p){
  if(p>0)
  return p;
  else
  return (-1)*p; 

}
double solution(int x){
if(x<2)
  return x;

double y = x;
double z = (y+(x/y))/2;

while(absolute(y - z) >= 0.000001){
    y = z;
    z = (y + (x/y))/2;
}  
 
  if((int)z*(int)z != x)  // adjusting the round off after the code
  return z-0.000001;
  else
  return z;
}
int main(){
int N;
scanf("%d" , &N);

printf("%lf" , solution(N));
}