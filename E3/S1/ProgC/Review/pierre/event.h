#ifndef EVENT_H
#define EVENT_H

void handle_event(int x, int y, int grid[9][9], int initial_grid[9][9],
                   int *selected_row, int *selected_col,
                   int grid_x, int grid_y, int grid_size,
                   int palette_x, int palette_width, int cell_size, int palette_cell_size,
                   int panel_height, int window_width, int margin);

void handle_mouse_click(int x, int y, int grid[9][9], int initial_grid[9][9],
                        int *selected_row, int *selected_col,
                        int grid_x, int grid_y, int grid_size,
                        int palette_x, int palette_width, int cell_size, int palette_cell_size,
                        int panel_height, int window_width, int margin);

#endif
