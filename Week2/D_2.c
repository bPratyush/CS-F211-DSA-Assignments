#include<stdio.h>
#define PRE 6

double sq_root(int n,int precision){
	int l=0,r=n;
	double ans=-1;

	if(n==1) return 1;

	while(l<=r){
		int mid=l+(r-l)/2;
		if(mid*mid==n){
			ans=mid;
			break;
		}
		else if(mid*mid<n) l=mid+1;
		else r=mid-1;
	}

	double inc=0.1;
	for(int i=0;i<precision;i++){
		while(ans*ans<n) ans+=inc;
		ans-=inc;
		inc/=10;
	}
	return ans;
}

int main(){
	int n; scanf("%d",&n);
	double ans=sq_root(n,PRE);
	printf("%lf\n",ans);
}