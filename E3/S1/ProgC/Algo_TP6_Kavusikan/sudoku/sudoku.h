#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);

void print_board(Board grid);

int is_legal(Board grid, int row, int col, int val);


int is_full(Board grid);

#endif

