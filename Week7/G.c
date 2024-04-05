#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int dist;
} Target;

void swap(Target *a,Target *b){
    Target tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(Target arr[], int p, int r) {
    Target x = arr[r];
    int i = (p - 1);
    for (int j = p; j <= r - 1; j++) {
        if (arr[j].dist < x.dist || (arr[j].dist == x.dist && arr[j].pos < x.pos)) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i + 1);
}

void quickSort(Target arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    Target targets[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &targets[i].pos);
        targets[i].dist = abs(targets[i].pos - x);
    }
    quickSort(targets, 0, n - 1);
    for (int i = 0; i < k; i++) printf("%d ", targets[i].pos);
}