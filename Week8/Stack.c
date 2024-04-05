#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack{
    int top;
    int arr[MAX_SIZE];
} stack;

bool stackempty(stack* s){
    if(s->top == -1) return true;
    return false;
}

void push(stack* s, int x){
    if(s->top == MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}

int pop(stack* s){
    if(stackempty(s)) {
        printf("Underflow\n");
        return -1;
    } else {
        s->top--;
        return s->arr[s->top+1];
    }
}

int peek(stack* s){
    return s->arr[s->top];
}