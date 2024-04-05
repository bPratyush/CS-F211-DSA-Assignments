#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct deque {
    int tail;
    int head;
    int arr[MAX_SIZE];
} deque;

void enqueue_back(deque* q, int x) {
    q->arr[q->tail] = x; 
    if(q->tail == MAX_SIZE - 1) q->tail = 0;
    else q->tail++;
}

int dequeue_front(deque* q) {
    int x = q->arr[q->head];
    if(q->head == MAX_SIZE - 1) q->head = 0;
    else q->head++;
    return x;
}

void enqueue_front(deque* q, int x) {
    if(q->head == 0) q->head = MAX_SIZE - 1;
    else q->head--;
    q->arr[q->head] = x;
}

int dequeue_back(deque* q) {
    if(q->tail == 0) q->tail = MAX_SIZE - 1;
    else q->tail--;
    return q->arr[q->tail];
}