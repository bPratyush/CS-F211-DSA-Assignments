#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

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

int dequeue_back(deque* q) {
    if(q->tail == 0) q->tail = MAX_SIZE - 1;
    else q->tail--;
    return q->arr[q->tail];
}

int front(deque* q) {
    return q->arr[q->head];
}

int back(deque* q) {
    return q->arr[q->tail == 0 ? MAX_SIZE - 1 : q->tail - 1];
}

long long count_valid_subarrays(int arr[], int n, int k) {
    deque minDeque, maxDeque;
    minDeque.head = minDeque.tail = maxDeque.head = maxDeque.tail = 0;
    long long count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (minDeque.tail != minDeque.head && arr[back(&minDeque)] >= arr[i]) dequeue_back(&minDeque); //Indices in Increasing Order
        while (maxDeque.tail != maxDeque.head && arr[back(&maxDeque)] <= arr[i]) dequeue_back(&maxDeque); //Indices in Decreasing Order
        enqueue_back(&minDeque, i); //Adding index i to both deques
        enqueue_back(&maxDeque, i);
        while (arr[front(&maxDeque)] - arr[front(&minDeque)] > k) {
            if (front(&minDeque) == j) dequeue_front(&minDeque); //checks if minimum element of the current subarray is at the start of the subarray
            if (front(&maxDeque) == j) dequeue_front(&maxDeque); //checks if maximum element of the current subarray is at the start of the subarray
            j++;
        }
        count += i - j + 1;
    }
    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    long long count = count_valid_subarrays(arr, n, k);
    printf("%lld", count);
}