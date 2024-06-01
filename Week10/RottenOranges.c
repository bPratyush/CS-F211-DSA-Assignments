#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int rows, cols;
int count = 0;

// Function to check if the cell is within the grid and has a fresh orange
bool isSafe(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1);
}

// DFS function to rot oranges and count the time taken for rotting
void dfs(int x, int y, int time) {
    if (!isSafe(x, y) || visited[x][y] <= time) return;
    visited[x][y] = time;
    count++;
    dfs(x + 1, y, time + 1);
    dfs(x - 1, y, time + 1);
    dfs(x, y + 1, time + 1);
    dfs(x, y - 1, time + 1);
}

int main() {
    scanf("%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
            visited[i][j] = MAX_SIZE * MAX_SIZE;
        }
    }
    // Perform DFS from each rotten orange
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                dfs(i, j, 0);
            }
        }
    }
    // Check if any fresh oranges remain
    bool freshExists = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1 && visited[i][j] == MAX_SIZE * MAX_SIZE) {
                freshExists = true;
                break;
            }
        }
    }
    if (freshExists) printf("-1");
    else printf("%d\n", count);
}
