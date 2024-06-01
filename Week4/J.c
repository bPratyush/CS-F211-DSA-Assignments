#include <stdio.h>

void processBoard(int n, int m, char board[n][m+1]) {
    for(int j = 0; j < m; j++) {
        int fall = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(board[i][j] == '*') {
                board[i][j] = '.';
                board[fall--][j] = '*';
            }
            else if(board[i][j] == 'o') fall = i-1;
        }
    }
    for(int i = 0; i < n; i++) printf("%s\n", board[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char board[n][m+1]; //+1 for NULL character
    for(int i = 0; i < n; i++) scanf("%s", board[i]);
    processBoard(n, m, board);
}

