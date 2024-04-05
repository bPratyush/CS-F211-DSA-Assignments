#include <stdio.h>
#include <string.h>

#define MAXN 100005
#define MAXL 105
#define MAXD 16

char arr[MAXN][MAXL];
char temp[MAXN][MAXL];
char *buckets[MAXD][MAXN];
int bucket_sizes[MAXD];

char get_digit(char *num, int k) {
    int len = strlen(num);
    return len >= k ? num[len - k] : '0';
}

int char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

void counting_sort(int n, int k) {
    for (int i = 0; i < MAXD; i++) bucket_sizes[i] = 0;
    for (int i = 0; i < n; i++) {
        int digit = char_to_int(get_digit(arr[i], k));
        buckets[digit][bucket_sizes[digit]++] = arr[i];
    }
    int index = 0;
    for (int i = 0; i < MAXD; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            strcpy(temp[index++], buckets[i][j]);
        }
    }
    for (int i = 0; i < n; i++) strcpy(arr[i], temp[i]);
}

void radix_sort(int n, int k) {
    for (int i = 1; i <= k; i++) counting_sort(n, i);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    radix_sort(n, k);
    for (int i = 0; i < n; i++) printf("%s ", arr[i]);
}