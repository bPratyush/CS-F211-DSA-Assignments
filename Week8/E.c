#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000001

typedef struct stack{
    int top;
    char* arr;
} stack;

bool stackempty(stack* s){
    return (s->top == -1);
}

void push(stack* s, int x){
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

int peek(stack*s){
    return s->arr[s->top];
}

char* subtract(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;
    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    int carry = 0;
    for (int i = len1 - 1, j = len2 - 1, k = len - 1; k >= 0; i--, j--, k--) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        }
        else carry = 0;
        result[k] = diff + '0';
    }
    return result;
}

char* removeKdigits(char* num, int k) {
    stack s;
    s.top = -1;
    s.arr = malloc((strlen(num) + 1) * sizeof(char));
    for(int i = 0; i < strlen(num); i++){
        while(!stackempty(&s) && num[i] < peek(&s) && k) { 
            pop(&s); 
            k--; 
        }
        if(!stackempty(&s) || num[i] != '0') push(&s, num[i]);
    }
    while(k-- && stackempty(&s)) pop(&s); 
    if(stackempty(&s)) return "0";
    else {
        s.arr[s.top+1] = '\0';
        char* result = strdup(s.arr);
        return result;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *s = malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    char* new_price = removeKdigits(s, k);
    char* profit = subtract(s, new_price);
    printf("%s\n", profit);
}