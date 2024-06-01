#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack{
    int top;
    char arr[MAX_SIZE];
} stack;

bool stackempty(stack* s){
    return (s->top == -1);
}

void push(stack* s, char x){
    s->top++;
    s->arr[s->top] = x;
}

char pop(stack* s){
    if(stackempty(s)) return -1;
    else {
        s->top--;
        return s->arr[s->top+1];
    }
}

bool isMatch(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool isValidParentheses(char* s) {
    stack st;
    st.top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') push(&st, s[i]);
        else {
            if (stackempty(&st) || !isMatch(pop(&st), s[i])) return false;
        }
    }
    return stackempty(&st);
}

int main() {
    char s[MAX_SIZE];
    scanf("%s", s);
    if (isValidParentheses(s)) printf("YES\n");
    else printf("NO\n");
}