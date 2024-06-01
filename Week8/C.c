#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1000000
#define MOD 1000000007

typedef struct stack{
    int top;
    int arr[MAX_SIZE];
} stack;

bool empty(stack* s){
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
    if(empty(s)) return -1;
    else {
        s->top--;
        return s->arr[s->top+1];
    }
}

int peek(stack* s){
    return s->arr[s->top];
}

long long calculate(int n, int a[n]) {
    int left[n], right[n];
    stack s;
    s.top = -1;
    //Nearest smallest element to the left
    for(int i = 0; i < n; i++) {
        while(!empty(&s) && a[peek(&s)] >= a[i]) pop(&s);
        left[i] = empty(&s) ? -1 : peek(&s);
        push(&s, i);
    }
    s.top = -1;
    //Nearest smallest element to the right
    for(int i = n - 1; i >= 0; i--) {
        while(!empty(&s) && a[peek(&s)] >= a[i]) pop(&s);
        right[i] = empty(&s) ? n : peek(&s);
        push(&s, i);
    }
    //Sum based on elements in a, left and right
    //The product (i - left[i]) * (right[i] - i) gives the total number of contiguous subarrays in which a[i] is the minimum.
    //Multiplying the product by a[i] gives the total contribution of a[i] to the sum of minimum elements of all subarrays
    long long sum = 0;
    for(int i = 0; i < n; i++) sum = (sum + (long long)a[i] * (i - left[i]) * (right[i] - i)) % MOD;
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    long long sum = calculate(n, a);
    printf("%lld\n", sum);
}