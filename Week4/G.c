#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int LCM(int a, int b) {
    return (a*b)/gcd(a,b);
}

void stringLCM(char *s, int n, char *result) {
    strcpy(result, s);
    for (int i = 1; i < n; i++) strcat(result, s);
}

int main() {
    char s1[10001];
    char s2[10001];
    char result[20002];  // Twice the maximum length of the input strings

    scanf("%s", s1);
    scanf("%s", s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int lcm = LCM(len1, len2);
    int flag = 0;

    stringLCM(s1, lcm / len1, result);
    strcpy(s1, result);
    stringLCM(s2, lcm / len2, result);
    strcpy(s2, result);

    if (!strcmp(s1, s2)) flag = 1;
    if (flag) printf("%s", s1);
    else printf("-1");
}