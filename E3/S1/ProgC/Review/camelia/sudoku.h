#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];
typedef int InitialMask[9][9];

void create_initial_mask(Board b, InitialMask mask);
int can_place(Board g, int row, int col, int val);
int find_empty_cell(Board g, int* row, int* col);
int is_grid_complete(Board g);

#endif
