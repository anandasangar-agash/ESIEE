#include <stdio.h>
#include <MLV/MLV_all.h>

#include "sudoku.h"

int find_empty_cell(Board g, int* row, int* col) {
    int i;
    int j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (g[i][j] == 0) {
                *row = i;
                *col = j;
                return 1; /*une case vide*/
            }
        }
    }
    return 0; /*aucune case vide*/
}

int can_place(Board g, int row, int col, int val) {
    int i; 
    int r; 
    int c;

    for (i = 0; i < 9; i++) {
        if (g[row][i] == val) return 0; /*Verif la ligne*/
    }

    for (i = 0; i < 9; i++) {
        if (g[i][col] == val) return 0; /*Verif la colonne*/
    }

    int start_row = (row / 3) * 3; /*Verif du carré en 3*3*/
    int start_col = (col / 3) * 3;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            if (g[start_row + r][start_col + c] == val) return 0;
        }
    }

    return 1;
}

int is_grid_complete(Board g) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (g[i][j] == 0) {
                return 0;  /* Il reste des cases vides */
            }
        }
    }
    return 1;  /* Toutes les cases sont remplies */
}

void create_initial_mask(Board b, InitialMask mask) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (b[i][j] != 0) {
                mask[i][j] = 1;  /* Case initiale */
            } else {
                mask[i][j] = 0;  /* Case vide */
            }
        }
    }
}

/*grid[row][col] = valeur; -> important*/