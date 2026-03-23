#ifndef SUDOKU_H
#define SUDOKU_H

int is_valid_placement(int grid[9][9], int row, int col, int num);
int solve_sudoku(int grid[9][9]);
int sudoku_is_complete(int grid[9][9]);
void copy_grid(int source[9][9], int dest[9][9]);
void give_hint(int grid[9][9], int initial_grid[9][9]);
int is_sudoku_valid(int grid[9][9]);

#endif
