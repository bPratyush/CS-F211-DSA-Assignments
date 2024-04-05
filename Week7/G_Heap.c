#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void minheapify(int diff[], int pos[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if(l < n && (diff[l] < diff[smallest] || (diff[l] == diff[smallest] && pos[l] < pos[smallest]))) smallest = l;
    if(r < n && (diff[r] < diff[smallest] || (diff[r] == diff[smallest] && pos[r] < pos[smallest]))) smallest = r;
    if(smallest != i){
        swap(&diff[i], &diff[smallest]);
        swap(&pos[i], &pos[smallest]);
        minheapify(diff, pos, n, smallest);
    }
}

void buildMinHeap(int diff[], int pos[], int n){
    for(int i = n/2 - 1; i >= 0; i--) minheapify(diff, pos, n, i);
}

int extractMin(int diff[], int pos[], int* n) {
    if (*n <= 0) return -1;
    int minPos = pos[0];
    diff[0] = diff[*n - 1];
    pos[0] = pos[*n - 1];
    (*n)--;
    minheapify(diff, pos, *n, 0);
    return minPos;
}

int main(void){
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int diff[n], pos[n];
    for(int i = 0; i < n; i++) scanf("%d", &pos[i]);
    for(int i = 0; i < n; i++) diff[i] = abs(x - pos[i]);
    buildMinHeap(diff, pos, n);
    for(int i = 0; i < k; i++) printf("%d ", extractMin(diff, pos, &n));
}