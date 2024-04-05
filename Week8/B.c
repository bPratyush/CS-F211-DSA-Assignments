#include <stdio.h>
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

int front(deque* dq) {
    return dq->arr[dq->head];
}

int back(deque* dq) {
    return dq->arr[dq->tail - 1];
}

int empty(deque* dq) {
    return dq->head == dq->tail;
}

void printKMax(int arr[], int N, int K) {
    deque Qi;
    Qi.head = 0;
    Qi.tail = 0;

    int i;
    for (i = 0; i < K; ++i) {
        while (!empty(&Qi) && arr[i] >= arr[back(&Qi)]) dequeue_back(&Qi);
        enqueue_back(&Qi, i);
    }
    for (; i < N; ++i) {
        printf("%d ", arr[front(&Qi)]);
        while (!empty(&Qi) && front(&Qi) <= i - K) dequeue_front(&Qi);
        while (!empty(&Qi) && arr[i] >= arr[back(&Qi)]) dequeue_back(&Qi);
        enqueue_back(&Qi, i);
    }
    printf("%d ", arr[front(&Qi)]);
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printKMax(a, n, k);
}