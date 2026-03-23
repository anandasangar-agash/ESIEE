#ifndef __GRAPHIC__
#define __GRAPHIC__

#include "sudoku.h"
#include <MLV/MLV_all.h>

#define WIN_W 1200
#define WIN_H 800

#define GRID_SIZE 9
#define CELL 60
#define GRID_X 100
#define GRID_Y 100

#define PICKER_SIZE 3
#define PICKER_CELL 60
#define PICKER_X (GRID_X + GRID_SIZE * CELL + 100)
#define PICKER_Y (GRID_Y + 3 * CELL)

void clear_screen();
void draw_grid();
void draw_numbers(Board grid);
void draw_picker();
void draw_board(Board grid, int sel_row, int sel_col);
int mouse_to_cell(int mx, int my, int* row, int* col);
int mouse_to_picker(int mx, int my);

#endif
