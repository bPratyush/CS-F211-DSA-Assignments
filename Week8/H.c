#include <stdio.h>
#define MAX_SIZE 1000000
//Without Heaps
int stack[MAX_SIZE], minStack[MAX_SIZE], queue[MAX_SIZE];
long long sumQueue = 0;
int top = -1, minTop = -1, front = 0, rear = -1, queueSize = 0;

void pushStack(int x) {
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop]) minStack[++minTop] = x;
}

void popStack() {
    if (stack[top] == minStack[minTop]) minTop--;
    top--;
}

int getMinStack() {
    return minStack[minTop];
}

void pushQueue(int x) {
    queue[++rear] = x;
    sumQueue += x;
    queueSize++;
}

void popQueue() {
    sumQueue -= queue[front++];
    queueSize--;
}

int getAvgQueue() {
    return sumQueue / queueSize;
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            pushStack(x);
            pushQueue(x);
        }
        else if (type == 2) {
            popStack();
            popQueue();
        }
        else printf("%d %d\n", getMinStack(), getAvgQueue());
    }
}