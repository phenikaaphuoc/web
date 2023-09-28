#include <stdio.h>
#define ROWS 5
#define COLS 5

// Hàm kiểm tra xem ô (x, y) có hợp lệ hay không
int isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Hàm thực hiện thuật toán FJS
void FJS(int grid[ROWS][COLS], int visited[ROWS][COLS], int x, int y) {
    if (!isValid(x, y) || visited[x][y] == 1 || grid[x][y] == 0) {
        return;
    }

    visited[x][y] = 1;
    printf("(%d, %d)\n", x, y);

    // Các hướng (trên, phải, dưới, trái)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        FJS(grid, visited, x + dx[i], y + dy[i]);
    }
}

int main() {
    int grid[ROWS][COLS] = {
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int visited[ROWS][COLS] = {0};

    printf("Các ô có thể đến được:\n");
    FJS(grid, visited, 0, 0);

    return 0;
}
