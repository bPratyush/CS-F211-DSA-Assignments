#include <stdio.h>
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

int front(deque* dq) {
    return dq->arr[dq->head];
}

int back(deque* dq) {
    return dq->arr[dq->tail - 1];
}

int empty(deque* dq) {
    return dq->head == dq->tail;
}

int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
deque q;

void bfs(int start, int n) {
    enqueue_back(&q, start);
    visited[start] = 1;

    while (!empty(&q)) {
        int current = dequeue_front(&q);
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                enqueue_back(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    q.head = 0;
    q.tail = 0;
    printf("BFS Traversal: ");
    bfs(start, n);
}
