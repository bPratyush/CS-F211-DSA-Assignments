#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000
//Stack Approach
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char item) {
    if (s->top == MAX_SIZE - 1) return;
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->items[(s->top)--];
}

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void reverseVowels(char *str, int strLen) {
    Stack s;
    s.top = -1;

    for (int i = 0; i <= strLen; i++) {
        if (isVowel(str[i])) {
            push(&s, str[i]);
        }
    }

    for (int i = 0; i <= strLen; i++) {
        if (isVowel(str[i])) {
            str[i] = pop(&s);
        }
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    char str[n + 1];
    scanf("%[^\n]", str);
    int strLen = 0;
    while (str[strLen] != '\n' && str[strLen] != '\0') {
        strLen++;
    }
    str[strLen] = '\0';
    reverseVowels(str, strLen);
    printf("%s\n", str);
    return 0;
}