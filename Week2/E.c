#include <stdio.h>

int main(void){
    int n;
    int t;
    scanf("%d",&n);
    scanf("%d",&t);
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int row = 0;
    int col = n - 1;
    int flag= 0;  
    while(row < n && col >= 0){
        if(a[row][col] == t) {
            flag=1;  
            break;
        }
        if(t > a[row][col]) row++;
        else col--;
    }
    if(flag) printf("YES\n");
    if(!flag) printf("NO\n");
    return 0;
}
