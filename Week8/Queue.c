#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct queue{
    int tail;
    int head;
    int arr[MAX_SIZE];
}queue;

void enqueue(queue* q,int x){
    q->arr[q->tail] = x; 
    if(q->tail == MAX_SIZE - 1) q->tail = 0;
    else q->tail++;
}

int dequeue(queue* q){
    int x = q->arr[q->head];
    if(q->head == MAX_SIZE - 1) q->head = 0;
    else q->head++;
    return x;
}