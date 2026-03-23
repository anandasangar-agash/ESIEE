#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
void print_board(Board grid);
int solve_board(Board grid);
int count_solutions(Board grid);

#endif
