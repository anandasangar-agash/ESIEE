#include <stdio.h>
#include "sudoku.h"

void initialize_empty_board(Board grid) {
    int i, j;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            grid[i][j] = 0;
        }
    }
}

void print_board(Board grid) {
    int i, j;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}


int is_legal(Board grid, int row, int col, int val) {
    int i, j;
    int startRow, startCol;

    if (val < 1 || val > 9) {
        return 0;
    }

    
    for (i = 0; i < 9; i++) {
        if (grid[row][i] == val) {
            return 0;
        }
        if (grid[i][col] == val) {
            return 0;
        }
    }

    
    startRow = row - row % 3;
    startCol = col - col % 3;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

int is_full(Board grid) {
    int i, j;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}
