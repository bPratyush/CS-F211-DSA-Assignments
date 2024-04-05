#include <stdio.h>

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void reverseVowels(char* s) {
    char* start = s;
    char* end = s;
    while (*end) end++;
    while (start < end) {
        while (!isVowel(*start) && start < end) start++;
        while (!isVowel(*end) && start < end) end--;
        if (start < end) {
            char temp = *start;
            *start++ = *end; 
            *end-- = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1]; 
    scanf(" %[^\n]", s);
    reverseVowels(s);
    printf("%s\n", s);
    return 0;
}
