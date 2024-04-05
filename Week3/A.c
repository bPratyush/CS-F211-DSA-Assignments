#include <stdio.h>

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int isPal(char* s, int l, int r){
    while(l<r){
        if(s[l]!=s[r])
        return 0;
        l++;
        r--;
    }
    return 1;
}

int LPS(char *s, int n){
    int maxlen=1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isPal(s,i,j)){
                int len=j-i+1;
                maxlen=max(len,maxlen);
            }
        }
    }
    return maxlen;
}

int main(){
    int n;
    scanf("%d", &n);
    char str[n+1];
    scanf("%s", str);
    int length = LPS(str, n);
    printf("%d\n", length);
    return 0;
}
