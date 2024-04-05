#include <stdio.h>

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

void reverseWords(char *str, int strLen) {
    Stack s;
    s.top = -1;

    for (int i = 0; i <= strLen; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            while (s.top != -1) {
                printf("%c", pop(&s));
            }
            printf("%c", str[i]); //To preserve the spaces
        } 
        else {
            push(&s, str[i]);
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
    reverseWords(str, strLen);
    return 0;
}