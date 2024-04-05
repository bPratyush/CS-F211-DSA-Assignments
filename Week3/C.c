#include <stdio.h>

void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseEachWord(char* s) {
    char* word_begin = s;
    char* temp = s;
    while (*temp) {
        temp++;
        if (*temp == ' ' || *temp == '\0') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1]; 
    scanf(" %[^\n]", s);
    reverseEachWord(s);
    printf("%s\n", s);
    return 0;
}