#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    char str[num + 1];
    scanf(" %[^\n]", str);
    int start = 0;
    for (int i = 0; i <= num; i++){
        if (str[i] == ' ' || str[i] == '\0'){
            int end = i - 1;
            while (start <= end){
                char temp = str[start];
                str[start++] = str[end];
                str[end--] = temp;
            }
            start = i + 1;
        }
    }
    printf("%s\n", str);
}