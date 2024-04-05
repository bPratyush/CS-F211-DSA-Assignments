#include <stdio.h>

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int lengthOfLongestSubstring(char* s, int n) {
    int mpp[256];
    for (int i = 0; i < 256; i++) mpp[i] = -1;
    
    int l = 0;
    int r = 0;
    int len = 0;
    
    while (r < n) {
        if (mpp[s[r]] != -1) 
        l = max(mpp[s[r]] + 1, l);
        mpp[s[r]] = r;
        len = max(r - l + 1, len);
        r++;
    }
    
    return len;
}


int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];  
    scanf("%s", s);
    int result = lengthOfLongestSubstring(s, n);
    printf("%d\n", result);
}
