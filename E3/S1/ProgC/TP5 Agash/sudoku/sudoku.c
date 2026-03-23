#include <stdio.h>

#include "sudoku.h"

#include <stdio.h>
#include "sudoku.h"

/* ------------------------------------------------------- */
/* Initialise une grille vide (toutes cases = 0)           */
/* ------------------------------------------------------- */
void initialize_empty_board(Board board) {
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            board[i][j] = 0;
}

/* ------------------------------------------------------- */
/* Affiche la grille de Sudoku                             */
/* ------------------------------------------------------- */
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
/* ------------------------------------------------------- */
/* Trouve la première case vide (0)                        */
/* Retourne 1 si une case vide existe, sinon 0             */
/* ------------------------------------------------------- */
int find_empty(Board board, int *row, int *col) {
    int i,j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

/* ------------------------------------------------------- */
/* Vérifie si val peut être placée dans (row, col)         */
/* ------------------------------------------------------- */
int is_valid(Board board, int row, int col, int val) {
    int i,j;
   
    for (j = 0; j < 9; j++)
        if (board[row][j] == val)
            return 0;


    for (i = 0; i < 9; i++)
        if (board[i][col] == val)
            return 0;

    int box_r = (row / 3) * 3;
    int box_c = (col / 3) * 3;

    for (i = box_r; i < box_r + 3; i++)
        for (j = box_c; j < box_c + 3; j++)
            if (board[i][j] == val)
                return 0;

    return 1; 
}

/* ------------------------------------------------------- */
/* Solver Sudoku récursif (backtracking)                   */
/* ------------------------------------------------------- */
int solve_board(Board board) {

    int row, col;

    if (!find_empty(board, &row, &col)) {
        print_board(board);
        return 1;
    }

    int val;

    for (val = 1; val <= 9; val++) {

        if (is_valid(board, row, col, val)) {
            board[row][col] = val;   

            if (solve_board(board))  
                return 1;

            board[row][col] = 0;    
        }
    }

    return 0;
}

int count_solutions(Board board) {
    int row, col;

    if (!find_empty(board, &row, &col)) {
        return 1;
    }

    int total = 0;
    int val;

    for (val = 1; val <= 9; val++) {
        if (is_valid(board, row, col, val)) {
            board[row][col] = val;

            total += count_solutions(board);

            board[row][col] = 0; 
        }
    }

    return total;
}

