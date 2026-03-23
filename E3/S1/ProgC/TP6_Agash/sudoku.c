#include <stdio.h>

#include "sudoku.h"


void initialize_empty_board(Board board) {
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            board[i][j] = 0;
}


void print_board(Board board) {

    printf("-------------------------------------\n");

    int i,j;
    for (i = 0 ; i < 9 ; i++) {
        printf("| ");

        for (j = 0 ; j < 9 ; j++) {

            if (board[i][j] == 0)
                printf(" ");    
            else
                printf("%d", board[i][j]);

            printf(" | ");         
        }

        printf("\n");
        printf("-------------------------------------\n");
    }
}


int is_valid(Board board, int row, int col, int val) {
    int i, j;
    int startRow, startCol;

    if (val < 1 || val > 9) {
        return 0;
    }

    for (i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return 0;
        }
        if (board[i][col] == val) {
            return 0;
        }
    }

    startRow = row - row % 3;
    startCol = col - col % 3;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

int is_full(Board board) {
    int i, j;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}
