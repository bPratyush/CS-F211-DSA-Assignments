#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct stack{
    int top;
    int arr[MAX_SIZE];
} stack;

bool stackempty(stack* s){
    return (s->top == -1);
}

void push(stack* s, int x){
    if(s->top == MAX_SIZE - 1) return;
    s->top++;
    s->arr[s->top] = x;
}

int pop(stack* s){
    if(stackempty(s)) return -1;
        else {
        s->top--;
        return s->arr[s->top+1];
    }
}

int peek(stack* s){
    return s->arr[s->top];
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int max_histogram_area(int heights[], int n) {
    stack s;
    s.top = -1;
    int max_area = 0;
    int area_with_top;
    int i = 0;
    while (i < n) {
        if (stackempty(&s) || heights[peek(&s)] <= heights[i]) push(&s, i++);
        else {
            area_with_top = heights[pop(&s)] * (stackempty(&s) ? i : i - peek(&s) - 1);
            max_area = max(max_area, area_with_top);
        }
    }
    while (!stackempty(&s)) {
        area_with_top = heights[pop(&s)] * (stackempty(&s) ? i : i - peek(&s) - 1);
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) scanf("%d", &heights[i]);
    int max_area = max_histogram_area(heights, n);
    printf("%d", max_area);
}