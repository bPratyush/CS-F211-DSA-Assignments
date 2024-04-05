#include <stdio.h>
#include <stdbool.h>
#define SIZE 9
//Backtracking
bool isValid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool solve(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                for (int num = 1; num <= SIZE; num++) {
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (solve(board)) return true;
                        board[i][j] = -1; //Backtracking Step
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (solve(board)) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else printf("-1");
}