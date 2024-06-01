#include <stdio.h>

int main() {
    char a[1001];
    char b[1001];
    int carry = 0;
    
    scanf("%s", a);
    scanf("%s", b);

    int x[1001]={0};
    int y[1001]={0};

    int sum;
    int arr[1002];
    int len_a = 0;
    int len_b = 0;
    
    while (a[len_a] != '\0') len_a++;
    while (b[len_b] != '\0') len_b++;
    for (int i = 0; i < len_a; i++) x[i] = a[len_a - 1 - i] - '0';
    for (int i = 0; i < len_b; i++) y[i] = b[len_b - 1 - i] - '0';
    // Perform addition
    for (int i = 0; i < 1001; i++) {
        sum = x[i] + y[i] + carry;
        if (sum >= 10) {
            carry = 1;
            int ones = sum % 10;
            arr[i] = ones;
        } else {
            carry = 0;
            arr[i] = sum;
        }
    }
    // Print the result
    int startPrinting = 0;
    for (int i = 1000; i >= 0; i--) {
        if (arr[i]) startPrinting = 1;
        if (startPrinting) printf("%d", arr[i]);
    }
    // If the result is zero, print 0
    if (!startPrinting) printf("0");
    return 0;
}