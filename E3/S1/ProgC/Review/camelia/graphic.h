#ifndef __GRAPHIC__
#define __GRAPHIC__

#include <MLV/MLV_all.h>
#include "sudoku.h"

void draw_base();
void print_numbers(Board B, InitialMask mask);
void draw_selection_dial(Board B, int row, int col);
int get_clicked_cell(int mouse_x, int mouse_y, int* row, int* col);
int get_selected_number(int mouse_x, int mouse_y);
void redraw_grid(Board B, InitialMask mask);

#endif
