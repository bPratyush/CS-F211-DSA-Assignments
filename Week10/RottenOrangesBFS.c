#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int rows, cols;
int count = 0;

// Structure to represent a cell in the grid
typedef struct {
    int x;
    int y;
} Cell;

// Function to check if the cell is within the grid and has a fresh orange
bool isSafe(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1);
}

// Function to perform BFS traversal
void bfs(int x, int y) {
    // Arrays for horizontal and vertical movements
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Queue for BFS traversal
    Cell queue[MAX_SIZE * MAX_SIZE];
    int front = 0, rear = 0;

    // Enqueue the starting cell
    queue[rear++] = (Cell){x, y};
    visited[x][y] = 0; // Mark as visited

    // Perform BFS
    while (front < rear) {
        Cell current = queue[front++];

        // Increment the count for each visited cell
        count++;

        // Explore adjacent cells
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // Check if the adjacent cell is safe and not visited
            if (isSafe(nx, ny) && visited[nx][ny] == -1) {
                // Enqueue the adjacent cell
                queue[rear++] = (Cell){nx, ny};
                visited[nx][ny] = visited[current.x][current.y] + 1; // Mark as visited and update time
            }
        }
    }
}

int main() {
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the grid (0 for empty cell, 1 for fresh orange): \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
            visited[i][j] = -1; // Initialize visited array with -1
        }
    }

    // Perform BFS from each rotten orange
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                bfs(i, j);
            }
        }
    }
}
