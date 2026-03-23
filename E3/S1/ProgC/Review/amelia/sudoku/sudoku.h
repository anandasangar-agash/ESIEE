#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
void print_board(Board grid);
int solve(Board grid);
void count_solutions(Board grid, int *count);
int is_legal(Board B, int row, int col, int val);
int board_is_full(Board B);
int check_row(Board B, int row, int val);
int check_col(Board B, int col, int val);
int check_block(Board B, int row, int col, int val);

#endif
