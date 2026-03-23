#ifndef INTERFACE_H
#define INTERFACE_H
#include "sudoku.h"
#include <MLV/MLV_all.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

#define GRID_SIZE 9
#define GRID_PIXEL_SIZE 600
#define GRID_ORIGIN_X 50
#define GRID_ORIGIN_Y 50
#define CELL_SIZE (GRID_PIXEL_SIZE / GRID_SIZE)

#define PAD_ORIGIN_X (GRID_ORIGIN_X + GRID_PIXEL_SIZE + 50)
#define PAD_ORIGIN_Y GRID_ORIGIN_Y

/* Gestion de la fenêtre */
void init_window(void);
void close_window(void);

/* Dessin */
void draw_cell_value(int row, int col, int value);
void draw_grid(Board grid, int sel_row, int sel_col);

/* Gestion souris */
int mouse_to_cell(int x, int y, int *row, int *col);
int wait_click_on_empty_cell(Board B, int *row, int *col);
int show_number_pad_and_get_choice(int sel_row, int sel_col);

#endif